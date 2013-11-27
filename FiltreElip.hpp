#ifndef FILTREELIP_HPP
#define FILTREELIP_HPP

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

class FiltreElip: public Filtre{
	protected : 
	Rect _rec1;
	Mat _filtre1;
	int _sum1;
	public : 
	FiltreElip() : _filtre1(Mat::ones(5,9,CV_8U)), _sum1(-1){
		_rec1=Rect(0,0,_filtre1.rows,_filtre1.cols);
	};
	FiltreElip(const Mat& fil) : _filtre1(fil),  _sum1(-1){
		_rec1=Rect(0,0,_filtre1.rows,_filtre1.cols);
	};
	FiltreElip(int i, int j) : _filtre1(Mat::ones(i,j,CV_8U)),  _sum1(-1){
		_rec1=Rect(0,0,_filtre1.rows,_filtre1.cols);
	};
	void goFiltre(Mat& img, Mat& gray, Mat& effet);
	Rect& getRec(){return _rec1;} 
	int getSum(){return _sum1;}
	
	void affiche(Mat& img){
//		std::cout << "On dessine à " << _rec1.y + _rec1.height*0.5 << std::endl;
		Point center( _rec1.x + _rec1.width*0.5, _rec1.y + _rec1.height*0.5 );
		ellipse(img, center, Size( _rec1.width*0.5, _rec1.height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
	}
};

#endif
