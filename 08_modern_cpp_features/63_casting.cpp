#include <iostream>
#include <vector>
#include <cstring>

class Parent{
public:
	int pop {0};
};


class Mars: public Parent{
public:
	int mars_value{33};
	Mars(){
		mars_value = 78;
		pop       = 66;
	}
	Mars(const Parent &other){
		std::cout<<"Constructor from Parent\n";
		mars_value = 123;
		pop        = 55;
	}
	
};

class Venus: public Parent{
public:
	int venus_value{43};
};


int main()
{ 
	Parent Daddy;
	Mars M;
	Venus V;

	double value_a =  3.99;
	double value_b = -3.99;
	
	//------------------------------
	//C-like static Cast
	//------------------------------
	std::cout << static_cast<int>(value_a)<<"\n"
			 << static_cast<int>(value_b)<<"\n";
	//------------------------------
	Parent *pp = &M;
	
	// Unsafe
	Mars *pm = static_cast<Mars *>(&Daddy);
	std::cout<< pm->mars_value<<" << Some shit here \n";


	//casting.cpp:53:13: error: cannot ‘dynamic_cast’ ‘& Daddy’ (of type ‘class Parent*’) 
	// to type ‘class Mars*’ (source type is not polymorphic)
	// Mars *dm = dynamic_cast<Mars *>(&Daddy); 
//	std::cout<< dm->mars_value<<" << Some shit here \n";


	Mars m2(Daddy);

	Parent *ppp = & M;
	Mars   *pbb = &M;

	// Static Cast - compile things
	
	return 0;
}
