#include "Environement.hpp"
#include "DetecFace.hpp"


void Environement::Key(){
	//if ( (cvWaitKey(10) & 255) == 27 ){
	
	char c= cvWaitKey(1);
	switch(c){
		case 'c' : 
			cleanF();
			break;
		case 27 : 
			destroyWindow( "mywindow" );
		//CE DEMERDER POUR APPELLER LES DESTRUCTEURS : flag ?	
			_fin=1;	
			break;	
		//exit(0);
		
		
	}
}

void Environement::displayImage(){	
	namedWindow("effet",1);
	imshow( "effet", effet );

	namedWindow("frame1",1);
	imshow("frame1", frame1);

	namedWindow("gray",1);
	imshow( "gray", gray );
}

void Environement::filter(){ 
	for(typename std::vector<Filtre*>::iterator it=filtres.begin();it!=filtres.end();){	
		(**it).goFiltre(frame1, gray, effet);	
		it++;
	}
}

void Environement::mainEnv(){
	//Skip some images :
	for (int i =0; i<1;i++)
	{ 
		capture.grab();
	}
	
	//Initialisation images
	capture >> frame1;
	cvtColor(frame1, gray, CV_BGR2GRAY); //Conversion
	effet=Mat::zeros(1,1,CV_64F);
	
	//Traitement
//	std::cout<< "filtrage"<<std::endl;
	filter();
//	std::cout << "predisplay" << std::endl;
	
	//Detection des yeux et visages
	detecFace->detect(*this);
	
	//Diplay
	/***************First destroy EVERYTHING ******************/
	//destroyAllWindows();
	
	/****************Then, dislay EVERYTHING ******************/
//	displayImage();
	afficheFace();
//	std::cout << "postdisplay" << std::endl;
	
	//Clavier
	Key();
	
	//Clean des buffer de visages
	clearFace();
}

void Environement::add(Face* f){
//	std::cout << "Add a face "<< std::endl;
	faces.push_back(f);
}

void Environement::add(Filtre* f){
	filtres.push_back(f);
}

void Environement::add(DetecFace* f){
	detecFace=f;
}


Face* Environement::getFace(Face* face){
	for(typename std::vector<Face*>::iterator it=faces.begin();it!=faces.end();){
		if((*it)==face){
			return *it;
		}
		it++;
	}
	return NULL;
}


void Environement::erase(Filtre* p){
//Met les element en fin de liste (remove_if) puis les supprime (erase)
	for(typename std::vector<Filtre*>::iterator it=filtres.begin();it!=filtres.end();){
		if(*it==p){
			delete(*it);
			filtres.erase(it);
		}
		else{
			it++;
		}
	}
}

void Environement::clearFiltre(){
	for(typename std::vector<Filtre*>::iterator it=filtres.begin();it!=filtres.end();){
		delete(*it);
		filtres.erase(it);
	}
}

void Environement::clearFace(){
	for(typename std::vector<Face*>::iterator it=faces.begin();it!=faces.end();){
		delete(*it);
		faces.erase(it);
	}
}

void Environement::afficheFace(){
	int i=0;
//	std::cout << "Bonjour " << faces.size() <<" taille" << std::endl;
	if(_ismultiface==1){
		for(typename std::vector<Face*>::iterator it=faces.begin();it!=faces.end();){
			(**it).affiche(i);
			i++;
			it++;
		}
	}
	else if(!faces.empty()){
		typename std::vector<Face*>::iterator it=faces.begin();
		(**it).affiche(i);
	}
}

void Environement::cleanF(){
	destroyAllWindows();
}

