#include <iostream>

class TestClass{
private:
	int pop;
public:
	TestClass(){
		std::cout<<"Default Constuctor\n";
	}
	TestClass(int i):pop(i){
		std::cout<<"Param Constuctor\n";
	}

/*/
	TestClass &operator=(const TestClass &other){
		std::cout<<"Assignment Operator \n";
		return *this;
	}
*/
	
	friend std::ostream &operator<<(std::ostream &out, TestClass &x);
};

std::ostream &operator<<(std::ostream &out, TestClass &x){
	out<<" This is the TestClass with pop=" << x.pop <<"\n";
	return out;
}


int main()
{
	TestClass    P0(333);
	TestClass P_foo(555);

	P_foo = P0;

	std::cout << P0;
	std::cout << P_foo;

	return 0;
}
