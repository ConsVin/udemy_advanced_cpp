#include <iostream>


void tester( void (*pFunc)() ){
	std::cout<<"Run Tester ====> ";
	pFunc();
}

int main(){
	
	auto func = [](){std::cout<<"Hi this Lambda :) \n";};
	func(); // Type of this lambda expr may varies widely :)
	tester(func);

	tester( [](){std::cout<<"Some another Lambda! :) \n";} );
}