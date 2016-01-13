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

extern Mat globalFrame;
extern QMutex mutex_globalFrame;

extern vector<Vec4i> globalApproxLanes;
extern QMutex mutex_globalApproxLanes;

extern Vec4i globalDetectedRightLane;
extern QMutex mutex_globalDetectedRightLane;

extern Vec4i globalDetectedLeftLane;
extern QMutex mutex_globalDetectedLeftLane;

extern string consoleMessage;
extern QMutex mutex_consoleMessage;

extern CascadeClassifier cascade;

extern vector<Rect> globalDetectedCars;
extern QMutex mutex_globalDetectedCars;

extern vector<Rect> globalApproxCars;
extern QMutex mutex_globalApproxCars;

extern Mat globalCarFrame1;
extern QMutex mutex_globalCarFrame1;

extern Mat globalCarFrame2;
extern QMutex mutex_globalCarFrame2;

extern String globalVideoLocation;

extern vector<Vec3f> globalApproxStopSigns;
extern QMutex mutex_globalApproxStopSigns;

extern Vec3f globalDetectedStopSign;
extern QMutex mutex_globalDetectedStopSign;

extern vector<Vec3f> globalApproxSchoolSigns;
extern QMutex mutex_globalApproxSchoolSigns;

extern Vec3f globalDetectedSchoolSign;
extern QMutex mutex_globalDetectedSchoolSign;

extern Rect globalDetectedPedestrian;
extern QMutex mutex_globalDetectedPedestrian;

extern double globalTimeElapsed;
extern QMutex mutex_globalTimeElapsed;

extern int globalVideoPosition;
extern QMutex mutex_globalVideoPosition;

extern HANDLE semaphore_console;

extern HANDLE semaphore_carAnalysis;

extern double globalPercentHorizontal;
extern QMutex mutex_globalPercentHorizontal;

extern Mat globalRefererenceImage;
extern QMutex mutex_globalReferenceImage;

extern Mat globalSampleImage;
extern QMutex mutex_globalSampleImage;

extern HANDLE semaphore_speedCallibration;

extern HANDLE semaphore_mainProcessing;

extern int globalSleepTime;
extern QMutex mutex_globalSleepTime;

extern HANDLE semaphore_startVideo;

extern bool globalStop;

extern bool globalPauseOnDetection;

extern bool globalCorrectRGB;

extern bool globalAnnotations;