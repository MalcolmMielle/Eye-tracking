#ifndef DETECGAZE_HPP
#define DETECGAZE_HPP

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include "Face.hpp"
#include "Environement.hpp"
//#include "Global.hpp"
#include "Filtre.hpp"
#include "FiltreMedian.hpp"
#include "FiltreSobel.hpp"
#include "FiltreHough.hpp"
#include "FiltreInvert.hpp"
#include "FiltreCouleur.hpp"
#include "FiltreElip.hpp"

using namespace std;
using namespace cv;
 
//class Environement;
 
 
class DetecGaze{
	protected : 
	public : 
	void detectPupil(Eye& eye);
};

#endif
