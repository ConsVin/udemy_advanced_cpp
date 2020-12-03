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

	RGB linear_interpolation( const RGB& color_start, const RGB& color_end, double alpha);
	void rgb_test();

} // end of namespace fractal
#endif // RGB_H