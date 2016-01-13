#include "LiveFeedThread.h"

LiveFeedThread::LiveFeedThread(){

}

void LiveFeedThread::process(){
	Mat scene;
	VideoCapture cap(globalVideoLocation);
	if (!cap.isOpened()){  // if not success, exit program
		return;
	}


	while (1){
		if (globalStop)
			break;
		bool bSuccess = cap.read(scene); // read a new frame from video
		if (!bSuccess){ //if not success, break loop
			break;
		}
		//QImage* frame = NULL;
		//MatToQImage(scene,&frame);
		//emit newFrame(*frame);
		//delete frame;
		//Sleep(10);
	}
}