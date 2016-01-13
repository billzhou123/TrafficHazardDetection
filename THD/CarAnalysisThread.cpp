#include "CarAnalysisThread.h"
#include "GlobalSettings.h"
#include "THDUtil.h"


CarAnalysisThread::CarAnalysisThread()
{

}


void CarAnalysisThread::process()
{
	DWORD dwWaitResult;
	deque<Point> recentturnlights;
	while (1)
	{
		if (globalStop)
			break;
		dwWaitResult = WaitForSingleObject(semaphore_carAnalysis,INFINITE);
		//Get the frame needed
		Mat carFrame;
		mutex_globalCarFrame1.lock();
		if (globalCarFrame1.empty()){
			mutex_globalCarFrame1.unlock();
			continue;
		}
		carFrame = globalCarFrame1;
		mutex_globalCarFrame1.unlock();

		/***
		//Setting Up Image Color
		Mat channel[3], imgHSV, thresh;
		cvtColor(carFrame, imgHSV, COLOR_BGR2HSV);
		split(imgHSV, channel);  // planes[2] is the red channel
		channel[0] = Mat::zeros(carFrame.rows, carFrame.cols, CV_8UC1); //Set blue channel to 0
		Mat targetcar = channel[1].clone();
		inRange(targetcar, 94, 173, thresh); //lower and upper ranges (84 and 115) for turn light detection

		//Get the circles for the turnlights
		Mat cannyImg;
		vector<Point> turnlightlocation;
		std::deque<int> turnlightlocationsize;
		Canny(thresh, cannyImg, 30, 30 * 3, 3);
		turnlightlocation = THDUtil::circleDetector(cannyImg, targetcar, 30, 10, 0, 4);
		for (int i = 0; i < turnlightlocation.size(); i++){ //Copy possible turn light into recentCircles
			circle(carFrame, turnlightlocation[i], 3, Scalar(0, 0, 255), 1, CV_AA, 0);
			Point lightpoint = turnlightlocation[i];
			if (lightpoint.y>(targetcar.rows / 8) * 3 && lightpoint.y < (targetcar.rows / 8) * 5){
				if (lightpoint.x < targetcar.cols / 2){ //Left Signal
					circle(carFrame, lightpoint, 3, Scalar(0, 255, 0), 1, CV_AA, 0);
					//Sleep(2000);
				}
				else{ //Left Signal
					circle(carFrame, lightpoint, 3, Scalar(0, 255, 0), 1, CV_AA, 0);
					//Sleep(2000);
				}
			}
		}
		**/

		emit sendCarAnalysisFrame(carFrame);
		Sleep(100);
	}
	return;
}