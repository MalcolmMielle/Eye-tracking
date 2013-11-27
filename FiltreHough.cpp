#include "FiltreHough.hpp"
#include "Environement.hpp"

void FiltreHough::goFiltre(Mat& img, Mat& gray, Mat& effet){
	Filtre::goFiltre(img, gray, effet);
	vector<Vec3f> circles;
	Mat work_on;
	
	if(_image_we_work_on==0){
		work_on=gray;
	}
	else{
		work_on=effet;
	}
	
	HoughCircles( work_on, circles, CV_HOUGH_GRADIENT, 1, work_on.rows/8, 200, 100, 0, 0 );	
	/// Draw the circles detected
	for( size_t i = 0; i < circles.size(); i++ )
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		// circle center
		circle( effet, center, 3, Scalar(0,255,0), -1, 8, 0 );
		// circle outline
		circle( effet, center, radius, Scalar(0,0,255), 3, 8, 0 );
	}
}
