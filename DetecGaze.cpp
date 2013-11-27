#include "DetecGaze.hpp"

void DetecGaze::detectPupil(Eye& eye){

	Mat gray;
	Mat out;
	/*****************AJOUT DES FILTRES SUR LES YEUX*******************/
//	std::cout << "MEDIAN filtre n° "<< ((eye.getEyeMat().rows+eye.getEyeMat().cols)/2)*10 << std::endl;
	
	eye.add(new FiltreMedian(((eye.getEyeMat().rows+eye.getEyeMat().cols)/2)*100));
	//eye.add(new FiltreInvert()); 
	//eye.add(new FiltreSobel());
	
	/*****************EQUALIZE ?*********************************/
	equalizeHist( eye.getEyeMat(), gray );
	
	/***********************Application du filtre***************************/
	FiltreElip fe(gray.rows*20/100, gray.cols*20/100); //Size = 30%
	fe.goFiltre(gray, gray, out);
	fe.affiche(eye.getEyeMat());
/*	namedWindow("prout",1);
		imshow( "prout",gray );
			waitKey(0); */
}
