#include <iostream>
#include <vector>
// @TODO Doesn't work as in Vicdeo

class Planet{
private:
	int pop;
public:
	Planet(){
		std::cout<<"Default Constuctor\n";
	}
	Planet(int i):pop(i){
		std::cout<<"Param Constuctor\n";
	}
	Planet &operator=(const Planet &other){
		this->pop = other.pop;
		return *this;
	}

	~Planet(){ std::cout<<"Object Destructor\n";}

	friend std::ostream &operator<<(std::ostream &out, Planet &x);

};

std::ostream &operator<<(std::ostream &out, Planet &x){
	out<<"This is the planet with pop:=" << x.pop <<"\n";
	return out;
}


Planet getPlanet(){
	return Planet(44);
}

int main()
{

	{	Planet P0(42);
		Planet P_foo(33);
		std::cout<<"#####################\n";
		std::cout<<P_foo;
		std::cout<<P0;
		P_foo = P0;
		std::cout<<P_foo;
		std::cout<<P0;
		std::cout<<"#####################\n";
	
	}
	std::cout<<"===================\n";
	Planet P_boo = getPlanet();
	std::cout<<P_boo;
	std::cout<<"===================\n";

	std::vector<Planet> vec;
	vec.push_back(Planet());
	std::cout<<"===================\n";


	

	return 0;

}
