#ifndef THD_H
#define THD_H
//QT Libaries
#include <QtWidgets/QMainWindow>
#include <qdebug.h>
//OpenCV Libaries
#include "opencv2/core/core.hpp"
#include "opencv/cv.h"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include <opencv2/video/background_segm.hpp>
//Windows Libaries

//Self-defined Libaries
#include "ui_thd.h"
#include "MatToQImage.h"

Q_DECLARE_METATYPE(Mat);

class THD : public QMainWindow 
{
	Q_OBJECT

public:
	THD(QWidget *parent = 0);
	~THD();

public slots:
	//Display Image Slots
	void updateLiveFeed(QImage frame);
	void updateDetectionFeed(Mat frame);
	void updateConsoleMessage();
	void updateConsoleMessage(String msg);
	void updateAnalysisImage(Mat frame);
	void updateAnalysisImage2(Mat frame); 
	void updateAnalysisImage3(Mat frame);
	void updateVideoInfo();
	int getVideoDuration(String filename);
	void updateCannyImage(Mat frame);
	void updateCarImage(Mat frame);
	void updateSpeedImage(Mat frame);
	
	//UI Slots
	void onRelease_btnPlayPause();
	void onRelease_btnSlowDown();
	void onRelease_btnSpeedUp();
	void onRelease_btnBrowse();
	void onRelease_btnClear();
	void onRelease_btnStart();
	void onRelease_btnStop();

private:
	Ui::THDClass ui;
	//Lane Drawing Variables
	Vec4i detectedRightLane;
	Vec4i detectedLeftLane;
	int rightLaneLastUpdated;
	int leftLaneLastUpdated;
	int framesprocessed = 0;

	//Car Drawing Variables
	vector<Rect> approxCars;
	vector<Rect> detectedCars;

	//Traffic Sign Drawing Variables
	Vec3f detectedStopSign;
	int stopSignLastUpdated;
	Point lastStopSignLocation;
	Vec3f detectedSchoolSign;
	int schoolSignLastUpdated;
	Point lastSchoolSignLocation;

	//Pedestrian Drawing Variables
	Rect detectedPedestrians;
	int pedestrianLastUpdated;

	//Analysis Images Display Variables
	int hazard1LastUpdated;
	int hazard2LastUpdated;
	int hazard3LastUpdated;

	//Video Variables
	int duration;
	int nextCallibration = 0;
	bool callibrationCountDown = false;
	double timeElapsed;
	double percentHorizontal = 0;

	//QThreads
	QThread* qthread_MainProcess;
	QThread* qthread_LaneDetectionThread;
	QThread* qthread_carDetectionThread;
	QThread* qthread_carAnalysisThread;
	QThread* qthread_StopSignThread;
	QThread* qthread_PedestrianThread;
	QThread* qthread_SpeedCallibrationThread;

	void setupThreads();
};

#endif // THD_H
