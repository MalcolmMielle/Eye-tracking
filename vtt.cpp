#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <time.h>
#include <cstdlib>
#include "Vecteur.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{
	Vecteur v1;
	BOOST_CHECK_EQUAL(v1.getX().x,0);
	BOOST_CHECK_EQUAL(v1.getX().y,0);
	BOOST_CHECK_EQUAL(v1.getY().x,0);
	BOOST_CHECK_EQUAL(v1.getY().y,0);
	
	Point3i p1;
	Point3i p2(1,1,1);
	Vecteur v2(p1,p2);
	BOOST_CHECK_EQUAL(v2.getX().x,0);
	BOOST_CHECK_EQUAL(v2.getX().y,0);
	BOOST_CHECK_EQUAL(v2.getX().z,0);
	BOOST_CHECK_EQUAL(v2.getY().x,1);
	BOOST_CHECK_EQUAL(v2.getY().y,1);
	BOOST_CHECK_EQUAL(v2.getY().z,1);
	
	v1.setX(p1);
	v1.setY(p2);
	BOOST_CHECK_EQUAL(v1.getX().x,0);
	BOOST_CHECK_EQUAL(v1.getX().y,0);
	BOOST_CHECK_EQUAL(v1.getY().x,1);
	BOOST_CHECK_EQUAL(v1.getY().y,1);
	BOOST_CHECK_EQUAL(v1.getY().z,1);
	
	Vecteur v3;
	v1=v3;
	BOOST_CHECK(v1==v3);
}
