#include "DetecFace.hpp"

 
void DetecFace::detect(Environement& env){
	std::vector<Rect> faces;
	Mat gray;
	DetecGaze dg;
	
	equalizeHist( env.getGra(), gray );

	//-- Detect faces
	/*Retourne la liste des visage en un vector de rectangle*/
	face_cascade.detectMultiScale(gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

	for( size_t i = 0; i < faces.size(); i++ )
	{
//		std::cout << "FACES !!"<<std::endl;
		Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
		ellipse( env.getImg(), center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

		Mat faceROI = gray( faces[i] ); //Decoupe l'image		
		
		//Ajoute une nouvelle face dans la liste de l'environnement.
		Face* face = new Face(faceROI, faces[i], center);
		env.add(face);
		//-- In each face, detect eyes
		std::vector<Rect> eyes; //REMOVE THAT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );

		for( size_t j = 0; j < eyes.size(); j++ )
		{
//			std::cout << "Eyes !!"<<std::endl;
			Point center(env.getFace(face)->getFaceRec().x + eyes[j].x + eyes[j].width*0.5, env.getFace(face)->getFaceRec().y + eyes[j].y + eyes[j].height*0.5 );
			int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
			circle( env.getImg(), center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
			
			Mat eyeROI = faceROI(eyes[j]);
			
			Eye* eye = new Eye(eyeROI, eyes[i], center, radius);
			dg.detectPupil(*eye);
			
			/******************************************************************/
			face->add(eye);
			
		}
		
	}
	//-- Show what you got
	//imshow( window_name, frame );
//	std::cout << "bye " << env.getAllFace().size() <<" taille" << std::endl;
}
