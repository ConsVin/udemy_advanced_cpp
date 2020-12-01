#ifndef ZOOM_H
#define ZOOM_H

#include <cstdint> // Uint types
#include <vector>
#include <utility> // Pairs
namespace fractal{

	struct Zoom{
		int    x{0};
		int    y{0};
		double scale_x{0.0};
		double scale_y{0.0};

		Zoom(int x, int y, double scale_x, double scale_y): 
		x(x),
		y(y),
		scale_x(scale_x),
		scale_y(scale_y)
		{};
	};
}

#endif 
// ZOOM_H

