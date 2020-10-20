#include <iostream>

int fancy_function(int x){
	if (x > 100){
		throw x*3;
	}
	if (x>5){
		throw "Wow wow so high!";
	}

	std::cout<<"Fancy function end is here!\n";
	return 42;
}

int main(int argc, char** argv){
	int x = (argc == 2)? strtol(argv[1],NULL,10) : 2;

	try{
		fancy_function(x);
	}
	catch(int e) {
		std::cout<<"\n"
				 << "** Error(6324236) Integer Throw, Super High! \n"
				 << "Error code: " << e << "\n"
				 << "\n";
	}
	catch(char const *e) {
		std::cout<<"\n"
				 << "** Error(2482745) String Throw\n"
				 << e << "\n"
				 << "\n";
	}
	std::cout<<"Done :-)\n";
	return 0;
}