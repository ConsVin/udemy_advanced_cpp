#include <iostream>
#include <string>
int glbl_x; // globals

template <class T>
class ring{
	public:
		class iterator;
		double counter_up = 888;

		struct inner{
			T foo;
			void f( T i){
				::glbl_x = i;// Access to Global X
				foo = i*2;
				std::cout << " Number : " << i << "\n" ;
			}

			void jump(ring* p, T i){
				p->counter_up = i*(-1);
			}
		};
};

template <class T>
class ring<T>::iterator{
public:
	void print(){
		std::cout<<"Hello from Iterator 22=> " << std::endl;
	}
};

int main(int argc, const char * argv[]){

	ring<double>        R;
	ring<int>::iterator it;
	ring<double>::inner ayax;


	it.print();
	std::cout<<glbl_x<<"\n";
	ayax.f(42.0);
	std::cout << glbl_x << "\n";
	std::cout << ayax.foo << "\n";
	std::cout<< R.counter_up <<"\n";
	ayax.jump(&R, 33);
	std::cout<< R.counter_up <<"\n";

}