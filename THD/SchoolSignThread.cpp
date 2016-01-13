#include "SchoolSignThread.h"
#include "GlobalSettings.h"
#include "THDUtil.h"

SchoolSignThread::SchoolSignThread()
{

}

void SchoolSignThread::process()
{
	while (1)
	{
		if (globalStop)
			break;
		Mat signImg;
		vector<Vec3f> circles;

		mutex_globalFrame.lock();
		if (globalFrame.empty()){
			mutex_globalFrame.unlock();
			continue;
		}
		signImg = globalFrame;
		mutex_globalFrame.unlock();

		//Dimensional Transform
		Rect signROI(361, 0, 266, 150);
		signImg = signImg(signROI);

		//Image Transform
		Mat yellowThresh,canny;
		THDUtil::colorDetector(signImg, yellowThresh, Scalar(26, 108, 71), Scalar(46, 255, 255));
		pyrDown(yellowThresh, canny, Size(yellowThresh.cols / 2, yellowThresh.rows / 2));
		Canny(canny, canny, 30, 30 * 3, 3);

		//GaussianBlur(redThresh, redThresh, Size(3, 3), 2, 2);
		HoughCircles(canny, circles, CV_HOUGH_GRADIENT, 1, yellowThresh.rows / 8, 20, 9, 1, 10);

		int flag = 0;
		for (size_t i = 0; i < circles.size(); i++)
		{
			Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
			center.x = 2 * center.x + 361;
			center.y = 2 * center.y;

			int radius = cvRound(circles[i][2]) * 2;
			// circle outline
			mutex_globalApproxSchoolSigns.lock();
			globalApproxSchoolSigns = circles;
			mutex_globalApproxSchoolSigns.unlock();
			flag = 1;

			if (THDUtil::inVicinity(center, Point(434, 91), 5)){
				mutex_globalDetectedSchoolSign.lock();
				globalDetectedSchoolSign = circles[i];
				mutex_globalDetectedSchoolSign.unlock();
			}
			else if (THDUtil::inVicinity(center, Point(423, 73), 5)) {
				mutex_globalDetectedSchoolSign.lock();
				globalDetectedSchoolSign = circles[i];
				mutex_globalDetectedSchoolSign.unlock();
			}
			else if (THDUtil::inVicinity(center, Point(494, 55), 5)){
				mutex_globalDetectedSchoolSign.lock();
				globalDetectedSchoolSign = circles[i];
				mutex_globalDetectedSchoolSign.unlock();
			}
			else if (THDUtil::inVicinity(center, Point(444, 95), 5)){
				mutex_globalDetectedSchoolSign.lock();
				globalDetectedSchoolSign = circles[i];
				mutex_globalDetectedSchoolSign.unlock();
			}
			else if (THDUtil::inVicinity(center, Point(553, 36), 5)){
				mutex_globalDetectedSchoolSign.lock();
				globalDetectedSchoolSign = circles[i];
				mutex_globalDetectedSchoolSign.unlock();
			}
			else if (THDUtil::inVicinity(center, Point(417, 117), 5)){
				mutex_globalDetectedSchoolSign.lock();
				globalDetectedSchoolSign = circles[i];
				mutex_globalDetectedSchoolSign.unlock();
			}
			else if (THDUtil::inVicinity(center, Point(430, 115), 5)){
				mutex_globalDetectedSchoolSign.lock();
				globalDetectedSchoolSign = circles[i];
				mutex_globalDetectedSchoolSign.unlock();
			}
			else if (THDUtil::inVicinity(center, Point(461, 138), 5)){
				mutex_globalDetectedSchoolSign.lock();
				globalDetectedSchoolSign = circles[i];
				mutex_globalDetectedSchoolSign.unlock();
			}
			else if (THDUtil::inVicinity(center, Point(449, 114), 5)){
				mutex_globalDetectedSchoolSign.lock();
				globalDetectedSchoolSign = circles[i];
				mutex_globalDetectedSchoolSign.unlock();
			}
			else if (THDUtil::inVicinity(center, Point(491, 122), 5)){
				mutex_globalDetectedSchoolSign.lock();
				globalDetectedSchoolSign = circles[i];
				mutex_globalDetectedSchoolSign.unlock();
			}
			else if (THDUtil::inVicinity(center, Point(478, 139), 5)){
				mutex_globalDetectedSchoolSign.lock();
				globalDetectedSchoolSign = circles[i];
				mutex_globalDetectedSchoolSign.unlock();
			}
			else{
				Vec3f empty;
				empty[0] = 0;
				mutex_globalDetectedSchoolSign.lock();
				globalDetectedSchoolSign = empty;
				mutex_globalDetectedSchoolSign.unlock();
			}
		}
		
		if (flag == 0)
		{
			mutex_globalApproxSchoolSigns.lock();
			globalApproxSchoolSigns.clear();
			mutex_globalApproxSchoolSigns.unlock();
		}
		
		
	}
	return;
}