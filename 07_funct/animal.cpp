/*


	*** -- Abstact Classes

                 +------------------------------+
         +-------+ ***  ANIMAL - ABSTRACT CLASS +-----+
         |       +------------------------------+     |
         |                                            |
    +----v----------+                  +-------------v-----+
    |      CAT      |                 |       DOG   ***    |
    +---------------+                  +-----------+--------+
                                                    |
                                           +--------+--------+
                                           |  LABRADOR       |
                                           +-----------------+
                                                    |
                                           +--------+--------+
                                           |  NakedLabrador   | 
                                           +-----------------+

*/

#include <iostream>
#include <string>
#include <vector>


class Animal{
public:
	virtual void speak() = 0;
	virtual void   run() = 0;
	virtual void  fur(){
		std::cout<<"I'm so fluffy! \n";
	}
};

class Dog: public Animal
{
public:
	virtual void speak(){
		std::cout<<"Woof!"<<std::endl;
	}
};

class Labrador: public Dog{
public:
    
    Labrador() {
        std::cout << "New labrador ..." << std::endl;
    }
    
    virtual void run(){
        std::cout << "labrador running ..." << std::endl;
    }
};

class NakedLabrador: public Labrador{
public:
	   virtual void fur(){
        std::cout << "I'm naked labrador, have no fur" << std::endl;
    }
};



class Cat: public Animal
{
public:
	virtual void speak(){
		std::cout<<"Meow!"<<std::endl;
	}
	virtual void run(){
		std::cout<<"Cat tic tic tic ..."<<std::endl;
	}

};

void CheckAnimals(Animal &a){
	std::cout<<"run   : "; 	a.run(); 	
	std::cout<<"speak : "; 	a.speak();
	std::cout<<"fur   : "; 	a.fur();
}


int main(int argc, const char * argv[]){
	//------------------------
	// Dog rex;  <<  Error
	//------------------------	
	// cannot declare variable ‘rex’ to be of abstract type ‘Dog’
	// because the following virtual functions are pure within ‘Dog’:
	// 		animal.cpp:23:17: note:     ‘virtual void Animal::run()’
	Cat fluffy;
	Labrador rex;
	NakedLabrador bob;


	fluffy.run();
	rex.run();
	rex.speak();
	
	std::cout<<"\n\n Check Fur methods:\n";
	rex.fur(); // << Use default from Animal
	bob.fur();// << Use from Animal

	std::cout<<"\n\nCheck CheckAnimals:\n";
	std::cout<<"Check Bob:\n";
	CheckAnimals(bob);
	std::cout<<"Check Fluffy:\n";
	CheckAnimals(fluffy);

	Animal *animals[3];
	animals[0] = &fluffy;
	animals[1] = &bob;
	animals[2] = &rex;

	for (auto a: animals){
		std::cout<<"Animals Says:::::\n";
		a->speak();
	}

	return 0;
}
