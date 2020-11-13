#include <iostream>
#include <string>
#include <vector>

int main(){
	int value [] = {2,12,85,07};

	class c_student{
	public:
		std::string name;
		int         mark;
		std::string second_name="Doe";
		
		void print(){
			std::cout << name <<" " 
					  << second_name
					  << " : "<< mark<<"\n";
		}
	};

	c_student stud [] = { 	
							{"Bob Bob Bob Bob Bob Bob BobBobBobBob ",2},
							{"Bill",15},
						 	{"Jan",15, "Robbinson"}
						};
						
	auto n_students = sizeof(stud)/sizeof(stud[0]);
	for (int i=0; i<n_students; i++){
		std::cout<<"-----\n";
		std::cout<<sizeof(stud[i])<<"\n";
		stud[i].print();
	}

	struct {
		int x;
		int y;
		void print(){
			std::cout<<"["<<x<<","<<y<<"]\n";
		}
	} point_a ={2,12}, point_b = {25,45};
	std::cout<<"Points:\n";
	point_b.print();
	point_a.print();
		
}