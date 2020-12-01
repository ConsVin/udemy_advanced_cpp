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

using namespace fractal;

auto getField(){
    int const m_width  = 1000;
    int const m_height =  800;
    std::unique_ptr<Bitmap>pBitmap {new Bitmap(m_width, m_height)};
    
    for (int y=0; y<m_height; y++ )
        for (int x=0; x<m_width; x++ )
                pBitmap->setPixel(x,y, 0,0,255); 
    for (int i=0; i<500; i++){pBitmap->setPixel(i,i, 255,0,0);    }
    for (int i=0; i<500; i++){pBitmap->setPixel(m_width-i,i, 0,255,0);    }
    return pBitmap;
}

int main(){
    int const m_width  = 1000;
    int const m_height =  500;

    FractalCreator fractal_creator(m_width, m_height);

    fractal_creator.addZoom( Zoom(m_width/2, m_height/2, 4.0/m_width, 2.0/m_height) );
    fractal_creator.addZoom( Zoom(582 , m_height-108, 1/45.0, 1/45.0 ) );
    fractal_creator.calculateIterations();
    fractal_creator.calculateTotalIterations();
    fractal_creator.drawFractal();
    fractal_creator.writeBitmap("mandelbrot.bmp");
	return 0;
}
