#include <iostream>
#include <string>
#include <vector>

int main(){
	int value_a = 22;
	int value_b  {33};

	int numbers_a[]={2,12,85,06,2,12,85};
	int numbers_b[]{2,12,85,06,2,12,85};
	
	std::cout<<"================\n";
	int n_b = sizeof(numbers_b)/sizeof(numbers_b[0]);
	for (int i =0; i< n_b; i++){
		std::cout<< i << "/" << n_b-1 << " : "<< numbers_b[i] <<"\n";
	}

	//int *pInts_b = new int[2]{1,2,3}; //Illegal
	std::cout<<"================\n";
	const int K = 7;
	int *pInts_b = new int[K]{1,2,3}; //Legal
	for (int i =0; i< K; i++){
		std::cout<< i << "/" << K-1 << " : "<< pInts_b[i] <<"\n";
	}
	delete [] pInts_b;

	std::cout<<"================\n";
	int value_foo{};
	int value_boo{5};
    std::cout	<< value_foo << "\n" 
				<< value_boo << "\n" 
    			<<std::endl ;
	std::vector<std::string> strings {"one", "two", "three"};
    std::cout << strings[2] << std::endl;
}