#include <iostream>


void testGreet(  void (*f)(std::string name)  ){
	f("Sally");
	f("Kate");
	f("Liza");
}

void runArith( double (*pArithFunct)(double a, double b)){
	std::cout << pArithFunct(9.0,(double)3) <<"\n"
			  << pArithFunct(9.0,0.0) <<"\n"
			  ;

}
int main(){

	auto pGreet = [](std::string name ){ std::cout<< "Hello " << name<<"\n";};
	pGreet("Bobby");
	testGreet(pGreet);

	auto pDivide = [](double a, double b)-> double{ 
		if (b==0){
			return 0;
			// return (double)0; << If you don't use -> double
		}
		return a/b;
	};
	auto X = pDivide(10.0, 3.0);
	std::cout<<"Result of pDivide "<<X<<"\n";
	auto X_2 = pDivide(10.0, 0.0);
	std::cout<<"Result of pDivide "<<X_2<<"\n";

	runArith(pDivide);
}