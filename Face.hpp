#ifndef FACEVISION_HPP
#define FACEVISION_HPP
#include "cv.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "Eye.hpp"
//#include "Graph.hpp"
using namespace std;
using namespace cv;

class Face{
	protected :
	Mat face;
	Rect face_rec;
	vector<Eye *> eyes;
	Point center;

	public : 
	Face() : face(Mat()) {
		//std::vector<Eye>& ey;
		Eye e;
		eyes.push_back(&e);
		eyes.push_back(&e);
		//eyes=ey;
	};
	
	Face(const Mat& f, const Rect& fr, vector<Eye *> e) : face(f), face_rec(fr), eyes(e), center(0){};
	
	Face(const Mat& f, const Rect& fr, Point cen) : face(f), face_rec(fr), center(cen){};
	
	Face(const vector<Eye *> e) : face(Mat()), face_rec(Rect()), eyes(e), center(0){};
	
	Face(const Mat& f, Eye* e) : face(f), face_rec(Rect()), center(0){
		std::vector<Eye *> ey;
		ey.push_back(e);
		ey.push_back(e);
		eyes=ey;
	}
	
	Face(Eye* e) : face(Mat()), face_rec(Rect()), center(0){
		std::vector<Eye *> ey;
		ey.push_back(e);
		ey.push_back(e);
		eyes=ey;
	}
	
	Face(const Mat& f, Eye* e1, Eye* e2) : face(f), face_rec(Rect()), center(0){
		std::vector<Eye *> ey;
		ey.push_back(e1);
		ey.push_back(e2);
		eyes=ey;
	}
	
	Face(Eye* e1, Eye* e2) : face(Mat()), face_rec(Rect()), center(0){
		std::vector<Eye *> ey;
		ey.push_back(e1);
		ey.push_back(e2);
		eyes=ey;
	}
	
	
	const Mat& getFace() const {return face;}
	vector<Eye*> getAllEyes() const {return eyes;}
	const Eye* getEye (int ind) const ;
	const Rect& getFaceRec() const {return face_rec;}
	const Point& getCenter() const {return center;}
	void add(Eye* eye);
	
	void setFace(const Mat& f){face=f;}
	void setFace(const Rect& r){face_rec=r;}
	void setAllEyes(const vector<Eye *> e){eyes=e;}
	void setEye(Eye& e, int identif);
	void setCenter(const Point& p){center=p;}
	
	void affiche(int i);

	
};
#endif
