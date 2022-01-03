#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <vector>
#include <map>

template <typename T> class Series{
private:
	std::vector<T> 			data ;
	std::string    			header ;
public:
	Series(std::vector<T> v, std::string s): data(v),header(s){};
    friend std::ostream &operator<<( std::ostream &output, const Series<T> &D ) { 
        output<< D.header <<" = [";
        for (auto i: D.data ){
            output<<i<<" ";
        }
        output<<"]\n";
        return output;            
    }
};

int main(){
	  Series<int> s({1,2,3,4},"data");
    std::cout<<s<<std::endl;

    std::vector <std::vector <std::string> > data;
    std::ifstream infile( "countries.csv" );

  while (infile)  {
    std::string s;
    if (!std::getline( infile, s )) break;

    std::istringstream ss( s );
    std::vector <std::string> record;
    
    while (ss)      {
        std::string s;
        if (!std::getline( ss, s, ',' )) break;
        record.push_back( s );
      }
      data.push_back( record );
    }

  if (!infile.eof())  {
    std::cerr << "Fooey!\n";
  }
  
  std::vector<int>         vec_pop;
  std::vector<std::string> vec_cntr;

  std::map<std::string , int > table;
  for (auto line:  data){
      std::string country =            line[0] ;
      int             pop = std::stoi( line[1] );
      table[country] = pop;
      vec_pop.push_back(pop);
      vec_cntr.push_back(country);
  }

  std::cout<<"Population of Germany " << table["Germany"]/1E6 << "M people \n";
  std::cout<<"Population of Italy   " << table["Italy"]/1E6 << "M people \n";

  Series<std::string> countries_series(vec_cntr,"Countries ");
  Series<int        > population_series(vec_pop,"Population ");
  
  std::cout<<"Series print";
  std::cout<<countries_series;
  std::cout<<population_series;
}