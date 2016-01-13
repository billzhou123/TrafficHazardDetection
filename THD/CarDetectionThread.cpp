#include "CarDetectionThread.h"
#include "GlobalSettings.h"
#include "THDUtil.h"


CarDetectionThread::CarDetectionThread()
{

}


void CarDetectionThread::process()
{
	while (1)
	{
		if (globalStop)
			break;
		vector<Rect> cars, approxCars, detectedCars;
		Mat carImage, largeImg;

		mutex_globalFrame.lock();
		if (globalFrame.empty()){
			mutex_globalFrame.unlock();
			continue;
		}
		carImage = globalFrame;
		largeImg = globalFrame;
		mutex_globalFrame.unlock();

		Rect halfSizeROI(181, 28, 381, 174);
		carImage = carImage(halfSizeROI);
		cvtColor(carImage, carImage, CV_RGB2GRAY);
		Mat medImg = carImage; //keeping medium image reference
		pyrDown(carImage, carImage, Size(carImage.cols / 2, carImage.rows / 2));
		equalizeHist(carImage, carImage);

		//emit sendCarImage(carImage);

		cascade.detectMultiScale(carImage, cars, 1.1, 3, 0 | CV_HAAR_DO_CANNY_PRUNING);

		for (int i = 0; i < cars.size(); i++)
		{
			cars[i].x = 2 * cars[i].x + 181;
			cars[i].y = 2 * cars[i].y + 28;
			cars[i].width = 2 * cars[i].width;
			cars[i].height = 2 * cars[i].height;
			approxCars.push_back(cars[i]);
			int centerX = cars[i].width / 2 + cars[i].x;
			int centerY = cars[i].height / 2 + cars[i].y;
			if (centerX > 220 && centerX < 480)
			{
				if (centerY > 82 && centerY < 186)
				{
					if (cars[i].area() < 8100){
						detectedCars.push_back(cars[i]);
					}
				}
			}
		}
		mutex_globalApproxCars.lock();
		globalApproxCars = approxCars;
		mutex_globalApproxCars.unlock();

		mutex_globalDetectedCars.lock();
		globalDetectedCars = detectedCars;
		mutex_globalDetectedCars.unlock();

		Mat car1, car2;
		for (int i = 0; i < detectedCars.size(); i++){ //Take out the first two cars
			if (i == 0)
				car1 = largeImg(detectedCars[0]);
			else if (i == 2)
				car2 = largeImg(detectedCars[1]);
			else
				break;
		}
		
		mutex_globalCarFrame1.lock();
		globalCarFrame1 = car1;
		mutex_globalCarFrame1.unlock();
		
		mutex_globalCarFrame2.lock();
		globalCarFrame2 = car2;
		mutex_globalCarFrame2.unlock();
		ReleaseSemaphore(semaphore_carAnalysis, 1, NULL);

		/***
		string msg = std::to_string(detectedCars.size()) + " Cars Detected";
		mutex_consoleMessage.lock();
		consoleMessage = msg;
		mutex_consoleMessage.unlock();
		***/
		Sleep(400);
	}
}