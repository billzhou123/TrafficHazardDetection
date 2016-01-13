#include "PedestrianThread.h"
#include "GlobalSettings.h"
#include "THDUtil.h"


PedestrianThread::PedestrianThread()
{

}


void PedestrianThread::process()
{
	while (1)
	{
		if (globalStop)
			break;
		Mat blindspotright;
		vector<Rect> found, found_filtered;
		HOGDescriptor hog;
		hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

		//Gets the global frame
		mutex_globalFrame.lock();
		if (globalFrame.empty()){
			mutex_globalFrame.unlock();
			continue;
		}
		blindspotright = globalFrame;
		mutex_globalFrame.unlock();

		//Dimensional Transformation
		Rect rightROI(397, 108, 49, 78);
		blindspotright = blindspotright(rightROI);

		//Image Transformation
		cvtColor(blindspotright, blindspotright, CV_RGB2GRAY);
		pyrUp(blindspotright, blindspotright, Size(blindspotright.cols * 2, blindspotright.rows * 2));

		hog.detectMultiScale(blindspotright, found, 0, Size(4, 4), Size(16, 16), 0, 2);

		size_t i, j;
		for (i = 0; i < found.size(); i++){
			Rect r = found[i];
			for (j = 0; j < found.size(); j++)
			if (j != i && (r & found[j]) == r)
				break;
			if (j == found.size()){
				found_filtered.push_back(r);
			}
		}

		int flag = 0;
		for (i = 0; i < found_filtered.size(); i++){
			Rect r = found_filtered[i];
			r.x += cvRound(r.width*0.1);
			r.width = cvRound(r.width*0.8);
			r.y += cvRound(r.height*0.06);
			r.height = cvRound(r.height*0.9);

			// Correct Display Position
			r.x = r.x / 2 + 397;
			r.y = r.y / 2 + 108;
			r.width = r.width / 2;
			r.height = r.height / 2;

			mutex_globalDetectedPedestrian.lock();
			globalDetectedPedestrian = r;
			mutex_globalDetectedPedestrian.unlock();
			flag = 1;
			//rectangle(scene, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
		}
		if (flag == 0)
		{
			Rect r;
			r.x = 0;
			mutex_globalDetectedPedestrian.lock();
			globalDetectedPedestrian = r;
			mutex_globalDetectedPedestrian.unlock();
		}
		Sleep(250);
	}

}