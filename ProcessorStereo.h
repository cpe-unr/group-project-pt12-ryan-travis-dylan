//4/15/2021
//Dylan Judy
//semester project

#ifndef PROCESSOR_STEREO_H
#define PROCESSOR_STEREO_H

#include <limits>
#include <cstdint>
#include <cmath>
template <typename BS>
class ProcessorStereo{
public:
    void processBufferStereo(BS* buffer,int bufferSize);
};


#endif
