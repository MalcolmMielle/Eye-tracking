#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <time.h>
#include <cstdlib>
#include "DetecFace.hpp"
#include "Environement.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{

	String face = "haarcascade_frontalface_alt.xml";
	String eyes = "haarcascade_eye_tree_eyeglasses.xml";
	Environement env;
	DetecFace df;
	env.add(&df);
	while(1){
		
		env.mainEnv();
		
	}
}
