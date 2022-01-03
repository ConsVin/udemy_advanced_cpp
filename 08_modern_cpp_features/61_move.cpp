
#include <iostream>
#include <vector>
#include <cstring>

class Planet{
	static const int SIZE{10};
	int * _pBuffer{nullptr};
public:
	Planet(){
		std::cout<<"Empty Constor\n";
		_pBuffer= new int[SIZE]{0};
	}

	Planet( int k){
		_pBuffer= new int[SIZE]{0};
		for (int i = 0; i<SIZE; i++){
			_pBuffer[i] = k;
		}
	}

	Planet(const Planet &other){
		_pBuffer = new int[SIZE];
		memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
	}


	Planet &operator=(const Planet &other){
		std::cout<<"Copy Assignment\n";
		_pBuffer = new int[SIZE];
		memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
		return *this;
	}

	Planet &operator=(Planet &&other){
		std::cout<<"Move Assignment\n";
		delete [] _pBuffer;
		_pBuffer = other._pBuffer;
		other._pBuffer = nullptr;
		return *this;
	}

	// Copy Constuctor
	Planet(Planet &&other){
		std::cout<<"Move Constructor\n";
		_pBuffer = other._pBuffer;
		///--------------------------------------------------
		// Yes, it will be safe to delete nullptr in class destructor
		// https://stackoverflow.com/questions/4190703/is-it-safe-to-delete-a-null-pointer
		///--------------------------------------------------
		other._pBuffer = nullptr;
	}

	void print(){
		std::cout<<"[";
		for (int i = 0; i<SIZE; i++){
			std::cout<<_pBuffer[i] <<" ";
		}
		std::cout<<"]\n";
	}

	~Planet(){
		delete[] _pBuffer;
	}


};


Planet get(){
	return Planet(33);
}
int main()
{ 
	Planet A(5);
	Planet B(7);

	A.print();
	B.print();
	A = B;
	A.print();

	std::vector<Planet> vec;
	
	vec.push_back(Planet(1)); // Move Called Here!
	vec.push_back(Planet(2)); // And  Here!
	vec.push_back(Planet(3)); // And  Here!

	for (auto &x: vec){
		x.print();
	}
	std::cout<<"--1-------------\n";
	Planet C = get();
	std::cout<<"--2------------\n";
	Planet D; // <<Empty Constor
	std::cout<<"--3------------\n";
	D  = get();
	
	return 0;
}
