#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

template<typename Container>
void print(std::string header, const Container& cont) {
   std::cout <<header<<" : ";
   for (auto const& x : cont) {
      std::cout << x << " ";
   }
   std::cout << '\n';
}

template<typename Container>
Container intersection(Container &v1,
                       Container &v2){
    Container v3;

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    std::set_intersection(v1.begin(),v1.end(),
                          v2.begin(),v2.end(),
                          back_inserter(v3));
    return v3;
}


int main(){
	std::cout<<"======Begin=======\n";
	
	std::vector<int> vec_a ={2,12,2,13,17,12,10,19};
	std::vector<int> vec_b ={  12,2,   17,12,   19, 43, 56};
	std::vector<int> vec_m;

	print("vec A",vec_a);
	print("vec B",vec_b);
	
	std::merge(vec_a.begin(), vec_a.end(),
			    vec_b.begin(), vec_b.end(),
			    std::back_inserter(vec_m));
	print("vec M",vec_m);

	std::vector<int> vec_int = intersection(vec_a,vec_b );
	print("vec Interesection",vec_int);	

	std::set<int> set_a ={2,12,2,13,17,12,10,19};
	std::set<int> set_b ={  12,2,   17,12,   19, 43, 56};
	
	print("Set A",set_a);
	set_a.merge(set_b);
	print("Set M",set_a);

}

