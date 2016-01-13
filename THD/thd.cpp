#include "thd.h"
#include "TestThread.h"
#include "THDUtil.h"
#include "LiveFeedThread.h"
#include "MainProcessingThread.h"
#include "LaneDetectionThread.h"
#include "ConsoleThread.h"
#include "CarDetectionThread.h"
#include "CarAnalysisThread.h"
#include "StopSignThread.h"
#include "GlobalSettings.h"
#include "SchoolSignThread.h"
#include "PedestrianThread.h"
#include "SpeedCallibrationThread.h"
//Windows Libaries
#include <propvarutil.h>
#include <InitGuid.h>
#include <propkey.h>
#include <propsys.h>
#include <Shobjidl.h>
#include <algorithm>
#include <QFileDialog>
#include <QMessageBox>

THD::THD(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	ui.hSliderProgress->setMaximum(100);
	ui.hSliderProgress->setMinimum(0);

	semaphore_console = CreateSemaphore(NULL, 0, 1, NULL); //Starting 0 Key, Max 1 Key
	semaphore_carAnalysis = CreateSemaphore(NULL, 0, 1, NULL); //Starting 0 Key, Max 1 Key
	semaphore_speedCallibration = CreateSemaphore(NULL, 0, 1, NULL); //Starting 0 Key, Max 1 Key
	semaphore_mainProcessing = CreateSemaphore(NULL, 1, 1, NULL); //Starting 1 Key, Max 1 Key
	semaphore_startVideo = CreateSemaphore(NULL, 0, 1, NULL);

	cascade.load("C:\\C Development\\OpenCVtest\\Resources\\haarcascade_cars3.xml");
	globalVideoLocation = "";
	
	
	setupThreads();
	
	
	//Connecting UI elements
	connect(ui.btnPlayPause, SIGNAL(released()), this, SLOT(onRelease_btnPlayPause()));
	connect(ui.btnSlowDown, SIGNAL(released()), this, SLOT(onRelease_btnSlowDown()));
	connect(ui.btnSpeedUp, SIGNAL(released()), this, SLOT(onRelease_btnSpeedUp()));
	connect(ui.btnBrowse, SIGNAL(released()), this, SLOT(onRelease_btnBrowse()));
	connect(ui.btnClear, SIGNAL(released()), this, SLOT(onRelease_btnClear()));
	connect(ui.btnStart, SIGNAL(released()), this, SLOT(onRelease_btnStart()));
	connect(ui.btnStop, SIGNAL(released()), this, SLOT(onRelease_btnStop()));
}

void THD::updateLiveFeed(QImage frame)
{
	ui.lblLiveFeed->setPixmap(QPixmap::fromImage(frame).scaled(ui.lblLiveFeed->width(), ui.lblLiveFeed->height(), Qt::KeepAspectRatio));
	return;
}

void THD::updateDetectionFeed(Mat frame)
{
	
	//Processing Approximated Lanes
	mutex_globalApproxLanes.lock();
	for (int i = 0; i < globalApproxLanes.size(); i++){
		Vec4i l = globalApproxLanes[i];
		line(frame, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, CV_AA);
		if (nextCallibration == 0)
			ui.lblEngineCallibration->setText("Callibrating");
	}
	if (globalApproxLanes.size() == 0)
		ui.lblEngineCallibration->setText("Idle");
	mutex_globalApproxLanes.unlock();

	//Processing Detetected Lanes
	mutex_globalDetectedRightLane.lock();
	if (globalDetectedRightLane[0] != 0 && globalDetectedRightLane[1] != 0){ // Check for non-empty
		detectedRightLane = globalDetectedRightLane;
		rightLaneLastUpdated = framesprocessed;
		globalDetectedRightLane[0] = 0;
	}
	mutex_globalDetectedRightLane.unlock();
	mutex_globalDetectedLeftLane.lock();
	if (globalDetectedLeftLane[0] != 0 && globalDetectedLeftLane[1] != 0){ // Check for non-empty
		detectedLeftLane = globalDetectedLeftLane; 
		leftLaneLastUpdated = framesprocessed;
		globalDetectedLeftLane[0] = 0;
	}
	mutex_globalDetectedLeftLane.unlock();

	//Drawing the Left Lane	
	if (framesprocessed - leftLaneLastUpdated < 20)
	{
		line(frame, Point(detectedLeftLane[0], detectedLeftLane[1]), Point(detectedLeftLane[2], detectedLeftLane[3]), Scalar(0, 255, 0), 2, CV_AA);
		ui.lblEngineCallibration->setText("Idle");
		nextCallibration = 30;
	}
	else if (framesprocessed - leftLaneLastUpdated<65)
		line(frame, Point(detectedLeftLane[0], detectedLeftLane[1]), Point(detectedLeftLane[2], detectedLeftLane[3]), Scalar(0, 242, 255), 2, CV_AA);
	//Drawing the Right Lane
	if (framesprocessed - rightLaneLastUpdated < 20)
	{
		line(frame, Point(detectedRightLane[0], detectedRightLane[1]), Point(detectedRightLane[2], detectedRightLane[3]), Scalar(0, 255, 0), 2, CV_AA);
		ui.lblEngineCallibration->setText("Idle");
		nextCallibration = 30;
	}
	else if (framesprocessed - rightLaneLastUpdated<65)
		line(frame, Point(detectedRightLane[0], detectedRightLane[1]), Point(detectedRightLane[2], detectedRightLane[3]), Scalar(0, 242, 255), 2, CV_AA);
		
	
	//Drawing Cars
	mutex_globalApproxCars.lock();
	for (int i = 0; i < globalApproxCars.size(); i++){
		rectangle(frame, globalApproxCars[i], Scalar(0, 0, 255), 1);
	}
	mutex_globalApproxCars.unlock();
	mutex_globalDetectedCars.lock();
	for (int i = 0; i < globalDetectedCars.size(); i++){
		rectangle(frame, globalDetectedCars[i], Scalar(255, 0, 0), 2);
	}
	mutex_globalDetectedCars.unlock();

	//Drawing Detected Stop Signs
	mutex_globalDetectedStopSign.lock();
	if (globalDetectedStopSign[0] != 0){
		detectedStopSign = globalDetectedStopSign;
		stopSignLastUpdated = framesprocessed;
	}
	mutex_globalDetectedStopSign.unlock();
	if (framesprocessed - stopSignLastUpdated < 10)
	{
		Point center(cvRound(detectedStopSign[0]), cvRound(detectedStopSign[1]));
		center.x = 2 * center.x + 361;
		center.y = 2 * center.y;
		if (framesprocessed - stopSignLastUpdated == 1){
			if (center.x - 10 >0 && center.y - 10 > 0){
				Rect stopSignROI(center.x - 10, center.y - 10, 20, 20);
				Mat stopsign = frame.clone();
				stopsign = stopsign(stopSignROI);
				updateAnalysisImage2(stopsign);
				updateConsoleMessage("Stop Sign Found");
				if (globalPauseOnDetection) // Pause on Detection
					onRelease_btnPlayPause();
			}
		}
		circle(frame, center, 8, Scalar(255, 0, 255), 2, 8, 0);
	}

	//Drawing Approximatted Stop Signs
	mutex_globalApproxStopSigns.lock();
	for (int i = 0; i < globalApproxStopSigns.size(); i++){
		Point center(cvRound(globalApproxStopSigns[i][0]), cvRound(globalApproxStopSigns[i][1]));
		center.x = 2 * center.x + 361;
		center.y = 2 * center.y;

		int radius = cvRound(globalApproxStopSigns[i][2]) * 2;
		circle(frame, center, radius, Scalar(0, 0, 255), 1, 8, 0);
	}
	mutex_globalApproxStopSigns.unlock();

	
	//Drawing Detected School Signs
	mutex_globalDetectedSchoolSign.lock();
	if (globalDetectedSchoolSign[0] != 0){
		detectedSchoolSign = globalDetectedSchoolSign;
		schoolSignLastUpdated = framesprocessed;
	}
	mutex_globalDetectedSchoolSign.unlock();
	if (framesprocessed - schoolSignLastUpdated < 10)
	{
		Point center(cvRound(detectedSchoolSign[0]), cvRound(detectedSchoolSign[1]));
		center.x = 2 * center.x + 361;
		center.y = 2 * center.y;
		if (framesprocessed - schoolSignLastUpdated == 1){
			if (center.x - 10 >0 && center.y - 10 > 0){
				Rect schoolSignROI(center.x - 10, center.y - 10, 20, 20);
				Mat schoolsign = frame.clone();
				schoolsign = schoolsign(schoolSignROI);
				updateAnalysisImage2(schoolsign);
				updateConsoleMessage("School Sign Found");
				if (globalPauseOnDetection)
					onRelease_btnPlayPause();
			}
		}
		circle(frame, center, 8, Scalar(255, 0, 255), 2, 8, 0);
	}
	
	//Drawing Approximatted School Signs
	mutex_globalApproxSchoolSigns.lock();
	for (int i = 0; i < globalApproxSchoolSigns.size(); i++){
		Point center(cvRound(globalApproxSchoolSigns[i][0]), cvRound(globalApproxSchoolSigns[i][1]));
		center.x = 2 * center.x + 361;
		center.y = 2 * center.y;

		int radius = cvRound(globalApproxSchoolSigns[i][2]) * 2;
		circle(frame, center, radius, Scalar(0, 0, 255), 1, 8, 0);
	}
	mutex_globalApproxSchoolSigns.unlock();

	mutex_globalDetectedPedestrian.lock();
	if (globalDetectedPedestrian.x != 0){
		detectedPedestrians = globalDetectedPedestrian;
		pedestrianLastUpdated = framesprocessed;
	}
	mutex_globalDetectedPedestrian.unlock();
	if (framesprocessed - pedestrianLastUpdated < 10)
	{
		if (framesprocessed - pedestrianLastUpdated == 1){
			Rect pedestrianROI(detectedPedestrians.tl(),detectedPedestrians.br());
			Mat pedestrian = frame.clone();
			pedestrian = pedestrian(pedestrianROI);
			updateAnalysisImage3(pedestrian);
			updateConsoleMessage("Pedestrian Found");
			if (globalPauseOnDetection)
				onRelease_btnPlayPause();
		}
		rectangle(frame, detectedPedestrians.tl(), detectedPedestrians.br(), cv::Scalar(0, 255, 0), 2);
	}

	// Resetting the Analysis Images After No Detection
	if (framesprocessed - hazard1LastUpdated > 40)
		ui.lblHazard1->setText("No Hazard");
	if (framesprocessed - hazard2LastUpdated > 80)
		ui.lblHazard2->setText("No Hazard");
	if (framesprocessed - hazard3LastUpdated > 80)
		ui.lblHazard3->setText("No Hazard");

	updateVideoInfo();

	//Convert and Display frame
	QImage DetectionFeedFrame = MatToQImage(frame);
	ui.lblDetectionFeed->setPixmap(QPixmap::fromImage(DetectionFeedFrame).scaled(ui.lblDetectionFeed->width(), ui.lblDetectionFeed->height(), Qt::KeepAspectRatio));
	
	//QImage* DetectionFeedFrame = NULL;
	//MatToQImage(frame,&DetectionFeedFrame);
	//ui.lblDetectionFeed->setPixmap(QPixmap::fromImage(*DetectionFeedFrame).scaled(ui.lblDetectionFeed->width(), ui.lblDetectionFeed->height(), Qt::KeepAspectRatio));
	

	framesprocessed++;
	if (nextCallibration != 0)
	{
		nextCallibration--;
	}
	return;
}

void THD::updateVideoInfo()
{
	//Update the Time Elapsed
	mutex_globalTimeElapsed.lock();
	ui.lblTimeElapsed->setNum(globalTimeElapsed);
	timeElapsed = globalTimeElapsed;
	double position = (globalTimeElapsed / duration) * 100;
	mutex_globalTimeElapsed.unlock();

	//Update the Frames Processed
	ui.lblFramesProcessed->setNum(framesprocessed);
	
	//Update the Slider Position
	ui.hSliderProgress->setSliderPosition(position);

	//Update the Vehicle Speed
	mutex_globalPercentHorizontal.lock();
	percentHorizontal = globalPercentHorizontal;
	mutex_globalPercentHorizontal.unlock();
	if (percentHorizontal > 0.7){
		String msg = to_string(percentHorizontal) + " (Slow)";
		ui.lblVehicleSpeed->setText(QString::fromStdString(msg));
	}else{
		String msg = to_string(percentHorizontal) + " (Fast)";
		ui.lblVehicleSpeed->setText(QString::fromStdString(msg));
	}

}

void THD::updateAnalysisImage(Mat frame)
{
	hazard1LastUpdated = framesprocessed;
	QImage analysisImage = MatToQImage(frame);
	ui.lblHazard1->setPixmap(QPixmap::fromImage(analysisImage).scaled(ui.lblHazard1->width(), ui.lblHazard1->height(), Qt::KeepAspectRatio));
	return;
}

void THD::updateAnalysisImage2(Mat frame)
{
	hazard2LastUpdated = framesprocessed;
	QImage analysisImage = MatToQImage(frame);
	ui.lblHazard2->setPixmap(QPixmap::fromImage(analysisImage).scaled(ui.lblHazard2->width(), ui.lblHazard2->height(), Qt::KeepAspectRatio));
	return;
}

void THD::updateAnalysisImage3(Mat frame)
{
	hazard3LastUpdated = framesprocessed;
	QImage analysisImage = MatToQImage(frame);
	ui.lblHazard3->setPixmap(QPixmap::fromImage(analysisImage).scaled(ui.lblHazard2->width(), ui.lblHazard2->height(), Qt::KeepAspectRatio));
	return;
}

void THD::updateConsoleMessage()
{
	string msg;
	mutex_consoleMessage.lock();
	msg = consoleMessage; //Gets the message
	consoleMessage.clear();
	mutex_consoleMessage.unlock();
	QString qmsg = QString::fromStdString(msg);
	ui.lWidgetConsole->addItem(qmsg);
}

void THD::updateConsoleMessage(String msg)
{
	if (timeElapsed < 1)
		return;
	msg = "[" + to_string(timeElapsed) + "] >> " + msg;
	QString qmsg = QString::fromStdString(msg);
	ui.lWidgetConsole->addItem(qmsg);
	return;
}

int THD::getVideoDuration(String filename)
{
	CoInitialize(NULL);
	HRESULT hr = S_OK;
	IPropertyStore* store = NULL;
	hr = SHGetPropertyStoreFromParsingName(THDUtil::String2wString(filename).c_str(), 
		                                   NULL, GPS_READWRITE, __uuidof(IPropertyStore), (void**)&store);
	PROPVARIANT variant;
	hr = store->GetValue(PKEY_Media_Duration, &variant);
	int duration = variant.uhVal.QuadPart / 10000000; //Converted microseconds to seconds
	store->Release();
	return duration;
}

void THD::updateCannyImage(Mat frame)
{
	QImage cannyImage = MatToQImage(frame);
	ui.lblAnalysisImage1->setPixmap(QPixmap::fromImage(cannyImage).scaled(ui.lblAnalysisImage1->width(), ui.lblAnalysisImage1->height(), Qt::KeepAspectRatio));
	return;
}

void THD::updateCarImage(Mat frame)
{
	QImage carImage = MatToQImage(frame);
	ui.lblAnalysisImage2->setPixmap(QPixmap::fromImage(carImage).scaled(ui.lblAnalysisImage2->width(), ui.lblAnalysisImage2->height(), Qt::KeepAspectRatio));
	return;
}

void THD::updateSpeedImage(Mat frame)
{
	QImage speedImage = MatToQImage(frame);
	ui.lblAnalysisImage2->setPixmap(QPixmap::fromImage(speedImage).scaled(ui.lblAnalysisImage2->width(), ui.lblAnalysisImage2->height(), Qt::KeepAspectRatio));
	return;
}

void THD::onRelease_btnPlayPause()
{
	QString str = ui.btnPlayPause->text();
	if (str == "Pause")
	{
		WaitForSingleObject(semaphore_mainProcessing, INFINITE);
		ui.btnPlayPause->setText("Play");
	}
	else
	{
		ui.btnPlayPause->setText("Pause");
		ReleaseSemaphore(semaphore_mainProcessing, 1, NULL);
	}
	return;
}

void THD::onRelease_btnSlowDown()
{
	mutex_globalSleepTime.lock();
	globalSleepTime += 100;
	String msg = "-" + to_string(globalSleepTime) + "ms";
	mutex_globalSleepTime.unlock();
	ui.lblVideoSpeed->setText(QString::fromStdString(msg));
	return;
}

void THD::onRelease_btnSpeedUp()
{
	mutex_globalSleepTime.lock();
	globalSleepTime = 0;
	mutex_globalSleepTime.unlock();
	ui.lblVideoSpeed->setText("1x");
	return;
}

void THD::onRelease_btnBrowse()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C:\\C Development\\THDTestSamples",tr("Files(*.wmv*)"));
	fileName.replace("/", "\\");
	ui.lEditVideoLocation->setText(fileName);
	return;
}

void THD::onRelease_btnClear()
{
	ui.lEditVideoLocation->clear();
	return;
}

void THD::onRelease_btnStart()
{
	QString dir = ui.lEditVideoLocation->text();
	globalVideoLocation = dir.toStdString();
	VideoCapture cap(globalVideoLocation);
	if (!cap.isOpened()){  // Cannot Open the video
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, "Error", "Invalid Video File. Pick Again?",
			QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes) {
			onRelease_btnBrowse();
			return;
		}
		else{
			return;
		}
	}

	if (ui.cBoxAnnotations->checkState() == Qt::Checked)
		globalAnnotations = true;
	else
		globalAnnotations = false;
	if (ui.cBoxDetectionPause->checkState() == Qt::Checked)
		globalPauseOnDetection = true;
	else
		globalPauseOnDetection = false;
	if (ui.cBoxRGBCorrection->checkState() == Qt::Checked)
		globalCorrectRGB = true;
	else
		globalCorrectRGB = false;

	// Disables all interfaces
	ui.btnStart->setDisabled(true);
	ui.btnClear->setDisabled(true);
	ui.btnBrowse->setDisabled(true);
	ui.lEditVideoLocation->setDisabled(true);
	ui.cBoxAnnotations->setDisabled(true);
	ui.cBoxDetectionPause->setDisabled(true);
	ui.cBoxRGBCorrection->setDisabled(true);

	duration = getVideoDuration(globalVideoLocation); //Calculate the video duration
	//ReleaseSemaphore(semaphore_startVideo, 1, NULL);

	//Start all threads
	globalStop = false;
	qthread_MainProcess->start();
	qthread_LaneDetectionThread->start();
	qthread_carDetectionThread->start();
	qthread_carAnalysisThread->start();
	qthread_StopSignThread->start();
	qthread_PedestrianThread->start();
	qthread_SpeedCallibrationThread->start();

	ui.btnStop->setDisabled(false); //Enable the stop button

	return;
}

void THD::onRelease_btnStop()
{
	ui.btnStop->setDisabled(true);
	if (!qthread_MainProcess->isFinished())
		globalStop = true;
	else{
		qthread_MainProcess->quit();
	}
	ui.btnStart->setDisabled(false);
	ui.btnClear->setDisabled(false);
	ui.btnBrowse->setDisabled(false);
	ui.lEditVideoLocation->setDisabled(false);
	ui.cBoxAnnotations->setDisabled(false);
	ui.cBoxDetectionPause->setDisabled(false);
	ui.cBoxRGBCorrection->setDisabled(false);

	setupThreads();

	return;
}

void THD::setupThreads()
{
	qthread_MainProcess = new QThread();
	MainProcessingThread* thread_MainProcess = new MainProcessingThread();
	thread_MainProcess->moveToThread(qthread_MainProcess);
	connect(qthread_MainProcess, SIGNAL(started()), thread_MainProcess, SLOT(process()));
	connect(thread_MainProcess, SIGNAL(sendLiveFeedFrame(QImage)), this, SLOT(updateLiveFeed(QImage)));
	connect(thread_MainProcess, SIGNAL(sendDetectionFeedFrame(Mat)), this, SLOT(updateDetectionFeed(Mat)));


	qthread_LaneDetectionThread = new QThread();
	LaneDetectionThread* thread_LaneDetectionThread = new LaneDetectionThread();
	thread_LaneDetectionThread->moveToThread(qthread_LaneDetectionThread);
	connect(qthread_LaneDetectionThread, SIGNAL(started()), thread_LaneDetectionThread, SLOT(process()));
	connect(thread_LaneDetectionThread, SIGNAL(sendCannyImage(Mat)), this, SLOT(updateCannyImage(Mat)));

	/***
	QThread* qthread_ConsoleThread = new QThread();
	ConsoleThread* thread_ConsoleThread = new ConsoleThread();
	thread_ConsoleThread->moveToThread(qthread_ConsoleThread);
	connect(qthread_ConsoleThread, SIGNAL(started()), thread_ConsoleThread, SLOT(process()));
	connect(thread_ConsoleThread, SIGNAL(sendGlobalMessage()), this, SLOT(updateConsoleMessage()));
	qthread_ConsoleThread->start();
	**/

	qthread_carDetectionThread = new QThread();
	CarDetectionThread* thread_carDetectionThread = new CarDetectionThread();
	thread_carDetectionThread->moveToThread(qthread_carDetectionThread);
	connect(qthread_carDetectionThread, SIGNAL(started()), thread_carDetectionThread, SLOT(process()));
	//connect(thread_carDetectionThread, SIGNAL(sendCarImage(Mat)), this, SLOT(updateCarImage(Mat)));

	qthread_carAnalysisThread = new QThread();
	CarAnalysisThread* thread_carAnalysisThread = new CarAnalysisThread();
	thread_carAnalysisThread->moveToThread(qthread_carAnalysisThread);
	connect(qthread_carAnalysisThread, SIGNAL(started()), thread_carAnalysisThread, SLOT(process()));
	connect(thread_carAnalysisThread, SIGNAL(sendCarAnalysisFrame(Mat)), this, SLOT(updateAnalysisImage(Mat)));


	qthread_StopSignThread = new QThread();
	StopSignThread* thread_StopSignThread = new StopSignThread();
	thread_StopSignThread->moveToThread(qthread_StopSignThread);
	connect(qthread_StopSignThread, SIGNAL(started()), thread_StopSignThread, SLOT(process()));


	/**
	QThread* qthread_SchoolSignThread = new QThread();
	SchoolSignThread* thread_SchoolSignThread = new SchoolSignThread();
	thread_SchoolSignThread->moveToThread(qthread_SchoolSignThread);
	connect(qthread_SchoolSignThread, SIGNAL(started()), thread_SchoolSignThread, SLOT(process()));
	qthread_SchoolSignThread->start();
	**/

	qthread_PedestrianThread = new QThread();
	PedestrianThread* thread_PedestrianThread = new PedestrianThread();
	thread_PedestrianThread->moveToThread(qthread_PedestrianThread);
	connect(qthread_PedestrianThread, SIGNAL(started()), thread_PedestrianThread, SLOT(process()));


	qthread_SpeedCallibrationThread = new QThread();
	SpeedCallibrationThread* thread_SpeedCallibrationThread = new SpeedCallibrationThread();
	thread_SpeedCallibrationThread->moveToThread(qthread_SpeedCallibrationThread);
	connect(qthread_SpeedCallibrationThread, SIGNAL(started()), thread_SpeedCallibrationThread, SLOT(process()));
	connect(thread_SpeedCallibrationThread, SIGNAL(sendSpeedImage(Mat)), this, SLOT(updateSpeedImage(Mat)));
	return;
}

THD::~THD()
{

}
