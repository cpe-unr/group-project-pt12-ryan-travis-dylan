#ifndef WAV_HEADER_PROCESSOR
#define WAV_HEADER_PROCESSOR

#include <fstream>
#include <iostream>

class WavHeaderProcessor : public Wav{
protected:
	void processHeader(ifstream openFile);
};

#endif