
#include <cstdint> // Uint types
#include <vector>
#include <utility> // Pairs
#include <zoom.h>
#include <zoomlist.h>
#include <iostream>

namespace fractal{

		void ZoomList::add (const Zoom& zoom){
			zooms.push_back(zoom);
			m_xCenter += ( zoom.x - m_width/2)*m_scale_x;
			m_yCenter += ( zoom.y - m_height/2)*m_scale_y;
			m_scale_x   *=   zoom.scale_x;
			m_scale_y   *=   zoom.scale_y;
			
			std::cout<< zoom.x    << " , "  << zoom.y << " , " <<  zoom.scale_x << " , " <<  zoom.scale_y << " \n ";
			std::cout<< m_xCenter << " , "  << m_yCenter << " , " <<  m_scale_x << " , " <<  m_scale_y<< " \n ";
		}

		std::pair<double,double> ZoomList::doZoom(int x, int y){
			double xFractal = (x -  m_width/2)*m_scale_x  + m_xCenter;
			double yFractal = (y - m_height/2)*m_scale_y  + m_yCenter;
			return std::pair<double,double>(xFractal, yFractal);
		}
}



