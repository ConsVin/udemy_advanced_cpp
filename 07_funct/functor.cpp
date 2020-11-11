#include <iostream>
#include <string>
#include <vector>

// Abstact Functor
struct Planet
{
	virtual bool operator()(std::string & text) = 0;
	// virtual ~Test(){}
};

// Functor, implementation 
struct Mars: public Planet{
	bool operator()(std::string & text){
		return text == "Mars";
	}
};

// Function uses functor
void check(std::string text, Planet &P)
{	
	std::cout<<"Check text : "<<text<<" => ";
	if (P(text)){
		std::cout<<"Text Matched! :D \n";
	}
	else
	{
		std::cout<<"Not matched  :-( \n";
	}

}



int main(int argc, const char * argv[]){
	Mars m;
	std::string line_a = "Mars";
	std::string line_b = "Marssss";
	std::cout<<"Compare Lines A and B : "<<m(line_a)<< "..."<<m(line_b)<<"\n";

	check("Mars",m);
	check("Venus",m);
	return 0;
}
