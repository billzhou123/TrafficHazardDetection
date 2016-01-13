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
#include "GlobalSettings.h"

using namespace cv;
using namespace std;


class ConsoleThread : public QObject {
	Q_OBJECT

public:
	ConsoleThread();


public slots:
	void process();

signals:
	void sendGlobalMessage();
	

private:
};