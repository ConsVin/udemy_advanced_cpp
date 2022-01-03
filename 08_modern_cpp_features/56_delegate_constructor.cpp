#include <iostream>
#include <vector>


class Planet{
public:
	long int population;
	std::string name;
	/*No Empty Constuctor here
	Planet(){
		std::cout<<"Parent Empty Consturctor \n";
		population = 100;
		name = "Venus";
	}
	*/
	Planet():Planet("Jupiter", 999){
		std::cout<<"Use Empty Planet Constructor\n";
	}

	Planet (std::string c, long int x):name(c),population(x){
		std::cout<<"Full Consturctor\n";
	}

	Planet (std::string c):name(c){
		population = 42;
		std::cout<<"Consturctor from string\n";
	}

	void print(){
		std::cout<<"Planet "<< name <<" population " << population << "\n";
	}
};

class Earthlike: public Planet{
 public:
	std::vector<std::string> parts ={"Europe", "Asia", "America", "Africa"};
	std::string comment;

	Earthlike(): Planet("Earth_FDDFDFDF"){std::cout<<"Child Consturctor \n";} // Calling Parent Constructor!

	Earthlike (std::string c):Planet("Earth42"){
		comment=c;
		population = 33;
		std::cout<<"Child Consturctor from string\n";
	}

};

int main(){
	Planet Mars;
	Mars.print();
	std::cout<<"---------\n";

	Planet Venus("Venus");
	Venus.print();
	std::cout<<"---------\n";
	Earthlike E;
	E.print();

	std::cout<<"---------\n";
	Earthlike E2("Earth");
	E2.print();




}