#include "Face.hpp"

void Face::add(Eye* eye){
	eyes.push_back(eye);
}

void Face::setEye(Eye& e, int identif){
	eyes[identif]=&e;
}

const Eye* Face::getEye (int ind) const {
	return eyes[ind];
}

void Face::affiche(int i){
	ostringstream ss;
	String ss2;
	ss<<i;
	ss2=ss.str();
	namedWindow(ss2,1);
	imshow( ss2, face);
	int j=0;
	/*for(typename std::vector<Eye*>::iterator it=eyes.begin();it!=eyes.end();){
		(**it).affiche(j);
		it++;
		j++;
	}*/
}
