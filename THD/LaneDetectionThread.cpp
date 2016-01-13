#include "LaneDetectionThread.h"
#include "GlobalSettings.h"
#include "THDUtil.h"


LaneDetectionThread::LaneDetectionThread()
{

}


void LaneDetectionThread::process()
{

	while (1)
	{
		if (globalStop)
			break;
		Mat laneImage;
		vector<Vec4i> lines, rightlanes, leftlanes;
		
		//Gets the global frame
		mutex_globalFrame.lock();
		if (globalFrame.empty()){
			mutex_globalFrame.unlock();
			continue;
		}
		cvtColor(globalFrame, laneImage, CV_RGB2GRAY);
		mutex_globalFrame.unlock();

		//Dimension Transformations
		Rect halfSizeROI(laneImage.cols / 4, 135, laneImage.cols - laneImage.cols / 2, laneImage.rows - 135);
		laneImage = laneImage(halfSizeROI);
		Mat medImg = laneImage; //keeping medium image reference
		pyrDown(laneImage, laneImage, Size(laneImage.cols / 2, laneImage.rows / 2));

		//Image Transformations
		equalizeHist(laneImage, laneImage);
		blur(laneImage, laneImage, Size(3, 3));
		Canny(laneImage, laneImage, 30, 30 * 3, 3);
		
		emit sendCannyImage(laneImage);

		//Compute Lines
		HoughLinesP(laneImage, lines, 1, CV_PI / 180, 30, 1, 500);
		
		vector<Vec4i> approxLanes;
		for (size_t i = 0; i < lines.size(); i++) //Filter candidates
		{
			Vec4i l = lines[i];
			double dx = l[2] - l[0]; //x2-x1
			double dy = l[3] - l[1]; //y2-y1
			if (dy == 0)
				continue;
			double slope = dy / dx;
			if (l[0]<73){ //lane on left side
				if (slope < -0.5 && slope > -10){
					leftlanes.push_back(l);
					l[0] += l[0] + medImg.cols / 2;
					l[1] += l[1] + 135;
					l[2] += l[2] + medImg.cols / 2;
					l[3] += l[3] + 135;
					approxLanes.push_back(l);
					//line(scene, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, CV_AA);
				}
			}
			else{ //lane on right side
				if (slope > 0.5 && slope < 10){
					rightlanes.push_back(l);
					l[0] += l[0] + medImg.cols / 2;
					l[1] += l[1] + 135;
					l[2] += l[2] + medImg.cols / 2;
					l[3] += l[3] + 135;
					approxLanes.push_back(l);
					//line(scene, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, CV_AA);
				}
			}
		}

		vector<Vec4i> detectedLanes;
		Vec4i avgRightLane, avgLeftLane;
		if (rightlanes.size() != 0){
			avgRightLane = THDUtil::averageLanes(rightlanes);
			if (sqrt((avgRightLane[2] - avgRightLane[0])*(avgRightLane[2] - avgRightLane[0])
				+ (avgRightLane[3] - avgRightLane[1])*(avgRightLane[3] - avgRightLane[1])) > 120){
				avgRightLane[0] += medImg.cols / 2;
				avgRightLane[1] += 135;
				avgRightLane[2] += medImg.cols / 2;
				avgRightLane[3] += 135;
				mutex_globalDetectedRightLane.lock();
				globalDetectedRightLane = avgRightLane;
				mutex_globalDetectedRightLane.unlock();
				//line(scene, Point(avgRightLane[0], avgRightLane[1]), Point(avgRightLane[2], avgRightLane[3]), Scalar(0, 255, 0), 3, CV_AA);
			}
		}

		if (leftlanes.size() != 0){
			avgLeftLane = THDUtil::averageLanes(leftlanes);
			if (sqrt((avgLeftLane[2] - avgLeftLane[0])*(avgLeftLane[2] - avgLeftLane[0])
				+ (avgLeftLane[3] - avgLeftLane[1])*(avgLeftLane[3] - avgLeftLane[1])) > 120){
				avgLeftLane[0] += medImg.cols / 2;
				avgLeftLane[1] += 135;
				avgLeftLane[2] += medImg.cols / 2;
				avgLeftLane[3] += 135;
				mutex_globalDetectedLeftLane.lock();
				globalDetectedLeftLane = avgLeftLane;
				mutex_globalDetectedLeftLane.unlock();
				//line(scene, Point(avgLeftLane[0], avgLeftLane[1]), Point(avgLeftLane[2], avgLeftLane[3]), Scalar(0, 255, 0), 3, CV_AA);
			}
		}

		//writing in new approximated lanes
		mutex_globalApproxLanes.lock();
		globalApproxLanes.clear();
		globalApproxLanes = approxLanes;
		mutex_globalApproxLanes.unlock();

		Sleep(200);
	}
}