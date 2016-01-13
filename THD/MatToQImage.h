#ifndef MATTOQIMAGE_H
#define MATTOQIMAGE_H

// Qt
#include <QtGui/QImage>
// OpenCV
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace cv;

void MatToQImage(const Mat& mat, QImage** img);
QImage MatToQImage(const Mat& mat);

#endif // MATTOQIMAGE_H
