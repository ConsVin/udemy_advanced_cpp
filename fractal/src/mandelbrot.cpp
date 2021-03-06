#include <string>
#include <iostream>
#include <fstream>
#include <complex>
#include <mandelbrot.h>

namespace fractal{
    
    Mandelbrot::Mandelbrot(){
    }
    
    int  Mandelbrot::getIterations(double x, double y){
        std::complex<double> z = 0;
        std::complex<double> c(x,y);    
        int n_iter = 0;

        while(n_iter < MAX_ITERATION){
            z = z*z + c;
            if (abs( z ) > 2){
                return n_iter;
            }
            n_iter++;
        }
        return n_iter;
    }

    Mandelbrot::~Mandelbrot(){
    }


}