//4/15/2021
//Dylan Judy
//semester project

#ifndef NOISEGATE_STEREO_H
#define NOISEGATE_STEREO_H

#include "ProcessorStereo.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <cmath>

template <typename BS>
class NoiseGateStereo: public ProcessorStereo<BS>{
int threshold;
public:
	NoiseGateStereo(int threshold);
   	void processBufferStereo(BS* buffer,int bufferSize);
};
template <typename BS> NoiseGateStereo<BS>::NoiseGateStereo(int threshold): threshold(threshold){}
template <typename BS> void NoiseGateStereo<BS>::processBufferStereo(BS* buffer, int bufferSize){
	BS zeroPoint;
	zeroPoint = std::numeric_limits<BS>::max();
	for( int i=0; i<bufferSize; i++){
		if(buffer[i] < (zeroPoint+5) && (buffer[i] > (zeroPoint-5))){
			buffer[i] = zeroPoint;
		}
		
	}

}
#endif
