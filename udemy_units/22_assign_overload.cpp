#include <iostream>

class Hero {
private:
	int  		x;
	std::string name;
public:
	Hero():x(42), name("JohnDoe") {};
	Hero(int a, std::string b):x(a), name(b) {};
	
	void print(){
		std::cout<<name<<" : "<<x<<"\n";
	}

	const Hero &operator =(const Hero &other){
		std::cout<<"Overloaded Assignment class to class! \n";
        x    = other.x;
        name = other.name;
        return *this;
	}

	const Hero &operator =(const std::string N){
		std::cout<<"Overloaded Assignment from string! \n";
        x    = 777;
        name = N;
        return *this;
	}

};

int main(){

	Hero foo(42, "Herculer");
	Hero bar(12, "Ayax");
	Hero zak = foo; // No overloading here
	bar = "HelloWorld";
	foo.print();
	bar.print();
	zak = bar;
	zak.print();
}