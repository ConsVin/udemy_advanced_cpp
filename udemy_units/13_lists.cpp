#include <iostream>
#include <list>
#include <stdio.h>
#include <chrono> 
#include <vector> 
#include <iomanip>
#include <iostream>     // std::cout
#include <iterator>     // std::next
#include <list>         // std::list
#include <algorithm>    // std::for_each


template <typename T = std::micro> struct Timer{
  typedef std::chrono::time_point<std::chrono::system_clock> t_clock;
  typedef std::pair<t_clock,std::string> t_markers; 

    std::vector<t_markers> markers;
    Timer(std::string s = "Fancy Timer"){
       markers.push_back(make_pair( std::chrono::system_clock::now(), s  ));
    }
    void tick(std::string s = "NOT_DEFINED")
    {
     markers.push_back(make_pair( std::chrono::system_clock::now(), s  )); 
    }
    void print_all(){
      
      std::cout <<"\n"
                << "*****************************\n"
                <<" Timer " << markers[0].second<< "\n"
                << "*****************************\n"
                << std::setw(20) << "LABEL " 
                << std::setw(20) << "TOTAL"  
                << std::setw(20) << "DIFF"   
                << "\n";
      std::string unit =  ( std::is_same<T, std::micro>::value) ? " us" : " ms" ;

     for (int i = 1; i < markers.size(); ++i){
        std::chrono::duration<double, T> total,diff; 
        total = markers[i].first- markers[0].first;
        diff = markers[i].first- markers[i-1].first;
        std::cout << std::setw(20) << markers[i].second 
                  << std::fixed << std::setprecision(2)
                  << std::setw(20)  << total.count()  << unit
                  << std::setw(20) <<  diff.count() << unit
                  <<  "\n";
      }
    }
};
template<typename Container>
void print(const Container& cont) {
   for (auto const& x : cont) {
      std::cout << x << " ";
   }
   std::cout << '\n';
}



//-------------------------------------------

int main(){


	std::cout<<"TicToc!\n";
    Timer<> timer("List vs Array, fill and array performance");

    std::vector<double> vec;
	std::list<double> num_list;

	int K = 100000;
	for (int i=0; i<K; i++){
		vec.push_back(i*i);
	}
	timer.tick("Vector Fill");
	for (int i=0; i<K; i++){
		num_list.push_back(i*i);
	}
	timer.tick("List fill");


	// while
	// 	auto it1 = std::next(num_list.begin(), i);
	// 	*it1 +=1;
	// }
	// timer.tick("Seq idx List");

	for (int i = 0; i<vec.size(); i+=20){
		vec[i] +=1;
	}
	timer.tick("Seq idx Vec");


	int n = 3;
	for (int i = 0; i<vec.size(); i+=(n-1)){
		vec.erase(vec.begin()+i);
	}
	timer.tick("Vector decimation");

    for (auto it = next(num_list.begin(), 3); it != num_list.end();) {
        it = num_list.erase(it);
        if (it != num_list.end())
            ++it;
    }
	timer.tick("List decimation");
    timer.print_all();

}