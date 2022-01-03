#include <iostream>
#include <vector>
#include <cstring>
class Planet{
public:
	int pop;
	Planet():pop(100000){}
	Planet(int i):pop(i){}
};

Planet getEarth(){ // Return Temporary R value, not L value;
	return Planet(1E9);
}

void check( Planet &x){
	std::cout<<"L Value Function \n";
}
void check( Planet &&x){
	std::cout<<"R Value Function \n";
}

void check( int &&x){
	std::cout<<"R Value Function \n";	
}
void check( int &x){
	std::cout<<"L Value Function \n";	
}


int main()
{ 
	Planet A;
	Planet B(42);
	Planet C =  getEarth();

	Planet *r_pA = &A;
	Planet &r_pD = A;

	// Planet &r_pB = getEarth();<< Not legal
	//Planet *r_pB = getEarth(); << Not legal
	const Planet &r_pC = getEarth(); // Legal!

//	 (CopyConstuctor(  R_VAL))
	Planet Mars(Planet( 0 ) );

	Planet &lTest = Mars;
	//Planet &&rtest = Mars; //Illegal

	//R-Values References
	Planet &&rtest_a = Planet(); //Illegal
	Planet &&rtest_b =getEarth();

	check( lTest      );	// << L
	check( rtest_b    ); 	// << L 
	check( getEarth() );	// << R
	check( Planet()   ); 	// << R 
	std::cout<<"=======\n";
	int x = 42;
	check(x); // L Value
	check(x++); // R Value
	check(++x); // L Value


	std::cout<<"Knock\n";
	
	return 0;
}
