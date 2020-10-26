#include <iostream>
#include <exception>
#include <vector>
#include <memory>
#include <stdlib.h>


//----------------------------------------------
class BadComputer : public std::exception{
public:
	virtual const char *what() const throw(){
		return "** Error: Internal computer is bad :( ";
	}
};

class BoardComputer{
private:
	std::vector<int> data;
public:
	BoardComputer(int K){
		std::cout<<"Construct the computer with K = "<<K<<"\n";
		if (K<20){
			for (int i = 0 ; i++; i<K){
				data.push_back(i);
			}
		} else{
			std::cout<<"Problems in the computer! \n";
			throw BadComputer();
		}
	}
};

//----------------------------------------------
class VeneraException: public std::exception{};

class BadRocket : public VeneraException{
public:
	virtual const char *what() const throw(){
		return "** Error: Spacecraft  goes down  :( ";
	}
};

class BadNavigation: public VeneraException {
public:
	virtual const char * what() const throw(){
		return "** Error: Naviation System Failure :(";
	}
};

class Venera10{
private:
	std::unique_ptr<BoardComputer> computer;
public:
	
	Venera10(int K): computer( new BoardComputer(K)) {}
	
	int LaunchRocket(){
		int random_int;
		srand (time(NULL));
		random_int = (rand() % 10);
		std::cout<<"Rocket lift on ggggrrrr...." << random_int << "\n";
		if ( random_int<5){
			std::cout<<"Bad luck :/ \n";
			throw BadRocket();	
		}

		random_int = (rand() % 10);
		std::cout<<"Set course to Venus...." << random_int << "\n";
		if ( random_int<5){
			std::cout<<"Bad luck :/ \n";
			throw BadNavigation();	
		}
		return 1;
	}
};

//----------------------------------------------

class LaunchException: public std::exception{
public:
	virtual const char * what() const throw(){
		return "**Error: Rocket Launcher exception \n";
	}
};

int launch_mission(int K){
	try {
		Venera10 venera10_spaceship(K);
		return	venera10_spaceship.LaunchRocket();	
	} catch( BadNavigation &e ){
		std::cout<<"Bad Navigation was caught in the launch_mission()!\n";
		std::cout<<e.what()<<"\n";
		return -2;
	} catch ( VeneraException &e ){
		std::cout<<"Some other kind of VeneraException,  but I'll just pass it through \n";
		throw;
	} catch( std::exception &e){
		std::cout<<"Not a Venera exception, throw another exception \n";
		std::cout<<e.what()<<"\n";
		std::cout<<"Throw Launcher exception... \n";
		throw LaunchException();
	}
}

//----------------------------------------------

int main(int argc, char **argv){
	int K = (argc == 2)? strtol(argv[1],NULL,10) : 42;
	int result;
	try{
		result = launch_mission(K);
		std::cout<<"\nMission complteted! \n\n";
	} catch ( std::exception &e ){
		std::cout << "Proceed  exception in the main()\n";
		std::cout << e.what()<< std::endl;
	}
}
