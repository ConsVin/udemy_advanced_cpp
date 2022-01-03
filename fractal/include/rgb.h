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

	const auto clr_orange  = RGB( 255,   153,   51  ); // clr_orange
	const auto clr_yellow  = RGB( 255,   255,   51  ); // clr_yellow
	const auto clr_green   = RGB( 153,   255,   51  ); // clr_green
	const auto clr_blue    = RGB(  51,   255,   255 ); // clr_blue

} // end of namespace fractal
#endif // RGB_H
