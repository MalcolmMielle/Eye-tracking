#include"FiltreMedian.hpp"

void FiltreMedian::goFiltre(Mat& img, Mat& gray, Mat& effet){
	Filtre::goFiltre(img, gray, effet);
//	 std::cout << "MEDIANISATION"<<std::endl;
	 if(_image_we_work_on==0){
		 for (int i=0;i<_a;i++){
			 medianBlur(gray, effet, 3);
		}
	}
	else{
		Mat tmp;
		if(_first==1){
			effet=gray;
		}
		for (int i=0;i<_a;i++){
			 medianBlur(effet, tmp, 3);
			 effet=tmp;
		}
	}
}
