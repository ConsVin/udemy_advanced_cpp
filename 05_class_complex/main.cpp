#include <iostream>
#include <complex.h>

int main(){
	common::Complex A(2.0,3.0);
	common::Complex B(2.0,3.0);
	common::Complex C(5.0,2.0);

	C = A*B;

	common::Complex X;
	X = 7.0;

	
	std::cout   <<"Hello world! \n" 
				<< A <<"\n"
				<< X <<"\n"
				<< A+B  << "\n"
				<< A + 3.0 << "\n"
				<< 4.0 + A <<"\n"
				<< A - B + 4.0  << "\n"
				<< "Conjugate as dereference:\n"
				<<    C  << "\n"
				<<   *C  << "\n"
				<<  **C  << "\n"
				<< ***C  << "\n"
				<< "Simple Arithmetic:\n"
				<< ((4.0*C)*A)*0.8  << "\n"
				;

	C = (5.0,2.0);			
	A = (C - 4.0) + (C - 4.0);
	B = common::Complex(1.0,2.0)*2.0;
	std::cout<<"Compare "<<A << " and "<< B << "\n";
	if (A==B){
		std::cout<<"So true! \n";
	}

	return 0;
}