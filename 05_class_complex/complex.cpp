#include "complex.h"

namespace common{
	Complex::Complex(): real(0), imag(0) {}
	Complex::Complex(double real, double imag): real(real), imag(imag) {}

	bool Complex::operator ==(const Complex &other) const{
		return (real == other.real)&&(imag == other.imag);
	}
	bool Complex::operator !=(const Complex &other) const{
		return !(*this == other);
	}


	std::ostream &operator<<(std::ostream &out, const Complex &C) {
	    out << "("<<C.getReal() <<","<<C.getImag()<<")";
        return out;
    }

    // Summation
    Complex operator +(const Complex &c1 , const Complex &c2){
    	return Complex(c1.getReal() + c2.getReal(), c1.getImag() + c2.getImag() );
    }
	Complex operator +(const Complex &c1 , double d){
		return Complex(c1.getReal() + d, c1.getImag());
	}
	Complex operator +(double d          , const Complex &c1){
		return Complex(c1.getReal() + d, c1.getImag());	
	}


	// Substraction
	Complex operator -(const Complex &c1 , const Complex &c2){
    	return Complex(c1.getReal() - c2.getReal(), c1.getImag() - c2.getImag() );
    }
	Complex operator -(const Complex &c1 , double d){
		return Complex(c1.getReal() - d, c1.getImag());
	}
	Complex operator -(double d          , const Complex &c1){
		return Complex(c1.getReal() - d, c1.getImag());	
	}


	// Multiplication
	Complex operator *(const Complex &c1 , const Complex &c2){
		double R = c1.getReal()*c2.getReal()  - c1.getImag()*c2.getImag();
		double I = c1.getReal()*c2.getImag()  + c1.getImag()*c2.getReal();
    	return Complex( R, I );
    }
	Complex operator *(const Complex &c1 , double d){
		return Complex(c1.getReal() * d, c1.getImag()*d);
	}
	Complex operator *(double d          , const Complex &c1){
		return Complex(c1.getReal() * d, c1.getImag() *d );	
	}

	// !!! Note that derefernce opeator differ from Mult Operator!!!!
	Complex Complex::operator*() const
	{
		return Complex(real, -imag);
	}


    const Complex &Complex::operator=(const Complex &other) {
        real  = other.real;
        imag  = other.imag;
        return *this;
    }

	 const Complex &Complex::operator=(const double d) {
	        real  = d;
	        imag  = 0.0;
	        return *this;
	    }
 

    

}
