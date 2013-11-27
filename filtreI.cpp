#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <time.h>
#include <cstdlib>
#include "FiltreInvert.hpp"
#include "Environement.hpp"
#include "Face.hpp"
#include "DetecFace.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{

	Environement env;
	FiltreInvert ffs;
	env.add(&ffs);
	DetecFace df;
	env.add(&df);
	BOOST_CHECK_EQUAL(env.getAllFiltre().size(),1);

	while(1){
		
		env.mainEnv();
		
	}
}
