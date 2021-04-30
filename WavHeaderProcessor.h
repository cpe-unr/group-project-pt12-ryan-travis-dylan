#ifndef WAV_HEADER_PROCESSOR
#define WAV_HEADER_PROCESSOR

#include <fstream>
#include <iostream>

#include "Wav.h"

class WavHeaderProcessor : public Wav{
public:
	void processHeader(std::ifstream openFile);
};

#endif