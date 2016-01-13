//Definitions
#define _USE_MATH_DEFINES
//Windows Libaries
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <iostream>
#include <sstream>
//OpenCV Libaries
#include "opencv2/core/core.hpp"
#include "opencv/cv.h"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include <opencv2/video/background_segm.hpp>
//Self-Defined Libaries

using namespace cv;
using namespace std;

class THDUtil{
public:
	static Mat sharpen(Mat img);
	static Mat computeOrientation(Mat frame);
	static Vec4i averageLanes(vector<Vec4i> lanes);
	static vector<Point> circleDetector(Mat& imgThresholded, Mat& scene, int cannyThreshold, int accumulatorThreshold, int minSize, int maxSize);
	static bool inVicinity(Point pt1, Point pt2, double threshhold);
	static Point colorDetector(Mat& scene, Mat& imgThresholded, Scalar lowerHSV, Scalar upperHSV);
	static wstring String2wString(const string& s);
};