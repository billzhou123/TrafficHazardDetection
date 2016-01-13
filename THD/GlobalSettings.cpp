// QT Libaries
#include <QtCore/QThread>
#include <QtCore/QTime>
#include <QtCore/QQueue>
#include <qmutex.h>
//OpenCV Libaries
#include "opencv2/core/core.hpp"
#include "opencv/cv.h"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include <opencv2/video/background_segm.hpp>
//C++ Libaries
#include <windows.h>
#include <string.h>
//THD Libaries
#include "MatToQImage.h"

using namespace cv;

Mat globalFrame;
QMutex mutex_globalFrame;

vector<Vec4i> globalApproxLanes;
QMutex mutex_globalApproxLanes;

Vec4i globalDetectedRightLane;
QMutex mutex_globalDetectedRightLane;

Vec4i globalDetectedLeftLane;
QMutex mutex_globalDetectedLeftLane;

string consoleMessage;
QMutex mutex_consoleMessage;

CascadeClassifier cascade;

vector<Rect> globalDetectedCars;
QMutex mutex_globalDetectedCars;

vector<Rect> globalApproxCars;
QMutex mutex_globalApproxCars;

Mat globalCarFrame1;
QMutex mutex_globalCarFrame1;

Mat globalCarFrame2;
QMutex mutex_globalCarFrame2;

String globalVideoLocation;

vector<Vec3f> globalApproxStopSigns;
QMutex mutex_globalApproxStopSigns;

Vec3f globalDetectedStopSign;
QMutex mutex_globalDetectedStopSign;

vector<Vec3f> globalApproxSchoolSigns;
QMutex mutex_globalApproxSchoolSigns;

Vec3f globalDetectedSchoolSign;
QMutex mutex_globalDetectedSchoolSign;

Rect globalDetectedPedestrian;
QMutex mutex_globalDetectedPedestrian;

double globalTimeElapsed;
QMutex mutex_globalTimeElapsed;

int globalVideoPosition;
QMutex mutex_globalVideoPosition;

HANDLE semaphore_console;

HANDLE semaphore_carAnalysis;

double globalPercentHorizontal;
QMutex mutex_globalPercentHorizontal;

Mat globalRefererenceImage;
QMutex mutex_globalReferenceImage;

Mat globalSampleImage;
QMutex mutex_globalSampleImage;

HANDLE semaphore_speedCallibration;

HANDLE semaphore_mainProcessing;

int globalSleepTime = 0;
QMutex mutex_globalSleepTime;

HANDLE semaphore_startVideo;

bool globalStop = false;

bool globalPauseOnDetection = false;

bool globalCorrectRGB = false;

bool globalAnnotations = false;