#include <rgb.h>
#include <iostream>

namespace fractal{

	RGB::RGB(double r,double g, double b):r(r),g(g),b(b){}
   
    void RGB::print(){
        std::cout<<"R :"<<r<<" G: "<<g<<" B: "<<b<<"\n";
    }


     RGB linear_interpolation( const RGB& color_start, const RGB& color_end, double alpha ){
        return RGB (    (1-alpha)*color_start.r  + color_end.r * alpha ,
                        (1-alpha)*color_start.g  + color_end.g * alpha ,    
                        (1-alpha)*color_start.b  + color_end.b * alpha 
                     ) ;
    }

    void rgb_test(){
        RGB a( 5.0, 7.0, 8.0 );
        RGB b( 1.0, 1.0, 3.0 );

        auto c0 = linear_interpolation(a,b,0);
        auto c1 = linear_interpolation(a,b,0.1);
        auto c2 = linear_interpolation(a,b,0.5);
        auto c3 = linear_interpolation(a,b,1.0);
        std::cout<<"RGB Test\n";
        c0.print();
        c1.print();
        c2.print();
        c3.print();
    }



    

	
} // end of namespace fractal
