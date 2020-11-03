#include <iostream>
#include <map>

template <typename Map>
void check (const Map& lookup, int const id )
{

	auto its = lookup.equal_range(id);
    for(auto it = its.first; it != its.second; it++) 
	        std::cout << it->first << ": " << it->second << std::endl;
	
}

template <typename Map>
void print (const Map& map )
{
    for (const auto& p : map)
        std::cout<<p.first <<":"<< p.second <<std::endl;
}


int main(){
	std::map< int, std::string> map;
	map.insert(std::make_pair( 30 , "Hamlet"            ));
	map.insert(std::make_pair(  5 , "Othello"           ));
	std::cout<<"Acess by key value "<<map[30]<<"\n";


	std::multimap< int, std::string> lookup;

	lookup.insert(std::make_pair( 30 , "Hamlet"            ));
	lookup.insert(std::make_pair(  5 , "Othello"           ));
	lookup.insert(std::make_pair( 30 , "Richard 3"         ));
	lookup.insert(std::make_pair( 30 , "King Lear"         		 ));
	lookup.insert(std::make_pair( 10 , "Twelfth Night"    		 ));
	lookup.insert(std::make_pair( 10 , "Twelfth Night vol2"      ));
	lookup.insert(std::make_pair( 20 , "Romeo and Juliet"  ));

	for (auto x: lookup){
		std::cout<<x.second<<" " << x.first<<" "<<"\n";
	}
	
	int k = 30;
	std::cout<<"\n\nPlays with rating equal to "<<k<<"\n";
	auto range = lookup.equal_range(30);
	for (auto i = range.first; i!= range.second; ++i){
		std::cout<<i->first << " : "<<i->second<<"\n";
	}

	print(lookup);
	std::cout<<"\n\nPrint 40 iterators\n";
	for (int i=0; i<40; i++){
		// std::cout<<"----"<<i<<"----\n";
		check(lookup, i);
	}



	return 0;
}