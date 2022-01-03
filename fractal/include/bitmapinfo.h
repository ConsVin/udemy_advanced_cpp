#ifndef BITMAPINFO_H
#define BITMAPINFO_H

	#include <cstdint>
	#pragma pack(2) // Remove all padding
	// Set bitwidth explicitly
	// int32/64 non standard types
namespace fractal{
	struct BitmapInfoHeader{
		int32_t headerSize{40};
		int32_t width;
		int32_t height;
		
		int16_t planes{1};
		int16_t bitsPerPixel{24};
		
		int32_t compression{0};
		int32_t dataSize{0};
		int32_t horizontalResolution{2400};
		int32_t verticalResolition{2400};
		int32_t colors{0};
		int32_t importantColors{0};
	};
}

#endif
