#include "iostream"
#include "string"
#include "vector"


int main(int argc, const char * argv[]){

	std::vector<int> vec_i = {1,2,3};
	std::vector<std::vector<int>> mat ={
										  {1,2,3},
										  {21,22,33},
										  {21,22,33,34,45},
										  {2}
										};
	std::cout<<"=====Vector of Vectors=====\n";
	for (auto v: mat){
		std::cout<<"---\n";
		for (auto i: v){
			std::cout<< i << ' ';
		}
		std::cout<<"\n";
	}
	
	std::cout<<"=====String=====\n";
	std::string hello="Hello hello how low";
	for (auto c: hello){
			std::cout<<c<<"_";
	}
	std::cout<<"\n\n";

	std::cout<<"=====Vector of Strings=====\n";
	std::vector<std::string> slist={"Hello","World","Another String"};
	for (auto c: slist){
			std::cout<<"_"<<c<<"_\n";
	}
	std::cout<<"\n";


}
