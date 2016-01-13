#include "THDUtil.h"

Mat THDUtil::sharpen(Mat img)
{
	Mat kern = (Mat_<char>(3, 3) << 0, -1, 0,
		-1, 5, -1,
		0, -1, 0);
	filter2D(img, img, -1, kern);
	return img;
}

Mat THDUtil::computeOrientation(Mat frame)
{
	Mat padded; //expanding input image to optimal size by making boarder
	int m = getOptimalDFTSize(frame.rows);
	int n = getOptimalDFTSize(frame.cols);
	copyMakeBorder(frame, padded, m - frame.rows, 0, n - frame.cols, BORDER_CONSTANT, 0);

	Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI);

	dft(complexI, complexI);

	split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
	magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
	Mat magI = planes[0];

	magI += Scalar::all(1);                    // switch to logarithmic scale
	log(magI, magI);

	// crop the spectrum, if it has an odd number of rows or columns
	magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));

	// rearrange the quadrants of Fourier image  so that the origin is at the image center
	int cx = magI.cols / 2;
	int cy = magI.rows / 2;

	Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
	Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
	Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
	Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right

	Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);

	q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
	q2.copyTo(q1);
	tmp.copyTo(q2);

	normalize(magI, magI, 0, 1, CV_MINMAX); // Transform the matrix with float values into a
	// viewable image form (float between values 0 and 1).
	return magI;
}

Vec4i THDUtil::averageLanes(vector<Vec4i> lanes){
	Vec4i avgLane;
	int size = lanes.size();

	if (size == 1){
		return lanes[0];
	}

	//Finding median x1 coordinates
	if (size % 2 == 0){ //If there is even number of lanes
		int x = lanes[size / 2][0] + lanes[size / 2 - 1][0]; //Average value of the middle two
		avgLane[0] = x;
		int y = lanes[size / 2][1] + lanes[size / 2 - 1][1];
		avgLane[1] = y;
	}
	else{
		avgLane[0] = lanes[size / 2 - 1][0];
		avgLane[1] = lanes[size / 2 - 1][1];
	}

	//Finding median x2 coordinates --> Sort the array in ascending order first
	int i, j, flag = 1; //set flag to 1 to start first pass
	int temp; //holding variable
	for (i = 1; (i <= size) && flag; i++)
	{
		flag = 0;
		for (j = 0; j < (size - 1); j++)
		{
			if (lanes[j + 1][2] < lanes[j][2])
			{
				temp = lanes[j][2];             //swap x2 elements
				lanes[j][2] = lanes[j + 1][2];
				lanes[j + 1][2] = temp;

				temp = lanes[j][3];             //swap y2 elements
				lanes[j][3] = lanes[j + 1][3];
				lanes[j + 1][3] = temp;

				flag = 1;                       //indicates that a swap occurred.
			}
		}
	}

	//Finding median x2 coordinates
	if (size % 2 == 0){ //If there is even number of lanes
		int x = lanes[size / 2][2] + lanes[size / 2 - 1][2]; //Average value of the middle two
		avgLane[2] = x;
		int y = lanes[size / 2][3] + lanes[size / 2 - 1][3];
		avgLane[3] = y;
	}
	else{
		avgLane[2] = lanes[size / 2 - 1][2];
		avgLane[3] = lanes[size / 2 - 1][3];
	}

	return avgLane;
}

vector<Point> THDUtil::circleDetector(Mat& imgThresholded, Mat& scene, int cannyThreshold, int accumulatorThreshold, int minSize, int maxSize)
{
	GaussianBlur(imgThresholded, imgThresholded, Size(3, 3), 2, 2);

	vector<Vec3f> circles;
	vector<Point> circleLocation;


	/// Apply the Hough Transform to find the circles
	HoughCircles(imgThresholded, circles, CV_HOUGH_GRADIENT, 1, imgThresholded.rows / 8, cannyThreshold, accumulatorThreshold, minSize, maxSize);

	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		circleLocation.push_back(center);
	}

	return circleLocation;

}

bool THDUtil::inVicinity(Point pt1, Point pt2, double threshhold)
{
	double result = sqrt((pt1.x - pt2.x)*(pt1.x - pt2.x) + (pt1.y - pt2.y)*(pt1.y - pt2.y));
	if (result <= threshhold)
		return true;
	
	return false;
}

Point THDUtil::colorDetector(Mat& scene, Mat& imgThresholded, Scalar lowerHSV, Scalar upperHSV)
{
	Mat imgHSV;

	cvtColor(scene, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

	inRange(imgHSV, lowerHSV, upperHSV, imgThresholded); //Threshold the image


	//morphological opening (removes small objects from the foreground)
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
	dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

	//morphological closing (removes small holes from the foreground)
	dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));


	Moments oMoments = moments(imgThresholded);

	double dM01 = oMoments.m01;
	double dM10 = oMoments.m10;
	double dArea = oMoments.m00;

	// if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
	if (dArea > 1000){
		return Point((int)(dM10 / dArea), (int)(dM01 / dArea));
	}

	return Point(-1, -1);
}

wstring THDUtil::String2wString(const string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}