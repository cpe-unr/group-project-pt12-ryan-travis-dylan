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

    template <typename B>
    B* getBuffer();

    int getBufferSize() const;

    //Writing Functions
    //void writeFile(const std::string &outFileName);
};

B* Wav::getBuffer(){
    if(wavData.sample_rate == 8){

        WavDataProcessor8* data = new WavDataProcessor8();
        unsigned char* buffer = data->getBuffer8();
        delete[] data;
        return buffer;
    }

    if(wavData.sample_rate == 16){

        WavDataProcessor16* data = new WavDataProcessor16();
        short* buffer = data->getBuffer16();
        delete[] data;
        return buffer;

    }
}

#endif