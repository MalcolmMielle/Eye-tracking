#ifndef FILTRE_HPP
#define FILTRE_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include "cv.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

class Environement;

class Filtre{
	protected : 
	int  _image_we_work_on;//0 work on gray, 1 we work on effet
	
	public : 
	Filtre() : _image_we_work_on(0){};
	Filtre(int i) : _image_we_work_on(i){
		if(_image_we_work_on!=0 && _image_we_work_on!=1){
			std::cout << "no correct value for _image_we_work_on"<<std::endl;
			exit(0);
		}
	}
	virtual ~Filtre(){};
	virtual void goFiltre(Mat& img, Mat& gray, Mat& effet)=0;
	
};

inline void Filtre::goFiltre(Mat& img, Mat& gray, Mat& effet){
//	std::cout<<"PREMIER FILTRE TOUJOURS LA"<<std::endl;
	if (effet.rows==0 && effet.cols==0){
		effet=Mat::zeros(gray.rows, gray.cols,CV_8U);
	}
}

#endif
