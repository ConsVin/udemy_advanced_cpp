#include <iostream>
#include <string>
#include <vector>

class Parent{
 private:
 	int foo;
 public:
 	int zoo;
 	Parent():foo(0),zoo(33){}
 	Parent(int x):foo(x){}
 	Parent( const Parent &other):foo(0){
 		foo = other.foo;
 		std::cout<<"Copy parent ....!"<<std::endl;
 	}
 	virtual void print(){
 		std::cout<<"Parent with foo : "<<foo<<std::endl;
 	}

 	void how_are_you(){
 		std::cout<<"Non Virtual function, I'm fine! "<<std::endl;
 	}

	// virtual void increment();

 	virtual ~Parent(){}
};

class Child: public Parent {
private:
	int boom;
public:
	Child():boom(42){}

	void print(){
		std::cout<<"This is Child Print with boom "<<boom<<"  zoo: " << zoo <<"\n";
	}

	void increment(){ boom++;};


};

class Child_Beta: public Parent {
private:
	int caradoom;
public:
	Child_Beta():caradoom(33){}
	void increment(){ caradoom++;};
};


int main(){

	Child c1;
	Parent &p1 = c1; 
	Child_Beta cb;

	std::cout<<"p1.print(); >>  "; p1.print();
	std::cout<<"c1.print(); >>  "; c1.print();
	std::cout<<"cb.print(); >>  "; cb.print();

	Parent p2 = Child();
    p2.print();


	return 0;
}
