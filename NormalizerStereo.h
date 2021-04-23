//4/15/2021
//Dylan Judy
//semester project

#ifndef NORMALIZER_STEREO_H
#define NORMALIZER_STEREO_H

#include "ProcessorStereo.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <cmath>

template <typename BS>
class NormalizerStereo: public ProcessorStereo<BS>{
int threshold;
public:
	NormalizerStereo(int threshold);
   	void processBufferStereo(BS* buffer,int bufferSize);
};
template <typename BS>NormalizerStereo<BS>::NormalizerStereo(int threshold): threshold(threshold){}
template <typename BS>void NormalizerStereo<BS>::processBufferStereo(BS* buffer,int bufferSize){
	int max=0;
	for(int i=0; i<bufferSize; i++){
		if(buffer[i]<max){
			buffer[i] = max;
		}
		buffer[i]*(max/std::numeric_limits<BS>::max());
	}

}
	

#endif
