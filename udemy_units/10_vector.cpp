#include <iostream>
#include <vector>

int main(){
	std::vector<std::string> strings;

	strings.push_back("Hello");
	strings.push_back("This");
	strings.push_back("is");
	strings.push_back("a");
	strings.push_back("vector");
	strings.push_back("of");
	strings.push_back("strings");

	// Naive indexing
	for (int i=0; i<strings.size(); i++){
		if (i!=0)
			std::cout<<"_";
		std::cout<< strings[i];
	}
	std::cout<<"\n";

	// Auto Iterator indexing
	for (auto s: strings){
		std::cout<< s <<" ";
	}
	std::cout<<"\n";
	
	// Explicit Iterator
    for(   std::vector<std::string>::iterator it = strings.begin();
            it != strings.end(); 
            it++) {
    	int k = std::distance(strings.begin(), it);
        std::cout << k <<" : " << *it <<std::endl;
	}
	std::cout<<"============";

	std::cout<<"\n";
}