#ifndef WAV_MAIN
#define WAV_MAIN

#include "WavStructure.h"

class Wav{
	wav_structure wavData;

public:
	//Reading Functions
	void readFile(const std::string &fileName);

    auto getMetadata(std::string param);
    auto getBuffer();

    int getBufferSize() const;

    //Writing Functions
    //void writeFile(const std::string &outFileName);
};

#endif