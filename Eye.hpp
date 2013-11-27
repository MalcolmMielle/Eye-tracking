#ifndef EYEVISION_HPP
#define EYEVISION_HPP
#include "cv.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "Vecteur.hpp"
#include "Filtre.hpp"
//#include "Graph.hpp"
using namespace std;
using namespace cv;

class Eye{
	protected : 
	Mat eye;
	Mat eye_effet;
	Rect eye_rec;
	Point center;
	float radius;
	Vecteur direction;
	std::vector<Filtre *> filtres;
	public : 
	Eye() : eye(Mat::zeros(0,0,CV_8U)), eye_effet(Mat::zeros(0,0,CV_8U)), center(Point()), radius(0), direction(Vecteur()) {};
	
	Eye(float a, float b, float rad) : eye(Mat()), center(Point(a,b)), radius(rad), direction(Vecteur()) {};
	
	Eye(const Point& ccenter, float rad) : eye(Mat()), center(ccenter), radius(rad), direction(Vecteur()) {};
	
	Eye(const Mat& eeye, const Point& ccenter, float rad, const Vecteur& direc) : eye(eeye), center(ccenter), radius(rad), direction(direc){};
	
	Eye(const Mat& eeye, const Rect& r, const Point& ccenter, float rad) : eye(eeye), eye_rec(r), center(ccenter), radius(rad){};
	
	Mat& getEyeMat()  {return eye;}
	Rect& getEyeRec()  {return eye_rec;}
	Point& getCenter() {return center;}
	float getRadius(){return radius;}
	const Vecteur getDirection() const {return direction;}
	
	void setEye(const Mat& e){eye=e;}
	void setEff(const Mat& e){eye_effet=e;};
	void setCenter(const Point cen){center=cen;} //Check if the prog me cris dessus à cause du const !!!!
	void setRadius(float rad){radius=rad;}
	void setDirection(const Vecteur dir){direction=dir;}
	void setEye(const Rect& r, const Point& c){
		eye_rec=r;
		center=c;
	}
	void add(Filtre* f){filtres.push_back(f);}
	void filter(){
//		std::cout<< "Filtroux" << eye_effet.rows << " "<< eye_effet.rows << std::endl;
		for(typename std::vector<Filtre*>::iterator it=filtres.begin();it!=filtres.end();){	
//			std::cout<< "Filtration" << eye_effet.rows << " "<< eye_effet.rows << std::endl;
			(**it).goFiltre(eye, eye, eye_effet);	
			it++;
		}
//		std::cout<< "taille" << eye_effet.rows << " "<< eye_effet.rows << std::endl;
		if (eye_effet.rows==0 && eye_effet.cols==0){
			eye_effet=Mat::zeros(eye.rows, eye.cols,CV_8U);
		}
		
	}
	
	void affiche(int i){
		filter();
//		std::cout<< "EYEEEEEES.hpp affiche" << std::endl;
		ostringstream ss;
		String ss2="eye";
		ss<< ss <<i;
		ss2=ss.str();
		namedWindow(ss2,1);
		imshow( ss2, eye_effet);	
	
	}
};
#endif
