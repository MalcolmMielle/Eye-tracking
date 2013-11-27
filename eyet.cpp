#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <time.h>
#include <cstdlib>
#include "Eye.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{
	Eye eye11;
	Eye eye(Mat(), Point(),10, Vecteur());
	BOOST_CHECK_EQUAL(eye.getDirection().getX().x,0);
	BOOST_CHECK_EQUAL(eye.getDirection().getX().y,0);
	BOOST_CHECK_EQUAL(eye.getDirection().getX().z,0);
	BOOST_CHECK_EQUAL(eye.getDirection().getY().x,0);
	BOOST_CHECK_EQUAL(eye.getDirection().getY().y,0);
	BOOST_CHECK_EQUAL(eye.getDirection().getY().z,0);
	BOOST_CHECK_EQUAL(eye11.getDirection().getX().x,0);
	BOOST_CHECK_EQUAL(eye11.getDirection().getX().y,0);
	BOOST_CHECK_EQUAL(eye11.getDirection().getX().z,0);
	BOOST_CHECK_EQUAL(eye11.getDirection().getY().x,0);
	BOOST_CHECK_EQUAL(eye11.getDirection().getY().y,0);
	BOOST_CHECK_EQUAL(eye11.getDirection().getY().z,0);
	
	BOOST_CHECK_EQUAL(eye.getCenter().x,0);
	BOOST_CHECK_EQUAL(eye.getCenter().y,0);
	//BOOST_CHECK_EQUAL(eye.getCenter().z,0);
	BOOST_CHECK_EQUAL(eye.getRadius(),10);
	
	eye.setCenter(Point(1,2));
	BOOST_CHECK_EQUAL(eye.getCenter().x ,1);
	BOOST_CHECK_EQUAL(eye.getCenter().y,2);
	
	eye.setRadius(5);
	BOOST_CHECK_EQUAL(eye.getRadius(),5);
}
