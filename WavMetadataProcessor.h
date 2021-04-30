#ifndef WAV_METADATA_PROCESSOR
#define WAV_METADATA_PROCESSOR

#include <fstream>
#include <iostream>

#include "Wav.h"

class WavMetadataProcessor : public Wav{
protected:
	void processMetadata(std::ifstream openFile);
};

#endif