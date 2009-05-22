#ifndef __INC_ImageProcessor_h
#define __INC_ImageProcessor_h

#include "dmtx.h"

class ImageProcessor {
public:
	ImageProcessor();
	~ImageProcessor();

	void decodeDib(char * filename);

private:
	DmtxImage* image;
};


#endif /* __INC_ImageProcessor_h */
