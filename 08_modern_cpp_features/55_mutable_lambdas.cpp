#include <iostream>

int main(){
	
	int n_cats = 5;
	std::cout<<"Before N cats : "<< n_cats<<"\n";
	
	[n_cats]() mutable{
		n_cats = 42;
		std::cout<<"N cats : "<< n_cats<<"\n";
	}();
	
	std::cout<<"After N cats : "<< n_cats<<"\n";
	

}