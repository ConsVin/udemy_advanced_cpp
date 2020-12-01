#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <iostream>

#include <iostream>
#include <memory>
#include <cmath>
#include <utility> // Pairs

#include <bitmapfile.h>
#include <bitmapinfo.h>
#include <bitmap.h>
#include <mandelbrot.h>
#include <zoomlist.h>



namespace fractal{

	class FractalCreator{
	private:
		int m_width;
		int m_height;

	    std::unique_ptr<int[]> m_histogram;
	    std::unique_ptr<int[]>   m_fractal;
	    ZoomList m_zoom_list;
		Bitmap        m_bitmap;

		int m_total_h;
		
	public:
		FractalCreator(int w, int h);
		virtual ~FractalCreator();

		void calculateIterations();
		void calculateTotalIterations();
		void drawFractal();
		void addZoom(const Zoom& zoom);
		void writeBitmap(std::string name);


	};

} // end of namespace fractal
#endif // FRACTALCREATOR_H