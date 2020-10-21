#include <iostream>
#include <vector>
#include <math.h> 
#include <memory>


class JumboClass{
public:
	std::vector<int> vec = {0,1,2,3,4,5};
	JumboClass(long len){
		char *pMemory = new char [len];
		delete [] pMemory;
	}
};
int fancy_function(int x, int idx){
		long len = pow(10,x);
		std::cout <<"Allocate buffer "<<len<<" and try to get from vec[5] element #"<<idx<<"\n";
		std::cout<<"Lets try huge alloc class : "<< len<<"\n";
		JumboClass object(len);
		
		object.vec[0] = 12;		
		for (auto v: object.vec){
			std::cout<<v<<" ";
		}
		std::cout<<"\n";
		object.vec.at(idx) = 43; // Expect exception here
		return 0;
}

int main(int argc, char** argv){
	int x   = (argc >= 2)? strtol(argv[1],NULL,10) :  2;
	int idx = (argc >= 3)? strtol(argv[2],NULL,10) :  2;
	int result;
	


	try{
		result = fancy_function(x,idx);
		std::cout<<"Succesfully finished with no exception :) \n";
	}
	catch (std::bad_alloc &e){
		std::cout<<"Caught exception:: "<< e.what() << "\n";
	}
	catch (std::out_of_range &e){
		std::cout<<"Caught exception:: "<< e.what() << "\n";
	}
	
	
}