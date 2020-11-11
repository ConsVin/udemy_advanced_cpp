#include <iostream>
#include <string>
#include <vector>

template <class T, class A>
class Odysseus{
private:
	T Telemachus;
	A Acusilaus;
public:
	Odysseus(T t, A a){
		this -> Telemachus = t;
		this -> Acusilaus  = a;
	}
	A get_A() const
	{ 
		return Acusilaus;
	}
	T get_T() const
	{ 
		return Telemachus;
	} 
	template <class U, class V>      // all instantiations of this template are my friends
   	friend std::ostream& operator<<( std::ostream&, const Odysseus<U,V>& );

};

//----------------------------------
// Print Hero
//----------------------------------
template <class U, class V>      // all instantiations of this template are my friends
 std::ostream& operator<<( std::ostream& cout, const Odysseus<U,V>& O){
   		cout << "Telemachus:" << O.Telemachus
			 << " | " 
   			 << "Acusilaus:" << O.Acusilaus
			 
			 ;   			 
 		return cout;
 }

//----------------------------------
// Print Vector Containter
//----------------------------------
template <class T>   
std::ostream& operator<<( std::ostream& cout, const std::vector<T>& V){
 		cout<<"[";
 		for (auto x: V)
   		cout << x<<" ";
   		cout<<"]";
 		return cout;
 }

//------------------------
//-- Template Print:
//-------------------------
 template <class T>
 void print (T n){
 	std::cout<< "TemplatePrint: ______ "<< n << "______" << std::endl;
 }
//------------------------
//-- Non-Template Print:
//-------------------------
 void print (int n){
 	std::cout<< "Integer Print: ______ "<< n << "______" << std::endl;
 }




int main (int argc, const char * argv[]){
	Odysseus< std::string, std::string > Hero_01( "Younger Bro" , "Older Bro" );
	std::cout<<"Hero 01: \n"<<Hero_01<<"\n";

	Odysseus< int , double> Hero_02( 92 , 42.5 );
	std::cout<<"Hero 01: \n"<<Hero_02<<"\n";	

	Odysseus< std::vector<int> , std::string> Hero_03( {2,12,85,06} , "String Hero!" );
	std::cout<<"Hero 03: \n"<<Hero_03<<"\n";	

	std::vector<int> vec = {1,2,3};
	
	std::cout<<"\nTemplated Prints:\n";
	print<>( 5);
	print<>( 5.2);
	print( "King Lear");
	print( Hero_03);
	print( vec);

	std::cout<<"\n\n\n";
	std::cout<<"\nDirect Prints:\n";
	print<int>( 5);
	print<>( 5);
	print(5);
	print(5.0);
	print<>("Hamlet!");
	print("Romeo and Juliet");
	


	return 0;
}