#include <QtCore/QThread>
#include <QtCore/QTime>
#include <QtCore/QQueue>

#include <windows.h>

class TestThread : public QObject {
	Q_OBJECT

public:
	TestThread();

public slots:
	void process();

signals:
	void finished(int i);
	void error(QString err);
};