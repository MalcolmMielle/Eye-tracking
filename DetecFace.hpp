#ifndef DETECFACE_HPP
#define DETECFACE_HPP

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include "Face.hpp"
#include "Environement.hpp"
//#include "Global.hpp"
#include "Filtre.hpp"
#include "FiltreMedian.hpp"
#include "FiltreSobel.hpp"
#include "FiltreHough.hpp"
#include "FiltreInvert.hpp"
#include "FiltreCouleur.hpp"
#include "DetecGaze.hpp"

using namespace std;
using namespace cv;
 
//class Environement;
 
 
class DetecFace{
	protected :
	String face_cascade_name;
	String eyes_cascade_name;
	CascadeClassifier face_cascade;
	CascadeClassifier eyes_cascade;
	RNG rng;
	
	public : 
	DetecFace() : face_cascade_name ("haarcascade_frontalface_alt.xml"), eyes_cascade_name("haarcascade_eye_tree_eyeglasses.xml") {
		if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); exit(0); };
		std::cout << "PROUT11" << std::endl;
		if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading\n"); exit(0); };
		std::cout << "PROUT22" << std::endl;
	}
	
	DetecFace(const String& face, const String& eyes) : face_cascade_name(face), eyes_cascade_name(eyes), rng(RNG(12345)){
		std::cout << "PROUT " << face_cascade_name <<  std::endl;
		if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); exit(0); };
		std::cout << "PROUT11" << std::endl;
		if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading\n"); exit(0); };
		std::cout << "PROUT22" << std::endl;
	}
	
	
	void detect(Environement& env);
};

#endif
	
	
