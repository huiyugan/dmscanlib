/*******************************************************************************
 * ImageProcessor.cpp
 *
 *	Contains methods for handling the decoding of 2d barcodes from images. Mostly
 *	a functionality wrapper around libdmtx which
 ******************************************************************************/

#include "ImageProcessor.h"
#include "Decoder.h"
#include "UaDebug.h"
#include "Dib.h"

#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#ifdef _VISUALC_
// disable fopen warnings
#pragma warning(disable : 4996)
#endif

using namespace std;

ImageProcessor::ImageProcessor()
: image(NULL) {

}

ImageProcessor::~ImageProcessor() {
	if (image != NULL) {
		dmtxImageDestroy(&image);
	}
}

void ImageProcessor::decodeDib(char * filename) {
	UA_ASSERT(filename != NULL);

	Dib * dib = new Dib(filename);
	UA_ASSERT_NOT_NULL(dib);
	Decoder * decoder = new Decoder(dib);

	unsigned numTags = decoder->getNumTags();
	UA_DOUT(3, 1, "tags found: " << numTags);
	for (unsigned i = 0; i < numTags; ++i) {
		UA_DOUT(3, 1, "tag " << i << ": " << decoder->getTag(i));
	}

	delete dib;
	delete decoder;
}
