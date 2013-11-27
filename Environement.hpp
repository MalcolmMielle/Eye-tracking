#ifndef ENVIRONEMENTVISION_HPP
#define ENVIRONEMENTVISION_HPP
#include "cv.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "Face.hpp"
//#include "Graph.hpp"
#include "Filtre.hpp"
//#include "DetecFace.hpp"

using namespace std;
using namespace cv;

class DetecFace;

class Environement{
	protected : 
	std::vector<Face *> faces;
	DetecFace* detecFace;
	//DetectEye detectEye;
	//DetectGaze detectGaze;
	VideoCapture capture;
	std::vector<Filtre *> filtres;
   	Mat frame1; //image de base
   	Mat effet; //effect
   	Mat gray;
   	int _fin;
   	int _ismultiface;
	
	public : 
	Environement() : capture(VideoCapture(0)) /*Initialise la lecture de la video*/, frame1(Mat::zeros(0,0,CV_8U)), effet(Mat::zeros(0,0,CV_8U)), gray(Mat::zeros(0,0,CV_8U)), _fin(0), _ismultiface(0) {
		if ( !capture.isOpened() ) { //Check if successful
			fprintf( stderr, "ERROR: capture is NULL \n" );
			getchar();
			exit(0);
		}
	}
	
	Environement(int is) : capture(VideoCapture(0)) /*Initialise la lecture de la video*/, frame1(Mat::zeros(0,0,CV_8U)), effet(Mat::zeros(0,0,CV_8U)), gray(Mat::zeros(0,0,CV_8U)), _fin(0), _ismultiface(is) {
		if ( !capture.isOpened() ) { //Check if successful
			fprintf( stderr, "ERROR: capture is NULL \n" );
			getchar();
			exit(0);
		}
	}
	
	~Environement(){
		for(typename std::vector<Face*>::iterator it=faces.begin();it!=faces.end();){
			delete(*it);
			faces.erase(it);
		}
		for(typename std::vector<Filtre*>::iterator it=filtres.begin();it!=filtres.end();){
			delete(*it);
			filtres.erase(it);
		}
	}
	
	void displayImage();
	void Key();
	void filter(); //TO DO
	void mainEnv();
	void add(Face* f);
	void add(Filtre* f);
	void add(DetecFace* f);
	Mat& getImg() {return frame1;}
	Mat& getGra() {return gray;}
	Mat& getEff() {return effet;}
	int getFin(){return _fin;}
	Face* getFace(Face* face);
	void erase(Filtre* p);
	void erase(Face* f);
	void clearFace();
	void clearFiltre();	
	std::vector<Filtre *> getAllFiltre() const{return filtres;};
	std::vector<Face *> getAllFace() const{return faces;};
	
	void afficheFace();
	void afficheEye();
	
	void cleanF();

};

#endif
