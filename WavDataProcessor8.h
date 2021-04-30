#ifndef WAV_DATA_PROCESSOR_8
#define WAV_DATA_PROCESSOR_8

#include <fstream>
#include <iostream>

#include "Wav.h"

class WavDataProcessor8 : public Wav{
	unsigned char* buffer = NULL;
public:

	void processData8(std::ifstream &openFile);
	unsigned char* getBuffer8();

	virtual ~WavDataProcessor8();
};

#endif