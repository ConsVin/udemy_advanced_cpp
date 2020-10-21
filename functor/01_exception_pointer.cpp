#include <iostream>
#include <memory>

struct MiserlinessClass{
	char  *   pMemory;
	int       memory_len;
	const int max_size = 10;
	MiserlinessClass(int len){
		if (len>max_size){
			std::cout<<"What a lavish lifestyle! Get out of my face! \n";
			std::bad_alloc exception;
 			throw exception;
		}
		pMemory = (char *)malloc(len*sizeof(char));
		memory_len = len;
	}
};


int main(int argc, char** argv){
	int len = (argc==2)? strtol(argv[1],NULL,10): 5;

	std::unique_ptr<MiserlinessClass> objPtr;

	bool allocated = false;
	const int max_cnt = 5;
	int cnt = 0;
	while (!allocated){
		try{
			std::cout<<"Trying to allocate "<<len<<" chars...\n";
			objPtr.reset(new MiserlinessClass(len));
			allocated = true;
		} catch (std::bad_alloc &e){
			len = len >> 1;
			cnt++;
			if (cnt==max_cnt){
				std::cout<<"I give up \n";
				throw  e;
			}
		}
	} 
	std::cout<< "Allocated " << objPtr->memory_len << " chars \n";	
	return 0;
}