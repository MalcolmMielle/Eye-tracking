#include "FiltreSobel.hpp"

void FiltreSobel::goFiltre(Mat& img, Mat& gray, Mat& effet){
	
	Filtre::goFiltre(img, gray, effet);
	Mat sobel;
	Mat tmp;
	//Sobel loul =D
	if(_image_we_work_on==0){
		Sobel(gray, sobel, -1, 1, 0, 3, 1, 0, BORDER_DEFAULT ); //-1 est la profondeur. -1 donne la même profondeur de l'image de départ pour l'arrivé
		tmp=sobel.clone();
		Sobel(gray, sobel, -1, 0, 1, 3, 1, 0, BORDER_DEFAULT );
	}
	else if(_image_we_work_on==1){
		Sobel(effet, sobel, -1, 1, 0, 3, 1, 0, BORDER_DEFAULT ); //-1 est la profondeur. -1 donne la même profondeur de l'image de départ pour l'arrivé
		tmp=sobel.clone();
		Sobel(effet, sobel, -1, 0, 1, 3, 1, 0, BORDER_DEFAULT );
	}	
	tmp=tmp+sobel;	
	effet=effet+tmp; //ligne à problème 
	
}
