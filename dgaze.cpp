#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <time.h>
#include <cstdlib>
#include "FiltreCouleur.hpp"
#include "Environement.hpp"
#include "Face.hpp"
#include "FiltreElip.hpp"
#include "DetecFace.hpp"
#include "DetecGaze.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{
	Environement env(0);
	DetecFace df;
	env.add(&df);
	while(1){
		
		env.mainEnv();
		if (env.getFin()==1){
			break;
		}
		
	}
	
	/***********************Test avec une photo****************************
	
	Mat img= imread("tout.jpg");
	if(! img.data )                              // Check for invalid input
	{
		cout <<  "Could not open or find the image" << std::endl ;
	}
	Mat gray;
	cvtColor(img, gray, CV_BGR2GRAY); //Conversion
	std::vector<Rect> faces;

	DetecGaze dg;
	/**************************************************
	String face_cascade_name="haarcascade_frontalface_alt.xml";
	String eyes_cascade_name="haarcascade_eye_tree_eyeglasses.xml";
	CascadeClassifier face_cascade;
	CascadeClassifier eyes_cascade;
	
	
	if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); exit(0); };
		std::cout << "PROUT11" << std::endl;
	if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading\n"); exit(0); };
		std::cout << "PROUT22" << std::endl;
	/*************************************************
	
	equalizeHist( gray, gray );
	namedWindow("eyes22",1);
	imshow( "eyes22", gray );
	waitKey(0);
	//-- Detect faces
	//*Retourne la liste des visage en un vector de rectangle
	face_cascade.detectMultiScale(gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

	for( size_t i = 0; i < faces.size(); i++ )
	{
		std::cout << "FACES !!"<<std::endl;
		Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
		ellipse( img, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

		Mat faceROI = gray( faces[i] ); //Decoupe l'image		
		
		//Ajoute une nouvelle face dans la liste de l'environnement.
		//Face* face = new Face(faceROI, faces[i], center);

		//-- In each face, detect eyes
		std::vector<Rect> eyes; //REMOVE THAT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );
		//namedWindow("face",1);
		//imshow( "face", faceROI );
		//waitKey(0); 
		
		for( size_t j = 0; j < eyes.size(); j++ )
		{
			std::cout << "Eyes !!"<<std::endl;
			Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5 );
			int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
			circle( img, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
			
			Mat eyeROI = faceROI(eyes[j]);
			
			Eye* eye = new Eye(eyeROI, eyes[i], center, radius);
			dg.detectPupil(*eye);
			namedWindow("eyes",1);
			imshow( "eyes", eyeROI );
			waitKey(0); 
			/******************************************************************
			
			
		}
		
	}
	namedWindow("eyes22",1);
	imshow( "eyes22", img );
	waitKey(0);
		*/

}
