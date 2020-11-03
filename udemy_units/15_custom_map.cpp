#include <iostream>
#include <map>
#include <vector>

struct Grade{
 	int math, art, science;
};
std::ostream & operator << (std::ostream &out, const Grade& g)
{
    out <<"Grades : "
    	<< "M: "<< g.math 
    	<< " A: "<< g.art
    	<< " S: "<< g.science;
    return out;
};


class Person{
private:

public:
	std::string name;
	int         age;

	
	Person(): name("JohnDoe"),age(-1){}
	
	Person( std::string name, int age): name(name), age(age){}
	
	Person(const Person &P){
		name = P.name;
		age  = P.age;
	}

	void print() const{
		std::cout<<"Person : "<<name<<" age : "<< age<< std::endl;
	}

	void set_age(int x){
		age = x;
	}
	void set_name(std::string x){
		name = x;
	}

	bool operator < (const Person &other) const{
		if (name == other.name){
			return age<other.age;
		} else{
			return name < other.name;
		}
	}

};

std::ostream & operator << (std::ostream &out, const Person& p)
{
	out<<"Person : "<<p.name<<" age : "<< p.age<< std::endl;
    return out;
};



int main(){
	Person A("Mike", 40);
	Person B(A);
	A.set_name("Peter");
	B.set_age(36);
	A.print();
	B.print();

	std::vector<Person> persons={ Person("Mike",22),
								  Person("Bob",42),
								  Person("Alice",35),
								  Person("Jan",16 )  };
	
	std::map < Person, Grade> grades_map;

	grades_map[Person("Mike",22)]  = {2, 6, 8};
	grades_map[Person("Alice",43)] = {3, 5, 9};
	grades_map[Person("Georg",13)] = {1, 4, 5};
	
	grades_map[Person("Jan",  13)] = {6, 6, 6};
	grades_map[Person("Jan",  16)] = {7, 7, 7};
	grades_map[Person("Jan",  18)] = {8, 8, 8};

	Person p = persons[3];
	std::cout<<"*********\n";
	std::cout<<p;
	std::cout<< grades_map[persons[3]]; 

}