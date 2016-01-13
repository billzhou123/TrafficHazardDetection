#include "MainProcessingThread.h"
#include "LaneDetectionThread.h"
#include "GlobalSettings.h"


MainProcessingThread::MainProcessingThread()
{

}

void MainProcessingThread::process(){
	Mat scene;
	//Speed Callibration Variables
	int referenceFrameCoolDown = 0;
	int sampleFrameCoolDown = 15;
	Mat referenceFrame, sampleFrame;
	//QImage* LiveFeedFrame = NULL;


	//WaitForSingleObject(semaphore_startVideo, INFINITE);
	VideoCapture cap(globalVideoLocation);
		if (!cap.isOpened()){  // success, continue;
			return;
		}

	while (1){
		if (globalStop) //Ends the loop
			break;
		WaitForSingleObject(semaphore_mainProcessing, INFINITE);

		bool bSuccess = cap.read(scene); // read a new frame from video
		if (!bSuccess){ //if not success, break loop
			ReleaseSemaphore(semaphore_mainProcessing, 1, NULL); //return the key for next video
			break;
		}
		QImage LiveFeedFrame = MatToQImage(scene);
		emit sendLiveFeedFrame(LiveFeedFrame);
		//MatToQImage(scene, &LiveFeedFrame);
		//emit sendLiveFeedFrame(*LiveFeedFrame);
		//delete LiveFeedFrame;
		//LiveFeedFrame = NULL;

		Rect myROI(67, 120, 720, 240);
		scene = scene(myROI);
		Mat gframe = scene.clone();
		emit sendDetectionFeedFrame(scene);

		if (sampleFrameCoolDown == 0){
			sampleFrame = scene.clone();
			Rect speedROI(556, 0, 52, 238);
			sampleFrame = sampleFrame(speedROI);
			mutex_globalSampleImage.lock();
			globalSampleImage = sampleFrame;
			mutex_globalSampleImage.unlock();
			sampleFrameCoolDown = 15;
			ReleaseSemaphore(semaphore_speedCallibration, 1, NULL);
		}
		else{
			sampleFrameCoolDown--;
		}
		
		if (referenceFrameCoolDown == 0){
			referenceFrame = scene.clone();
			Rect speedROI(556, 0, 52, 238);
			referenceFrame = referenceFrame(speedROI);
			mutex_globalReferenceImage.lock();
			globalRefererenceImage = referenceFrame;
			mutex_globalReferenceImage.unlock();
			referenceFrameCoolDown = 15;
		}
		else{
			referenceFrameCoolDown--;
		}

		//Send the shared frame
		mutex_globalFrame.lock();
		globalFrame = gframe;
		mutex_globalFrame.unlock();

		//Send the time elapsed of video
		double msec = cap.get(CV_CAP_PROP_POS_MSEC);
		double sec = msec / 1000;
		mutex_globalTimeElapsed.lock();
		globalTimeElapsed = sec;
		mutex_globalTimeElapsed.unlock();

		framesprocessed++;

		mutex_globalSleepTime.lock();
		sleepTime = globalSleepTime;
		mutex_globalSleepTime.unlock();
		Sleep(sleepTime);

		ReleaseSemaphore(semaphore_mainProcessing, 1, NULL);
	}
	//ReleaseSemaphore(semaphore_startVideo, 1, NULL);
}