#ifndef WAV_DATA_PROCESSOR_16
#define WAV_DATA_PROCESSOR_16

#include <fstream>
#include <iostream>

class WavDataProcessor16 : public Wav{
protected:
    void processData16(ifstream openFile, int bufferSize);
    short* getBuffer16();

public:
    virtual ~WavDataProcessor8();
};

#endif