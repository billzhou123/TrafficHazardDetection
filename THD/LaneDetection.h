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

class LaneDetection{
public:
	LaneDetection();
	vector<Vec4i> laneDetector(Mat scene);
};