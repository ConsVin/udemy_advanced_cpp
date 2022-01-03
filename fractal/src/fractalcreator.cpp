#include <fractalcreator.h>
#include <iostream>
#include <cassert>

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
        
        auto normal_zoom = Zoom(m_width/2, m_height/2, 4.0/m_width, 2.0/m_height);
        addZoom( normal_zoom );
        auto ne_corner_of_the_lake = Zoom(0.582*m_width , 0.784*m_height, 1/10.0);
        addZoom( ne_corner_of_the_lake);
        setPalette( { clr_orange, clr_blue , clr_yellow, clr_green });
        
        calculateIterations();
        calculateTotalIterations();
        allocatePaletteRanges();
        calculateRangeTotals();
        drawFractal();
        writeBitmap(name);
    }
    

    void FractalCreator::calculateIterations(){
               for (int y=0; y<m_height; y++ ){
                for (int x=0; x<m_width; x++ ){
                    std::pair<double,double> coords = m_zoom_list.doZoom(x,y);
                    auto n_iter = Mandelbrot::getIterations(coords.first, coords.second);
                    m_fractal[ y*m_width + x ] = n_iter;
                    set_m_fractal_iter(x,y, n_iter);
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

    int FractalCreator::get_m_fractal_iter( int x, int y){
        return m_fractal[ y*m_width + x ];        
    }

    void FractalCreator::set_m_fractal_iter( int x, int y, int n_iter){
        m_fractal[ y*m_width + x ] = n_iter;
    }



    void FractalCreator::drawFractal(){
          for (int y=0; y<m_height; y++ ){
            for (int x=0; x<m_width; x++ ){

                int n_iter = get_m_fractal_iter(x,y);
                int range  = getRange(n_iter);

                int rangeTotals = m_ranges_totals[range];
                int rangeStart = m_ranges[range];

                RGB&  color_start = m_rgb[range  ];
                RGB&  color_end   = m_rgb[range+1];
                RGB color_pix(0,0,0); // Default pixel of Mandelbrot set

                double alpha = 0;
                if (n_iter!= Mandelbrot::MAX_ITERATION){
                    int totalPixels = 0;
                    int tic = 0;
                    for (int i=rangeStart; i <= n_iter; i++){
                        totalPixels += m_histogram[i];
                    }
                    alpha = (double)totalPixels / (double)rangeTotals;
                    color_pix = linear_interpolation(color_start, color_end, alpha );
                }
                m_bitmap.setPixel(x,y, color_pix); 
            }
        }
    }

    void FractalCreator::addZoom(const Zoom& zoom){
        m_zoom_list.add(zoom);
    }
    void FractalCreator::setPalette(std::vector<RGB> palette){
        m_palette = palette;
    }

    void FractalCreator::allocatePaletteRanges( ){
        auto n_ranges = m_palette.size();
        auto range_size  = m_total_h / n_ranges;
        int sum = 0;
        int range_cnt = 0;
        for (int i=0; i< Mandelbrot::MAX_ITERATION; i++){
            sum += m_histogram[i];
            if (sum > range_size){
                addRange( i, m_palette[ range_cnt]);
                range_cnt++;
                sum = 0;
            }
        }
        addRange(  Mandelbrot::MAX_ITERATION , m_palette[range_cnt]);
    }

    void FractalCreator::calculateRangeTotals(){
        int rangeIndex = 0;

        for (int i=0; i< Mandelbrot::MAX_ITERATION; i++){
            int pixels = m_histogram[i];
            if (i>= m_ranges[rangeIndex+1]){
                rangeIndex++;
            }
            m_ranges_totals[rangeIndex] += pixels;
        }
    }

    void FractalCreator::addRange(int rangeEnd, const RGB& rgb){
        fprintf(stdout, "Add Range %d \n",rangeEnd);
        m_ranges.push_back( rangeEnd );
        m_rgb.push_back(rgb);
        if (m_bGotFirstRange){
            m_ranges_totals.push_back(0);
        }
        m_bGotFirstRange=true;
    }

    int FractalCreator::getRange( int iters) const{
        int range = 0;

        for (int i=1; i<m_ranges.size(); i++){
            range = i;
            if (m_ranges[i]> iters){
                break;
            }
        }

        range--; // Get zero-based index
        assert(range>-1); 
        assert(range< m_ranges.size());
        return  range;
    }


    void FractalCreator::writeBitmap(std::string name){
        m_bitmap.write(name);
    }

	
} // end of namespace fractal
