#ifndef WAV_MAIN
#define WAV_MAIN

#include <vector>

#include "WavStructure.h"
#include "WavDataProcessor8.h"
#include "WavDataProcessor16.h"

class Wav{
protected:
	wav_structure wavData;

public:
	//Reading Functions
	void readFile(const std::string &fileName);

    std::vector<std::string> getMetadata();

    auto getBuffer();

    int getBufferSize() const;

    //Writing Functions
    //void writeFile(const std::string &outFileName);
};

#endif