#ifndef BITMAP_H
#define BITMAP_H
#include <cstdint>

namespace fractal{
	class Bitmap{
	private:
		int m_width{0};
		int m_height{0};
	public:
		Bitmap(int width, int height);
		~Bitmap();
	};
}

#endif /*BITMAP_H*/

