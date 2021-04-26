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
/**
This is the templated NoiseGate class for stereo.
*/
template <typename BS>
class NoiseGateStereo: public ProcessorStereo<BS>{
int threshold;
public:
	NoiseGateStereo(int threshold);
   	void processBufferStereo(BS* buffer,int bufferSize);
};
/**
This is the templated parameterized consuctor.
@param threshold- this is the threshold of audio. 
*/
template <typename BS> NoiseGateStereo<BS>::NoiseGateStereo(int threshold): threshold(threshold){}
/**
This finds our zero point and then brings the audio within a certin range down or up to the zero point.
@param buffer- Our read in wav file with all the information of the file.
@param bufferSize - The size of the buffer that is used in our loops.
*/ 
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
