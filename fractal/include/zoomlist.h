#ifndef ZOOMLIST_H
#define ZOOMLIST_H

#include <cstdint> // Uint types
#include <vector>
#include <utility> // Pairs

#include <zoom.h>

namespace fractal{

	class ZoomList{
	private:
		int    m_width{0};
		int    m_height{0};

		double m_xCenter{ 0 };
		double m_yCenter{ 0 };
		double m_scale_x{ 1.0 };
		double m_scale_y{ 1.0 };
		
		std::vector<Zoom> zooms;
	public:
		ZoomList(int w, int h):m_width(w), m_height(h){};
	
	public:
		void add (const Zoom& zoom);
		std::pair<double,double> doZoom(int x, int y);
	};

} // end of namespace
#endif // ZOOMLIST_H