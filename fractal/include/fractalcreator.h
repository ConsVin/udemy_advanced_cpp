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
#include <rgb.h>


namespace fractal{

	class FractalCreator{
	private:
		int m_width;
		int m_height;
		std::unique_ptr<int[]> m_histogram;
	    int m_total_h;
		std::unique_ptr<int[]>   m_fractal;
	    ZoomList m_zoom_list;
		Bitmap        m_bitmap;
		std::vector<int> m_ranges;
		std::vector<RGB> m_rgb;
		std::vector<int> m_ranges_totals;
		std::vector<RGB> m_palette;
		bool m_bGotFirstRange{false};

	private:
		
		void calculateIterations();
		void calculateTotalIterations();
		void calculateRangeTotals();

		void drawFractal();
		void writeBitmap(std::string name);
		int getRange( int iters) const;
		void setPalette(std::vector<RGB> palette);
		int get_m_fractal_iter(int x, int y);
		void set_m_fractal_iter(int x, int y, int n_iter);
		void allocatePaletteRanges();
	public:
		FractalCreator(int w, int h);
		void addRange(int rangeEnd, const RGB& rgb);
		void addZoom(const Zoom& zoom);
		void run(std::string name);
	};

} // end of namespace fractal
#endif // FRACTALCREATOR_H