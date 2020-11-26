#include <string>
#include <iostream>
#include <fstream>

#include <bitmap.h>
#include <bitmapinfo.h>
#include <bitmapfile.h>

namespace fractal{
    Bitmap::Bitmap(int width, int height):
              m_width( width),
             m_height( height),
            m_pPixels( new uint8_t[ width*height*3]{100})
            {}


    bool Bitmap::write(std::string filename){
        BitmapFileHeader fileHeader;
        BitmapInfoHeader infoHeader;

        fileHeader.fileSize =   sizeof( BitmapFileHeader ) 
                              + sizeof( BitmapInfoHeader )
                              + m_width*m_height*3;
        fileHeader.dataOffset = sizeof( BitmapFileHeader ) 
                              + sizeof( BitmapInfoHeader );                                  
        infoHeader.width  = m_width;
        infoHeader.height = m_height;

        std::ofstream file;
        auto mode = std::ios::out|std::ios::binary;
        file.open( filename.c_str(),  mode);
        if (!file){
            return false;            
        }

        file.write((char *)&fileHeader, sizeof(fileHeader));
        file.write((char *)&infoHeader, sizeof(infoHeader));
        file.write((char *)m_pPixels.get(),  m_width*m_height*3); //  Unique to Raw!

        file.close();
        if (!file){
            return false;            
        }
        return true;
    }
    
    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue  ){
        uint8_t *pPixel = m_pPixels.get();
        pPixel += ( y * m_width + x ) * 3;
        pPixel[0] = blue;
        pPixel[1] = red;
        pPixel[2] = green;

        // LittleEndian Format, so inverse order
        //     R  G  B
        //  0x FF 88 33
    }


    Bitmap::~Bitmap(){
    }


}