#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <exception>
#include <stdexcept>

int main(){
	std::ifstream ifile;
	std::string fname = "05_fname.txt";

	ifile.open(fname);
	if (ifile.is_open()){
		std::string  line;
		int k=0;
		while (ifile){
			getline(ifile, line);
			k++;
			std::cout<<("  %10d  ",k)<<"\t" << line <<std::endl;
		}
		ifile.close();
	} else{
		std::cout<<"Bad filename\n" << fname <<"\n";
		throw std::runtime_error("File doesn't exist");
	}
}