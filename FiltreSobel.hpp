#ifndef FILTRESOBEL_HPP
#define FILTRESOBEL_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "Filtre.hpp"
#include "Environement.hpp"

class FiltreSobel: public Filtre{
	protected : 
	
	public : 

	FiltreSobel() : Filtre() {};
	
	FiltreSobel(int i) : Filtre(i) {};
	~FiltreSobel(){};
	void goFiltre(Mat& img, Mat& gray, Mat& effet);
	
};

#endif
