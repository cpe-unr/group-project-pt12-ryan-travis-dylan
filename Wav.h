#ifndef WAV_MAIN
#define WAV_MAIN

#include "WavStructure.h"

template <typename B, typename M>
class Wav{
	wav_structure wavData;
	B* buffer = NULL;
public:
	//Reading Functions
	void readFile(const std::string &fileName);

    M getMetadata(const std::string &param);
    B* getBuffer();
    int getBufferSize() const;

    //Writing Functions
    //void writeFile(const std::string &outFileName);
};

#endif