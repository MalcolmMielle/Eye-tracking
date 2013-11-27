#include "FiltreCouleur.hpp"

void FiltreCouleur::goFiltre(Mat& img, Mat& gray, Mat& effet)
{
	Filtre::goFiltre(img, gray, effet);
	Mat high;
	if(_image_we_work_on==0){
		cvtColor(img, high, CV_BGR2HSV);
	}
	else{
		cvtColor(effet, high, CV_BGR2HSV);
	}
	inRange(high, _s1, _s2, effet); //Grab le jaune
}
