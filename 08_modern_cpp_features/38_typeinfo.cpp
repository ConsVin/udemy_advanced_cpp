#include "iostream"
#include "string"
#include "typeinfo"

class Oedipus{
	private:
		double Jocasta;
	public:
		int Laius;
};

class Dionysus{
		std::string Wine;
};


int main(int argc, const char * argv[]){
	std::cout<<"\n==MAIN==\n";
	
	//-----------------------------------------
	
	double 		     a;
	int    			 b;
	long int    	 c;
	long long int    d;
	char             e;
	std::string      f;

	std::cout <<"\n"
			  << typeid( a ).name()<<"\n"
			  << typeid( b ).name()<<"\n"
			  << typeid( c ).name()<<"\n"
			  << typeid( d ).name()<<"\n"
			  << typeid( e ).name()<<"\n"
			  << typeid( f ).name()<<"\n"
			  ;
	//-----------------------------------------
	
	Dionysus		 		obj_D;
	Oedipus 	     		obj_O;
	decltype(obj_O)  		Anon;
	decltype(obj_O.Laius)  	WhoAreYou;
	
	std::cout <<"\n\n"
			  << typeid( obj_O 		).name()<<"\n"
			  << typeid( obj_D 		).name()<<"\n"
			  << typeid( Anon  		).name()<<"\n"
			  << typeid( WhoAreYou  ).name()<<"\n"
			  ;
	
	//-----------------------------------------
	return 0;
}