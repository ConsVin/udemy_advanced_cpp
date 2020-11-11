#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

namespace common{
	// template <typename T>
	class Complex{
		private:
			double real;
			double imag;
		public:
			Complex( double real, double imag);
			Complex();
			
			double getReal() const { return real; }
            double getImag() const { return imag; }

            const Complex &operator=(const Complex &other);
            const Complex &operator=(const double  d     );
            
            bool operator ==(const Complex &other) const;
            bool operator !=(const Complex &other) const;

            // Dereference operator overloaded to Conjugated!
			Complex operator*() const;
	};

	std::ostream &operator<<(std::ostream&out, const Complex &C);

	Complex operator +(const Complex &c1 , const Complex &c2);
	Complex operator +(const Complex &c1 , double d);
	Complex operator +(double d          , const Complex &c2);

	Complex operator -(const Complex &c1 , const Complex &c2);
	Complex operator -(const Complex &c1 , double d);
	Complex operator -(double d          , const Complex &c2);

	Complex operator *(const Complex &c1 , const Complex &c2);
	Complex operator *(const Complex &c1 , double d);
	Complex operator *(double d          , const Complex &c2);

	


}

#endif

