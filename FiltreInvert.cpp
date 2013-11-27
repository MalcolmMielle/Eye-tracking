#include "FiltreInvert.hpp"

void FiltreInvert::goFiltre(Mat& img, Mat& gray, Mat& effet)
{
	Filtre::goFiltre(img, gray, effet);
	if(_image_we_work_on==0){
		effet=255-gray;
	}
	else
	{
		effet=255-effet;
	}
	std::cout << "Godzilla end"<<std::endl;
}
