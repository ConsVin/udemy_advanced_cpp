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

	friend std::ostream &operator<<(std::ostream&out, const Hero & H) {
	    out << "Hero: "<< H.x << "," << H.name;
        return out;
    }

};

int main(){

	Hero foo(42, "Hercules");
	Hero zak = foo; // Regular assignmnet, not the overloaded
	
	// Hero bar = "HelloWorld";  <<<<  Illegal
	Hero bar; 
	bar =  "Ayax";  // "Overloaded Assignment from string! \n";
	
	zak = bar; //"Overloaded Assignment class to class! \n";
	zak.print();
	bar.print();

	std::cout << "-------\n";
	std::cout <<foo<<"\n"<<bar<<"\n";
}