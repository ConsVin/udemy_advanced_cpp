#include <iostream>
#include <memory>
#include <cmath>
#include <utility> // Pairs

#include <bitmapfile.h>
#include <bitmapinfo.h>
#include <bitmap.h>
#include <mandelbrot.h>
#include <zoomlist.h>
#include <fractalcreator.h>
#include <rgb.h>

using namespace fractal;

int main(){
    int const m_width  = 1000;
    int const m_height =  500;
    FractalCreator fractal_creator(m_width, m_height);
    fractal_creator.run("mandelbrot.bmp");
	return 0;
}
