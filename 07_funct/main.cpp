#include <iostream>
#include <string>
#include <vector>


void f_test(int arg){
	std::cout<<" Argument : " << arg <<"\n";
}

bool match(std::string x, int k){
	return x.size()==k;
}

using vec_str_t = std::vector<std::string>;

int countStrings(vec_str_t  texts, bool (*match)(std::string, int), int K)
{
	int total = 0;
	for (auto s: texts){
		if (match(s,K)){
			total++;
		}
	}
	return total;
}

int main(int argc, const char * argv[]){
	f_test(5);
	void (* pFunctionPointer)(int) = f_test;
	pFunctionPointer(8);

	int K = 3;
	vec_str_t texts={"One","Two","Three","Four","Five","Six","Seven"};
	std::cout<< "COUT: "<< countStrings(texts, match, K)<<"\n";

	return 0;
}