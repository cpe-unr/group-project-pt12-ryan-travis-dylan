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
/**
This is the templated Normalizer class for stereo.
*/
template <typename BS>
class NormalizerStereo: public ProcessorStereo<BS>{
int threshold;
public:
	NormalizerStereo();
   	void processBufferStereo(BS* buffer,int bufferSize);
};
/**
This is the templated consuctor.
*/
template <typename BS>NormalizerStereo<BS>::NormalizerStereo(){}
/**
This is what finds the max and then normalizes the audio for the file using the max.
@param buffer- Our read in wav file with all the information of the file.
@param bufferSize - The size of the buffer that is used in our loops.
*/ 
template <typename BS>void NormalizerStereo<BS>::processBufferStereo(BS* buffer,int bufferSize){
	int max=0;
	for(int i=0; i<bufferSize; i= i+2){
		if(buffer[i]<max){
			buffer[i] = max;
		}
		buffer[i]*(max/std::numeric_limits<BS>::max());
	}

}
	

#endif
