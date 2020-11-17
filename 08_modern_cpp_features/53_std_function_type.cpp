#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

bool f_check(std::string &x){
	return x.size()== 5;
}

class Checker{
public:
	int K = 2;
	bool operator()(std::string &x){
		return x.size() == K;
	}
} some_weired_name;

void gatekeeper(std::function<bool(std::string&)> check){
	std::string x = "dog";
	std::cout<<"Feed recieved function with \""<< x << "\" Result : "<<check(x)<<"\n";
}

int main(){
	std::vector<std::string> vec {"Hello", "brave", "new", "world","two","_seven_"};
	
	int def_size = 3;
	auto n_three  = count_if(vec.begin(), vec.end(), [def_size](std::string x){return x.size()==def_size;});
	std::cout<<"Result "<<n_three<<"\n";

	std::cout<<"Five length :: "<< count_if(vec.begin(), vec.end(), f_check)<<"\n";

	std::cout<<"Five length :: "<< count_if(vec.begin(), vec.end(), some_weired_name)<<"\n";
	
	Checker Seven={7};
	std::cout<<"Seven length :: "<< count_if(vec.begin(), vec.end(), Seven)<<"\n";

	auto my_lambda =  [def_size](std::string x){return x.size() == def_size;};
	std::cout<<"# Result "<<count_if(vec.begin(), vec.end(),my_lambda)<<"\n";
	gatekeeper(my_lambda);
	gatekeeper(f_check);

	std::function<int(int,int)> add = [](int one, int two){return one+two;};
	std::cout<<add(4,3);
	return 0;	
}