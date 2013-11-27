#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
//#include "Point3D.hpp"
#include "cv.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

class Vecteur{
	protected : 
	Point3i x;
	Point3i y;
	public : 
	Vecteur() : x(Point3i()), y(Point3i()){}
	Vecteur(const Point3i xx, const Point3i yy) : x(xx), y(yy){}
	
	void setX(const Point3i& xx){x=xx;}
	void setY(const Point3i& yy){y=yy;}
	
	Point3i getX() const {return x;}
	Point3i getY() const {return y;}
	
	void operator=(const Vecteur& p){
		setX(p.getX());
		setY(p.getY());
	}
	
	bool operator==(const Vecteur& p){
		if(p.getX()==getX() && p.getY()==getY())
		{
			return true;
		}
		return false;
	}
	
};
#endif
