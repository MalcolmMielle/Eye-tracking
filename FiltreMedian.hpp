#ifndef FILTREMEDIAN_HPP
#define FILTREMEDIAN_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "Filtre.hpp"
#include "Environement.hpp"

class FiltreMedian: public Filtre{
	protected : 
	int _a;
	int _first;
	public : 
	FiltreMedian(int a1)  : Filtre(), _a(a1), _first(0){};
	FiltreMedian(int i, int f, int a1) : Filtre(i), _a(a1), _first(f){};
	~FiltreMedian(){};
	void goFiltre(Mat& img, Mat& gray, Mat& effet);
	
};

#endif
