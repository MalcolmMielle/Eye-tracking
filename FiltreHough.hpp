#ifndef FILTREHOUGH_HPP
#define FILTREHOUGH_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "Filtre.hpp"

class FiltreHough: public Filtre{
	protected : 
	
	public : 
	FiltreHough() {};
	~FiltreHough(){};
	void goFiltre(Mat& img, Mat& gray, Mat& effet);
	
};

#endif
