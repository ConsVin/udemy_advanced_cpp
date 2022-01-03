#include <iostream>
#include <string>
#include <initializer_list>
#include <typeinfo>

class c_student{
	// private:
	public:
		std::string name = "John";
		int         mark = 5;
		std::string second_name="Doe";

		c_student (std::string n):name(n){};
		c_student() = default;
		// c_student( const c_student &other) = default; //<< Works even comment out this

		// Disable Copy Initialization
		//c_student( const c_student &other) = delete; //<< Works even comment out this
		
		void print(){
			std::cout << name <<" " 
					  << second_name
					  << " : "<< mark<<"\n";
		}
	};

	

int main(){
	c_student signle_stud_a;
	c_student signle_stud_b("Bob");
	c_student signle_stud_c = signle_stud_b; // << Copy Initialization
	signle_stud_c.print();
	
	signle_stud_a.print();
	// c_student signle_stud_d = {"Bob", 52};
	
	//@TODO: Fix https://stackoverflow.com/questions/64823173/c-default-brace-enclosed-initializer-list
	// These initializations works only if I comment consturctors in class definition
	// c_student stud_c  = {"Luke ",420};
	// stud_c.print();
	// c_student stud_d  = {"Mark "};
	// stud_d.print();
		
}