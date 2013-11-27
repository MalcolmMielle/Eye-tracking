#ifndef FILTRECOULEUR_HPP
#define FILTRECOULEUR_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "Filtre.hpp"
#include "Environement.hpp"

class FiltreCouleur: public Filtre{
	protected : 
	Scalar _s1;
	Scalar _s2;

	public : 
	FiltreCouleur() : Filtre(), _s1(Scalar(20, 100, 100)), _s2(Scalar(30, 255, 255)) {};
	FiltreCouleur(int a, int b, int c, int d, int e, int f) : Filtre(), _s1(Scalar(a,b,c)), _s2(Scalar(d,e,f)) {};
	~FiltreCouleur(){};
	void goFiltre(Mat& img, Mat& gray, Mat& effet);
	
};

#endif
