#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>
#include <vector>


int main()
{
    using namespace std::complex_literals;
    using cmpx = std::complex<double>;
    std::cout << std::fixed << std::setprecision(3);
	double pi = M_PI; // cmath

 	
 	cmpx z1,z2;
 	z1 = 3.0 - 2i;
 	std::cout<<z1<<"\n";
	
	std::cout<<"\nBasic arithmetic\n";
	z1 = (3.0 - 2i)*(0.5 + 7i) + (0.5) / 8i;
 	std::cout<<z1<<"\n";
	
	std::cout<<"\nPhase and abs\n";
	z1 = std::exp(     1i * pi/4.0)*10.0;
	z2 = std::polar(  10.0, pi/4.0);
	cmpx diff = z2 - z1;
 	std::cout << pi << std::endl;
 	std::cout << std::setprecision(55)
 			  << z1<<"\n" << z2<<"\n" << diff <<"\n"
 			  << std::setprecision(2);
	
	std::cout<<"\nSplit Imag/Real\n";
	z2 = std::sqrt(2.0) + std::sqrt(7.0)*1i;
	double R = std::real(z2), I = std::imag(z2);
	std::cout << std::setprecision(3)
			  << "C: "<< z2 <<"\tR:" << R  <<"\t I:" << I  <<"\n";
			  
	
	std::vector<cmpx> vec;
	for (int i = 1, r=5; i< 10; i++, r*=1.5 ){
		vec.push_back( cmpx(r,i));
	}

	for (auto x: vec){
		std::cout<<x<<"\n";
	}

	std::cout<<"\nPI:\n";	
	std::cout << std::setprecision(55)<< pi << std::endl;


}