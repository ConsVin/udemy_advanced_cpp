#include <iostream>
#include <map>
#include <vector>

template<typename Container, typename K>
void safe_print(const Container& cont, K key) {
	if ( cont.find(key) != cont.end() ){
		std::cout<<" Name :  " << key <<" ";
		std::cout<< cont.at(key) <<" years";
	} else{
		std::cout<<"Skip "<< key;	
	}
	
	std::cout<<"\n";
}
 

int main(){

    std::vector<int> num(10);

    int n = 1;
    
    
	std::map<std::string,int> ages;

	ages["Bob"]   = 42;
	ages["Alice"] = 43;
	ages["Marco"] = 69;
	ages["Kate"]  = 45;

	ages.insert(std::make_pair("Peter",18));
	std::cout << ages["Bob"] << std::endl;
 	
 	std::string name = "Bob";
 	std::cout << ages[name] << std::endl;
	name = "Bob";
	safe_print(ages,name);

	std::vector<std::string> applicants ={"Alice","Jessy", "Bab", "Marco"};
	for (auto a: applicants){
		safe_print(ages, a);
	}

	for (auto &a: ages)		a.second  = 0;
	
	std::cout<<"\n******\nZeroed map\n******\n";
	for (auto a: ages){
		std::cout<<a.first<<" : "<<a.second<<"\n";
	}

}