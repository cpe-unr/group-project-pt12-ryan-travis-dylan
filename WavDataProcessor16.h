#ifndef WAV_DATA_PROCESSOR_16
#define WAV_DATA_PROCESSOR_16

#include <fstream>
#include <iostream>

#include "Wav.h"

class WavDataProcessor16 : public Wav{
protected:
    void processData16(std::ifstream openFile);
    short* getBuffer16();

public:
    virtual ~WavDataProcessor16();
};

#endif