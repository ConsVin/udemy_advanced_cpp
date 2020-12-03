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
    // TODO: Add checking of these ranges
    fractal_creator.addRange( 0.0, RGB(200,   0,   0));
    fractal_creator.addRange(0.02, RGB(  0, 150,   0));
    fractal_creator.addRange(0.05, RGB( 200,  0,   255));
    fractal_creator.addRange( 1.0, RGB(  0,   0,  255));
    // fractal_creator.addRange(0.5, RGB(255, 255, 0));
    
    fractal_creator.run("mandelbrot.bmp");

	return 0;
}
