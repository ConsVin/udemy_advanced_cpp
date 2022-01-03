#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <exception>
#include <stdexcept>


int main(){

	std::ofstream out_file;

	std::string output_file_name = "05_fname.txt";
	out_file.open(output_file_name);

	if (out_file.is_open() ){
		out_file<< " Hello world! \n";
		out_file<<123<<std::endl;
		
		for (int p=2; p<15; p=p+4){
			out_file.precision(p);\
			out_file<<"Precision set to "<<out_file.precision()<<"\n";
			for (int i=2; i<5; i++){
				out_file<<sqrt(i*1000) <<std::endl;
			}
		}

		out_file<<"END" <<std::endl;
		out_file.close();
		std::cout<<"Check file to see the results: "<<output_file_name<<"\n";
	} else {
		std::cout<<"Bad filename\n";
		throw std::runtime_error("error");
	}
}
