#include <iostream>
#include <memory>
#include <cmath>
#include <utility> // Pairs

#include <bitmapfile.h>
#include <bitmapinfo.h>
#include <bitmap.h>
#include <mandelbrot.h>
#include <zoomlist.h>

using namespace fractal;

auto getField(){
    int const WIDTH  = 1000;
    int const HEIGHT =  800;
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

    ZoomList zoom_list(WIDTH,HEIGHT);
    zoom_list.add(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH, 2.0/HEIGHT) );

    zoom_list.add(Zoom(582 , HEIGHT-108, 1/45.0, 1/45.0 ) );

    std::unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATION + 1]{0} );
    std::unique_ptr<int[]>   fractal(new int[WIDTH*HEIGHT]{0} );

    
    Bitmap bitmap(WIDTH,HEIGHT);
    for (int y=0; y<HEIGHT; y++ ){
        for (int x=0; x<WIDTH; x++ ){
            std::pair<double,double> coords = zoom_list.doZoom(x,y);
            auto n_iter = Mandelbrot::getIterations(coords.first, coords.second);
            fractal[ y*WIDTH + x ] = n_iter;
            if (n_iter != Mandelbrot::MAX_ITERATION) {
                histogram[n_iter]++;
            }
        }
    }
    std::cout<<"MIN :" << min << " MAX: "<<max<<"\n";
 
    int total_h =0;
    for (int i=0; i<= Mandelbrot::MAX_ITERATION; i++){
        total_h+= histogram[i];
    }


    for (int y=0; y<HEIGHT; y++ ){
        for (int x=0; x<WIDTH; x++ ){
            int n_iter = fractal[ y*WIDTH + x ];
            uint8_t colour   = (uint8_t)( 240*(double)n_iter/Mandelbrot::MAX_ITERATION) ;

            uint8_t red   = 0;
            uint8_t green = 0;
            uint8_t blue  = 0;


            double hue = 0;
            if (n_iter!= Mandelbrot::MAX_ITERATION){
                for (int i=0; i<= n_iter; i++){
                    hue += (double)histogram[i]/(double)total_h;
                    red     = std::pow(250,hue);
                }
            }
             
            bitmap.setPixel(x,y, red, green , blue); 
        }
    }
    
    
    bitmap.write("mandel.bmp");
    
    if (false){
        int count =0;
        for (int i=0; i<= Mandelbrot::MAX_ITERATION; i++){
            if (!(i%16)) fprintf(stdout, "\t |%4d \n",i);
            fprintf(stdout, "%6d ", histogram[i]);
            count+= histogram[i];
        }
        std::cout<<"\n count :"<< count<<"; Product H*W "<< WIDTH*HEIGHT<<"\n";
    }

	std::cout<<"====Done!\n";
    std::cout<<"\n\n\n";

	return 0;
}
