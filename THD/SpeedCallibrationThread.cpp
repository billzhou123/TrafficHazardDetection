#include "SpeedCallibrationThread.h"
#include "GlobalSettings.h"
#include "THDUtil.h"

SpeedCallibrationThread::SpeedCallibrationThread()
{

}

void SpeedCallibrationThread::process()
{
	
	
	while (1)
	{
		if (globalStop)
			break;
		Mat referenceFrame, sampleFrame;
		WaitForSingleObject(semaphore_carAnalysis, INFINITE);

		//Load the reference image
		mutex_globalReferenceImage.lock();
		referenceFrame = globalRefererenceImage;
		mutex_globalReferenceImage.unlock();

		//Load the sample Image
		mutex_globalSampleImage.lock();
		sampleFrame = globalSampleImage;
		mutex_globalSampleImage.unlock();

		SurfFeatureDetector detector(600);

		vector<KeyPoint> keypoints_1, keypoints_2;

		detector.detect(referenceFrame, keypoints_1);
		detector.detect(sampleFrame, keypoints_2);

		//Calculate descriptors
		SurfDescriptorExtractor extractor;

		Mat descriptors_1, descriptors_2;

		extractor.compute(referenceFrame, keypoints_1, descriptors_1);
		extractor.compute(sampleFrame, keypoints_2, descriptors_2);

		//Matching descriptor vectors using FLANN matcher
		FlannBasedMatcher matcher;
		vector<DMatch> matches;
		if (descriptors_1.rows == 0 || descriptors_2.rows == 0) //
			continue;
		matcher.match(descriptors_1, descriptors_2, matches);

		//Quick calculation of max and min distances between keypoints
		double max_dist = 0; double min_dist = 100;
		for (int i = 0; i < descriptors_1.rows; i++){
			double dist = matches[i].distance;
			if (dist < min_dist) min_dist = dist;
			if (dist > max_dist) max_dist = dist;
		}

		//Draw only "good" matches (i.e. whose distance is less than 2*min_dist,
		//or a small arbitary value ( 0.02 ) in the event that min_dist is very small)
		vector<DMatch> good_matches;
		int horizontalSlopeMatches = 0;
		for (int i = 0; i < descriptors_1.rows; i++){
			if (matches[i].distance <= max(2 * min_dist, 0.02)){
				good_matches.push_back(matches[i]);
				Point2f point1 = keypoints_1[matches[i].queryIdx].pt;
				Point2f point2 = keypoints_2[matches[i].trainIdx].pt;
				double slope = (point2.y - point1.y) / (point2.x - point1.x);
				if (abs(slope) < 1)
					horizontalSlopeMatches++;
				keypoints_2[matches[i].trainIdx].pt.x += (556 - scene.cols / 2); //Correct the position
			}
		}
		double percentHorizontal = (double)horizontalSlopeMatches / good_matches.size();
		mutex_globalPercentHorizontal.lock();
		globalPercentHorizontal = percentHorizontal;
		mutex_globalPercentHorizontal.unlock();

		//-- Draw only "good" matches
		mutex_globalFrame.lock();
		scene = globalFrame;
		mutex_globalFrame.unlock();
		Mat img_matches;
		Mat halfScene;
		Rect halfsizeROI(scene.cols / 2, 0, scene.cols / 2, scene.rows);
		halfScene = scene(halfsizeROI);
		drawMatches(referenceFrame, keypoints_1, halfScene, keypoints_2,
			good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
			vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
		emit sendSpeedImage(img_matches);

	}
	return;
}