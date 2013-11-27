#include "FiltreElip.hpp"

void FiltreElip::goFiltre(Mat& img, Mat& gray, Mat& effet){

	Mat work_on;
	if(_image_we_work_on==0){
		equalizeHist( gray, work_on );
	}
	else{
		equalizeHist( effet, work_on );
	}
	int rows=work_on.rows;
	int cols=work_on.cols;
//	std::cout << rows << " rows" << std::endl;
//	std::cout << cols << " cols" << std::endl;
	int trying=0;
	
	for(int i=0;i<rows-_filtre1.rows;i=i+5){
		for(int j=0;j<cols-_filtre1.cols;j=j+5){
			Mat tmp = work_on(Range(i,i+_filtre1.rows), Range(j,j+_filtre1.cols));

			tmp.mul(_filtre1);			
			trying=sum(tmp).val[0];
			
			
			if(_sum1>trying || _sum1==-1){
			//std::cout<<"sum : "<<_sum1 <<" "<< trying << std::endl;
				_sum1=trying;
				_rec1=Rect(j,i,_filtre1.rows,_filtre1.cols);
					
			}
		}
	}
}
