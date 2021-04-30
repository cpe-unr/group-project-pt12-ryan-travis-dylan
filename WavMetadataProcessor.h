#ifndef WAV_METADATA_PROCESSOR
#define WAV_METADATA_PROCESSOR

#include <fstream>
#include <iostream>

class WavMetadataProcessor : public Wav{
protected:
	void processMetadata(ifstream openFile);
};

#endif