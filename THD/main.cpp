#include "thd.h"
#include <QtWidgets/QApplication>

Q_DECLARE_METATYPE(Vec4i);

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qRegisterMetaType<Mat>();
	
	qRegisterMetaType<Vec4i>();
	THD w;
	w.show();
	return a.exec();
}
