#include <iostream>


int main(){
	int one   =  1;
	int two   = 42;
	int three = 33;

	// Given by value, list of vars
	[two](){std::cout<<":: "<<two <<" Hello world :-)\n";}();

	//Catch All  By Value
	[ =, &three ](){
			std::cout<< one <<"\n";
			// one = 42; << Not Allowed! All variables are given by value
			three  = 89;
		}();
	std::cout << one <<"\n"
			  << three <<"\n";

	std::cout<<"============";
	// Catch All By Reference, but two by value
	[ &, two ](){
			std::cout<< one <<"\n";
			one = 66; // << Allowed, given by reference
			//two = 78; // << Not allowed, captured by value!
			
		}();
	std::cout<< one <<"\n";


}