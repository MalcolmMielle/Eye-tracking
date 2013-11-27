#ifndef FILTRELAPLAVE_HPP
#define FILTRELAPLAVE_HPP

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "Filtre.hpp"
#include "Environement.hpp"

using namespace std;
using namespace cv;

class FiltreLaplace: public Filtre{
	protected : 
		
	public : 
	FiltreLaplace() : Filtre(){};
	
	FiltreLaplace(int i) : Filtre(i){};
	
	void goFiltre(Mat& img, Mat& gray, Mat& effet){
		Filtre::goFiltre(img, gray, effet);
		std::cout << "Laplace"<< std::endl;
		Mat tmp;
		if(_image_we_work_on==0){
			Laplacian( gray, tmp, -1, 3, 1, 0, BORDER_DEFAULT );
		}
		else if (_image_we_work_on==1){
			Laplacian( effet, tmp, -1, 3, 1, 0, BORDER_DEFAULT );
		}		
		effet=effet+tmp;

	}
};

#endif
