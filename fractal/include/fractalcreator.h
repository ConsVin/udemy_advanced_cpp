#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <iostream>
#include <zoom.h>

namespace fractal{

	class FractalCreator{
	public:
		FractalCreator();
		virtual ~FractalCreator();

		void calculateIterations();
		void drawFractal();
		void addZoom(const Zoom& zoom);
		void writeBitmap(std::string name);


	};

} // end of namespace fractal
#endif // FRACTALCREATOR_H