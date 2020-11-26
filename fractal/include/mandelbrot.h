#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <cstdint> // Uint types

namespace fractal{

	class Mandelbrot{
	private:

	public:
		static const int MAX_ITERATION = 100;

	public:
		static int   getIterations(double x, double y);
		Mandelbrot();
		~Mandelbrot();
	};
}

#endif 
// MANDELBROT_H

