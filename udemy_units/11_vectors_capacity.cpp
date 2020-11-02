#include <iostream>
#include <vector>


int main(){
	std::vector<double> numbers;

	for(int i = 0; i < 66; i++) {
        std::cout<< i << " .."
                 <<"Size :" <<numbers.size()
                 << "   "
		         <<"Capacity :"<<numbers.capacity()<<std::endl;
	    numbers.push_back(i);
	 }
}