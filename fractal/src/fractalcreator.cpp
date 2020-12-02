#include <fractalcreator.h>
#include <iostream>

namespace fractal{

	FractalCreator::FractalCreator(int w, int h):
    m_width(w),
    m_height(h),
    m_histogram(new int[Mandelbrot::MAX_ITERATION + 1]{0} ),
    m_fractal(new int[m_width*m_height]{0} ),
    m_zoom_list(w,h),
    m_bitmap(w,h),
    m_total_h(0)
    {

    }


    void FractalCreator::run(std::string name){
        addZoom( Zoom(m_width/2, m_height/2, 4.0/m_width, 2.0/m_height) );
        addZoom( Zoom(582 , m_height-108,        1/45.0, 1/45.0 ) );
        calculateIterations();
        calculateTotalIterations();
        drawFractal();
        writeBitmap(name);
    }
    

    void FractalCreator::calculateIterations(){
               for (int y=0; y<m_height; y++ ){
                for (int x=0; x<m_width; x++ ){
                    std::pair<double,double> coords = m_zoom_list.doZoom(x,y);
                    auto n_iter = Mandelbrot::getIterations(coords.first, coords.second);
                    m_fractal[ y*m_width + x ] = n_iter;
                    if (n_iter != Mandelbrot::MAX_ITERATION) {
                        m_histogram[n_iter]++;
                    }
                }
            }
    }

    void FractalCreator::calculateTotalIterations(){
        for (int i=0; i<= Mandelbrot::MAX_ITERATION; i++){
            m_total_h+= m_histogram[i];
        }
    }

    void FractalCreator::drawFractal(){
          for (int y=0; y<m_height; y++ ){
            for (int x=0; x<m_width; x++ ){
                int n_iter = m_fractal[ y*m_width + x ];
                
                uint8_t red   = 0;
                uint8_t green = 0;
                uint8_t blue  = 0;

                double hue = 0;
                if (n_iter!= Mandelbrot::MAX_ITERATION){
                    for (int i=0; i<= n_iter; i++){
                        hue += (double)m_histogram[i]/(double)m_total_h;
                        red     = std::pow(250,hue);
                    }
                }
                 
                m_bitmap.setPixel(x,y, red, green , blue); 
            }
        }

    }

    void FractalCreator::addZoom(const Zoom& zoom){
        m_zoom_list.add(zoom);
    }

    void FractalCreator::writeBitmap(std::string name){
        m_bitmap.write(name);
    }

	
} // end of namespace fractal
