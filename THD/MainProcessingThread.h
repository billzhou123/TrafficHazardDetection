// QT Libaries
#include <QtCore/QThread>
#include <QtCore/QTime>
#include <QtCore/QQueue>
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
//THD Libaries
#include "MatToQImage.h"

using namespace cv;

class MainProcessingThread : public QObject {
	Q_OBJECT

public:
	MainProcessingThread();

public slots:
	void process();

signals:
	void sendLiveFeedFrame(QImage frame);
	void sendDetectionFeedFrame(Mat frame);

private:
	String vidLocation1 = "C:\\C Development\\VideoSample\\ShowSet.wmv";
	int webcam = 0;
	int framesprocessed = 0;
	int sleepTime = 0;
	
};