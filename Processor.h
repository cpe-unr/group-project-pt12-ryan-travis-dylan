//4/15/2021
//Dylan Judy
//semester project

#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <limits>
#include <cstdint>
#include <cmath>
/**
The templated interface for the mono processor.
*/
template <typename B>
class Processor {
public:
    void processBuffer(B* buffer,int bufferSize)=0;
};


#endif
