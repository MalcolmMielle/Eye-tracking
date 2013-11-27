#ifndef FILTREINVER_HPP
#define FILTREINVER_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "Filtre.hpp"
#include "Environement.hpp"

class FiltreInvert: public Filtre{
	protected : 

	public : 
	FiltreInvert() {};
	~FiltreInvert(){};
	void goFiltre(Mat& img, Mat& gray, Mat& effet);
	
};

#endif
