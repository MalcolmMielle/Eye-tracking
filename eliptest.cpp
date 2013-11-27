#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <time.h>
#include <cstdlib>
#include "FiltreCouleur.hpp"
#include "Environement.hpp"
#include "Face.hpp"
#include "FiltreElip.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{
	Mat img= imread("moi3.jpg");
	if(! img.data )                              // Check for invalid input
	{
		cout <<  "Could not open or find the image" << std::endl ;
	}
	Mat ones = Mat::ones(2,3,CV_8U);
	std::cout << sum(ones) << sum(ones).val[0] <<std::endl;
	
	Mat gray;
	Mat end;
	cvtColor(img, gray, CV_BGR2GRAY);
	
	FiltreElip fe(50,70);
	fe.goFiltre(img,gray,end);
	std::cout << fe.getSum() << std::endl;
	
	fe.affiche(img);
	namedWindow("eyes",1);
	imshow( "eyes", img );
	waitKey(0); 
	
	//Deuxième filtre
	FiltreElip fe2(70,50);
	fe2.goFiltre(img,gray,end);
	
	fe2.affiche(img);
	namedWindow("eyes",1);
	imshow( "eyes", img );
	waitKey(0); 
	//int q=scanf("%d",&q);
	std::cout << "taille : "<< fe2.getRec().x <<" "<<img.cols << std::endl;
		
}
