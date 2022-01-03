#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <complex>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <random>


template <typename T> std::string to_str(T & arr){
  std::ostringstream os;
  os << "[";  for (auto x: arr){    os<<" "<< x <<" ";  }  os << "]\n"; 
  return os.str();
}

template <typename T>  std::vector< T > convolution1d( std::vector<T> x, std::vector<T> coeff){
  std::vector<T> y(x.size(),0);
  for (int i=0; i< (x.size()-coeff.size()); ++i){
    for (int j=0; j<coeff.size(); ++j){
      y[i] += coeff[j]*x[i+j];
    }
  }
  return y;
}

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


template <class T> struct FIR { 
    std::vector< T > coeff;  // Array of coefficents is static all the time
    std::list< T > taps;  // Array of taps are shifting each tick
    int order;

    FIR(std::vector< T > v)  
    { 
       coeff = v; 
       order = coeff.size();
       taps = std::list< T > (coeff.size(), 0);
    } 
    void reset(){
       taps = std::list< T > (coeff.size(), 0);
    }
    void append( T  x){
      taps.push_front( x);
      taps.pop_back();
    }

    auto sum_product(){
      T  psum = 0;
      typename   std::list< T >::iterator t;
      typename std::vector< T >::iterator c;
      // Can we do better here?
      for (   c =coeff.begin(),     t  =taps.begin(); 
              c!=coeff.end(),       t !=taps.end();
            ++c             ,     ++t             ){
        psum += (*c) * (*t);
      }
      return psum;
    }
    
    auto operator() ( T  x){
      append(x);
       T  psum = sum_product();
      return psum;
    }

     auto operator() (std::vector< T > x){
     std::vector< T > y( x.size(), 0);
     if (0){
       for (int i = 0; i<x.size(); ++i){
          y[i] =  operator()(x[i]);
       }
     }

    for (int i=0; i< (x.size()-coeff.size()); ++i){
      for (int j=0; j<coeff.size(); ++j){
        y[i] += coeff[j]*x[i+j];
      }
    }

     return y;
     }
}; 
  
int main() 
{ 
    std::vector<double> coeff = {0.0,1.0,5.0, 1.0, 0.0};
    
    FIR<double> fir(coeff); 
    std::cout <<"Coeff: " << to_str(fir.coeff);
    std::cout <<"Taps : "  << to_str(fir.taps);
    
    
    std::cout<<"\nTRANSFORM IN THE LOOP \n";
    std::vector<double> x_array = {0,0,0,1,2,3,4,5,6,13,0,0,0,0,0};
    for (auto x:x_array){
      auto p = fir(x);
      std::cout<<p<<"  ";
    }
    std::cout<<"\n";
    fir.reset();

    std::cout<<"\nTRANSFORM WITH FUNCTOR FOR SCALAR\n";
    std::vector<double> y_array( x_array.size(), 0);
    std::transform(x_array.begin(), x_array.end(), y_array.begin(), fir); 
    std::cout << to_str(y_array);
    fir.reset();

    std::cout<<"\nAPPLY FUNCTOR FOR CONTTAINER \n";
    auto y_2 = fir(x_array);
    std::cout << to_str(y_2);
    fir.reset();

    std::cout<<"\n1D convolution directly \n";
    
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(-10000.0, 10000.0);
    
    Timer<> timer("Init");
    std::vector<double> x_long(200E3,0);
    for (int i=0; i<x_long.size(); i++){
      x_long[i] = dis(gen);
    }
    timer.tick("Random fill");
    
    auto y_3 = convolution1d(x_long,coeff);
    timer.tick("Convolution Calc");

    auto y_4 = fir(x_long);
    timer.tick("FIR Implementation");
        

    timer.print_all();

    fir.reset();
    
    return 0; 
} 