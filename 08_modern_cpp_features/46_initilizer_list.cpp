#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <typeinfo>

template <class T>
class Philosopher{
public:
	 Philosopher(){
	 	std::cout<< "Im constuctor with no arguments \n"
	 			 << "The greatest wealth is to live content with little\n"
	 			 ;
	 }
	
	

	Philosopher( T a, T b){
		std::cout 	<< "I'm constuctor from pair of T : ";
	}
	 
	 Philosopher( std::initializer_list<T> ideas){
	 	for (auto i: ideas)
	 	{
	 		std::cout << "I say : " << i << "\n" ;
	 	}
	 }
};

int main(){
	Philosopher<int> Plato ;
	Philosopher<std::string> Socrat {"The beginning", "of wisdom", "is a definition","of terms."};
	Philosopher <std::vector<int>> Aristotle ( {1,2,3}, {4,5,6});
	auto x = {1,2,3}; // the type of il is an initializer_list 
	Philosopher <int> Epicurus (x);
}