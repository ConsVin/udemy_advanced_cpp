#include <iostream>
#include <vector>
#include <cstring>
class Planet{
public:
	int pop;
	int *_pBuffer_a;
	int *_pBuffer_b;
	int *_pBuffer_c;

	static const int SIZE=5;
	

	Planet(){
		std::cout<<"Default Constuctor\n";
		_pBuffer_a= new int[SIZE]{0};
		 memset(_pBuffer_a, 0, sizeof(int)*SIZE);

		// _pBuffer_b= new int[SIZE]{0};
		

	}
	Planet(int i):pop(i){
		std::cout<<"Param Constuctor\n";
		_pBuffer_a= new int[SIZE]{33};
		_pBuffer_b= new int[SIZE];
		// memset(_pBuffer_a, 0, sizeof(int)*SIZE);
		for (int j=0; j<SIZE; j++){
			_pBuffer_a[j]=3*j;
			_pBuffer_b[j]=7*j-3;
		}
	}
	Planet &operator=(const Planet &other){
		_pBuffer_a= new int[SIZE];
		pop = other.pop;

		// Really copy the valud
		memcpy(_pBuffer_a, other._pBuffer_a, SIZE*sizeof(int));
		// Just send the pointer
		_pBuffer_b = other._pBuffer_b;
		

		return *this;
	}

	~Planet(){ 
		std::cout<<"Object Destructor\n";
		delete [] _pBuffer_a;
		delete [] _pBuffer_b;
		// delete [] _pBuffer_c;
			
	}

	friend std::ostream &operator<<(std::ostream &out, Planet &x);

};

std::ostream &operator<<(std::ostream &out, Planet &x){
	out<<"This is the planet with pop:=" << x.pop<<"\n";
	out<<"[";
	for (int i = 0; i < x.SIZE; i++){
	 	out <<*(x._pBuffer_a + i )<<" ";
	}
	out<<"]\n";

	out<<"[";
	for (int i = 0; i < x.SIZE; i++){
	 	out <<*(x._pBuffer_b + i )<<" ";
	}
	out<<"]\n";
	

	return out;
}


Planet getPlanet(){
	return Planet(44);
}

int main()
{
	Planet P_foo(44);
	Planet P_boo(55);

	std::cout<<P_boo<<"\n";
	P_foo = P_boo;
	std::cout<<P_foo<<"\n";
	std::cout<<"Assign 77 to P_foo A and B ";
	
	*(P_foo._pBuffer_a) = 77;
	*(P_foo._pBuffer_b) = 77;
	std::cout<<"Foo: "<< P_foo<<"\n";
	std::cout<<"BOO :"<< P_boo<<"\n";
	
	return 0;

}
