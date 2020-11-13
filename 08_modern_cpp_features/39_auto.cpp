#include "iostream"
#include "string"
#include "typeinfo"
//------------------------------------------

template <class T, class S>
auto test_a(T value_a, S value_b)->decltype(value_a + value_b)
{
	return value_a + value_b;
}

template <class T, class S>
auto test_b(T value_a, S value_b)
{
	return value_a + value_b;
}


//------------------------------------------

auto get(){
	return 42.0;
}

//------------------------------------------

int main(int argc, const char * argv[]){
	std::cout<<"\n==MAIN==\n";
	auto a = 9;
	auto b = 9.0;
	auto c =  'a';
	auto d = "Hello World";

	auto f0 = 2.0 + 5.0;
	auto f1 = 2   + 5;
	
	std::cout <<"\n"
			  << typeid( a ).name()<<"\n"
			  << typeid( b ).name()<<"\n"
			  << typeid( c ).name()<<"\n"
			  << typeid( d ).name()<<"\n"
			  << typeid( f0 ).name()<<"\n"
			  << typeid( f1 ).name()<<"\n"
  			  << typeid( test_a(5  , 8  ) ).name()<<"\n"
			  << typeid( test_b(5.0, 8.0) ).name()<<"\n"
			  ;
	
	return 0;
}