#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <time.h>
#include <cstdlib>
#include "FiltreCouleur.hpp"
#include "FiltreInvert.hpp"
#include "FiltreSobel.hpp"
#include "Environement.hpp"
#include "FiltreLaplace.hpp"
#include "FiltreMedian.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{

	Environement env;
	FiltreInvert ffc;
	FiltreSobel ffs;
	FiltreMedian fm(1,1,200);
	FiltreLaplace fl(1);
	env.add(&fm);
	env.add(&fl);
	BOOST_CHECK_EQUAL(env.getAllFiltre().size(),2);
	
	while(1){
		
		env.mainEnv();
		
	}
}
