#include <iostream>
#include <exception>

class EndOfTheWorldException : public std::exception {
/*
	const char * is the return type, a pointer to a constant character, by convention the first character of a zero-terminated string array.
	what is the function name
	() is an empty parameter list, indicating that the function takes no arguments
	const qualifies the function, so it can be called on a const object, and can't directly modify the object's members
	throw () is an exception specification which prevents it from throwing any exceptions.
*/
	
public:
	virtual const char * what() const throw (){
		return "** Error: When we are born, we cry that we are come to this great stage of fools";
	}
};


class MarsClass{

public:
	void goesWrong(){
		throw EndOfTheWorldException();
	}
};

int main(){
	std::cout<<"** Info : Many a true word hath been spoken in jest \n";
	MarsClass test;

	try{
		test.goesWrong();
	} catch ( EndOfTheWorldException &e ){
		std::cout << e.what()<< std::endl;
	}
	std::cout <<"Achieved the end! \n";
	return 0;
}