#include <iostream>
#include <bitmapfile.h>
#include <bitmapinfo.h>
#include <bitmap.h>
#include <mandelbrot.h>


using namespace fractal;

auto getField(){
    int const WIDTH  = 800;
    int const HEIGHT = 600;
    std::unique_ptr<Bitmap>pBitmap {new Bitmap(WIDTH, HEIGHT)};
    
    for (int y=0; y<HEIGHT; y++ )
        for (int x=0; x<WIDTH; x++ )
                pBitmap->setPixel(x,y, 0,0,255); 
    for (int i=0; i<500; i++){pBitmap->setPixel(i,i, 255,0,0);    }
    for (int i=0; i<500; i++){pBitmap->setPixel(WIDTH-i,i, 0,255,0);    }
    return pBitmap;
}

int main(){

    auto pBitmap = getField();
    pBitmap->write("field.bmp");

    int const WIDTH  = 1000;
    int const HEIGHT =  500;
    double min =  99999;
    double max = -90999;
    
    Bitmap bitmap(WIDTH,HEIGHT);
    for (int y=0; y<HEIGHT; y++ ){
        for (int x=0; x<WIDTH; x++ ){
            double xFractal = (x -  WIDTH/2.0 -  WIDTH/4.0) * (4.0/WIDTH);
            double yFractal = (y - HEIGHT/2) * (2.0/HEIGHT);
            if (xFractal<min)   min  = xFractal;
            if (xFractal>max)   max  = xFractal;
            auto p = Mandelbrot::getIterations(xFractal, yFractal);
            bitmap.setPixel(x,y, p,p/2,p); 
        }
    }
    bitmap.write("mandel.bmp");


    std::cout<<"MIN :" << min << " MAX: "<<max<<"\n";

	std::cout<<"====Done!\n";
    std::cout<<"\n\n\n";

	return 0;
}
