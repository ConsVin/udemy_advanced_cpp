#include <iostream>
#include <vector>
#include <cstring>
class Planet{
public:
	int pop;
	Planet():pop(100000){}
	Planet(int i):pop(i){}
};

Planet getEarth(){
	return Planet(1E9);
}

int main()
{ 
	Planet A;
	Planet B(42);
	
	Planet *pA = &A;
	//Planet *D = getEarth();// Not legal, pointer to function, not the Planet

	int x{100};
	
	int *foo  = &x; // Just reference
	std::cout<<"X : "<< x << " Foo :"<< *foo<<"\n";
	
	int *boo  = &++x; // Allowed, increment X and return pointer to X
	std::cout<<"X : "<< x << " Boo :"<< *boo<<"\n";
	
	// int *zoo  = &x++; << Not allowed! (x++) create temporary copy, can't catch reference to temp
	// int *zoo  = &(x+8); << Also not allowed, 

	return 0;

}
