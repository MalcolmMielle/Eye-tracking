#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <time.h>
#include <cstdlib>
#include "Environement.hpp"
#include "FiltreSobel.hpp"
#include "DetecFace.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{

	Environement env;
	DetecFace df;
	env.add(&df);

	while(1){
		
		env.mainEnv();
		if (env.getFin()==1){
			break;
		}
		
	}

}
