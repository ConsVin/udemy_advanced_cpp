#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

// #include <fstream>
// #include <string>
// #include <math.h>
// #include <exception>
// #include <stdexcept>

struct gen_rand { 
    float range;
public:
    gen_rand(float r=1.0) : range(r) {}
    float operator()() { 
        return (rand()/(float)RAND_MAX) *range - range/2;
    }
};

int main(){
	int num_items = 2048*8;
	std::vector<float> x(num_items);
	std::generate_n(x.begin(), num_items, gen_rand(1000.0));
	
	long double sum_naive_dbl = 0;
	for (auto i: x){
		sum_naive_dbl += (long  double)i;
	}
	double err = 0;
	err = sum_naive_dbl - sum_naive_dbl;
	printf("%10s %8.10Lf %8.10f \n","Double", sum_naive_dbl, err);


	float sum_naive = 0.0;
	for (auto i: x){
		sum_naive += i;
	}
	err = sum_naive - sum_naive_dbl;
	printf("%10s %8.10f %8.10f \n","Naive", sum_naive, err);
	
	std::sort (x.begin(), x.end(),std::greater<>());  
	float sum_sorted_gr = 0;
	for (auto i: x){
		sum_sorted_gr += i;
	}
	err = sum_sorted_gr - sum_naive_dbl;
	printf("%10s %8.10f %8.10f \n","Sorted D", sum_sorted_gr, err);
	
	std::sort (x.begin(), x.end());  
	float sum_sorted_inv = 0;
	for (auto i: x){
		sum_sorted_inv += i;
	}
	err = sum_sorted_inv - sum_naive_dbl;
	printf("%10s %8.10f %8.10f \n","Sorted U", sum_sorted_inv, err);



}