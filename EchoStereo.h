//4/15/2021
//Dylan Judy
//semester project

#ifndef ECHO_STEREO_H
#define ECHO_STEREO_H

#include "ProcessorStereo.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <cmath>

template <typename BS>
class EchoStereo: public ProcessorStereo<BS>{
int delay;
public:
	EchoStereo(int delay);
   	void processBufferStereo(BS* buffer,int bufferSize);
};
template <typename BS>EchoStereo<BS>::EchoStereo(int delay): delay(delay){}
template <typename BS>void EchoStereo<BS>::processBufferStereo(BS* buffer, int bufferSize){
int i;
	for(i=0; i<bufferSize; i++){
		buffer[i] = buffer[i-delay]/3 + buffer[i];
	}
}
#endif
