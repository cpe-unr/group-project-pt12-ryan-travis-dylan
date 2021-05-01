#ifndef WAV_MAIN
#define WAV_MAIN

#include <vector>

#include "WavStructure.h"

class Wav{
protected:
	
    wav_structure wavData;

public:
	//Reading Functions
	void readFile(const std::string &fileName);

    std::vector<std::string> getMetadata();

    unsigned char* getBuffer8();
    short* getBuffer16();

    int getBufferSize();
    int getSampleRate();

    //Writing Functions
    //void writeFile(const std::string &outFileName);
};

#endif