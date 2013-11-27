#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <time.h>
#include <cstdlib>
#include "Face.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{
	Face face;
	BOOST_CHECK_EQUAL(face.getAllEyes()[1]->getCenter().x,0);
	BOOST_CHECK_EQUAL(face.getAllEyes()[1]->getCenter().y,0);
	BOOST_CHECK_EQUAL(face.getAllEyes()[2]->getCenter().x,0);
	BOOST_CHECK_EQUAL(face.getAllEyes()[2]->getCenter().y,0);
	BOOST_CHECK_EQUAL(face.getEye(1)->getCenter().x,0);
	BOOST_CHECK_EQUAL(face.getEye(1)->getCenter().y,0);
	
	Eye eye(Point(2,1), 10);
	Face face2(&eye);
	BOOST_CHECK_EQUAL(face2.getAllEyes()[1]->getCenter().x,2);
	BOOST_CHECK_EQUAL(face2.getAllEyes()[1]->getCenter().y,1);
	BOOST_CHECK_EQUAL(face2.getAllEyes()[0]->getCenter().x,2);
	BOOST_CHECK_EQUAL(face2.getAllEyes()[0]->getCenter().y,1);
	
	Eye eye2;
	Face face3(&eye, &eye2);
	BOOST_CHECK_EQUAL(face3.getAllEyes()[0]->getCenter().x,2);
	BOOST_CHECK_EQUAL(face3.getAllEyes()[0]->getCenter().y,1);
	BOOST_CHECK_EQUAL(face3.getAllEyes()[1]->getCenter().x,0);
	BOOST_CHECK_EQUAL(face3.getAllEyes()[1]->getCenter().y,0);

	
	Eye eye3(10,10, 0);
	face3.setEye(eye3, 1);
	BOOST_CHECK_EQUAL(face3.getAllEyes()[1]->getCenter().x,10);
	BOOST_CHECK_EQUAL(face3.getAllEyes()[1]->getCenter().y,10);
	
	
	
}
