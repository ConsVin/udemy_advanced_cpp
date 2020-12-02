#ifndef RGB_H
#define RGB_H

#include <cstdint> // Uint types
#include <vector>
#include <utility> // Pairs


namespace fractal{

	struct RGB{
		double r;
		double g;
		double b;		

		RGB(double r,double g, double b);

		void print();

	};
	
	RGB operator -(const RGB& first, const RGB& second);

	void rgb_test();

} // end of namespace fractal
#endif // RGB_H
