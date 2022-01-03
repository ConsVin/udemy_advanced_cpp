#ifndef BITMAP_H
#define BITMAP_H
#include <cstdint> // Uint types
#include <string>
#include <memory>
#include <rgb.h>

namespace fractal{

	class Bitmap{
	private:
		int m_width{0};
		int m_height{0};
		std::unique_ptr<uint8_t[]>m_pPixels {nullptr};
	public:
		Bitmap(int width, int height);
		
		void setPixel(int x, int y,
						 	uint8_t red,
							uint8_t green, 
							uint8_t blue  );
		void setPixel(int x, int y, RGB & color );

		bool write(std::string filename);

		~Bitmap();
	};
}

#endif /*BITMAP_H*/

