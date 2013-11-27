#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <time.h>
#include <cstdlib>
#include "Point3D.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{
	Point3D p1;
	BOOST_CHECK_EQUAL(p1.getX(),0);
	BOOST_CHECK_EQUAL(p1.getY(),0);
	BOOST_CHECK_EQUAL(p1.getZ(),0);
	
	Point3D p2(0,2,1);
	BOOST_CHECK_EQUAL(p2.getX(),0);
	BOOST_CHECK_EQUAL(p2.getY(),2);
	BOOST_CHECK_EQUAL(p2.getZ(),1);
	
	p1.setX(4);
	p1.setY(3);
	p1.setZ(2);
	BOOST_CHECK_EQUAL(p1.getX(),4);
	BOOST_CHECK_EQUAL(p1.getY(),3);
	BOOST_CHECK_EQUAL(p1.getZ(),2);
	
	AddP add;
	Point3D p3=add(p1,p2);
	BOOST_CHECK_EQUAL(p3.getX(),4);
	BOOST_CHECK_EQUAL(p3.getY(),5);
	BOOST_CHECK_EQUAL(p3.getZ(),3);
	
	p3=p1;
	BOOST_CHECK_EQUAL(p3.getX(),4);
	BOOST_CHECK_EQUAL(p3.getY(),3);
	BOOST_CHECK_EQUAL(p3.getZ(),2);
	BOOST_CHECK(p3==p1);
	
	p3.move(1,1,1);
	BOOST_CHECK_EQUAL(p3.getX(),5);
	BOOST_CHECK_EQUAL(p3.getY(),4);
	BOOST_CHECK_EQUAL(p3.getZ(),3);
}
