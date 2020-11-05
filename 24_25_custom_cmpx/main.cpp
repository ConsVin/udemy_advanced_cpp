#include <iostream>
#include <complex.h>

int main(){
	common::Complex A(2.0,3.0);
	common::Complex B(2.0,3.0);
	common::Complex C(2.0,3.0);

	C = A*B;
	
	std::cout   <<"Hello world! \n" 
				<< A <<"\n"
				<< A+B  << "\n"
				<< A + 3.0 << "\n"
				<< 4.0 + A <<"\n"
				<< A - B + 4.0  << "\n"
				<< C  << "\n"
				<< ((4.0*C)*A)*0.8  << "\n"
				;
	return 0;
}