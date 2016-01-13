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
//C++ Libaries
#include <windows.h>
//THD Libaries
#include "MatToQImage.h"
#include "GlobalSettings.h"

using namespace cv;

class LiveFeedThread : public QObject {
	Q_OBJECT

public:
	LiveFeedThread();

public slots:
	void process();

signals:
	void newFrame(QImage frame);

private:
	String vidLocation1 = "C:\\C Development\\THDTestSamples\\TestSample1.wmv";
	int webcame = 0;
};