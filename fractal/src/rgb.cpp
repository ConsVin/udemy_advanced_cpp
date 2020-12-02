#include <rgb.h>
#include <iostream>

namespace fractal{

	RGB::RGB(double r,double g, double b):r(r),g(g),b(b){}
   
    void RGB::print(){
        std::cout<<"R :"<<r<<" G: "<<g<<" B: "<<b<<"\n";
    }

    RGB operator -(const RGB& first, const RGB& second){
        return RGB(    first.r - second.r,
                       first.g - second.g, 
                       first.b - second.b);
    }

    void rgb_test(){
        RGB a(5.0,7.0,8.0);
        RGB b(1.0,1.0,3.0);
        auto c = a - b;
        a.print();
        b.print();
        c.print();
    }



    

	
} // end of namespace fractal
