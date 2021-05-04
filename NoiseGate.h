//4/15/2021
//Dylan Judy
//semester project

#ifndef NOISEGATE_H
#define NOISEGATE_H

#include "Processor.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <cmath>
/**
This is the templated NoiseGate class for mono.
*/

template <typename B>
class NoiseGate: public Processor<B>{
int threshold;
public:
	NoiseGate(int threshold);
   	void processBuffer(B* buffer,int bufferSize);
};
/**
This is the templated parameterized consuctor.
@param threshold- this is the threshold of audio. 
*/
template <typename B> NoiseGate <B>::NoiseGate(int threshold): threshold(threshold){}
/**
This finds our zero point and then brings the audio within a certin range down or up to the zero point.
@param buffer- Our read in wav file with all the information of the file.
@param bufferSize - The size of the buffer that is used in our loops.
*/ 
template <typename B> void NoiseGate<B>::processBuffer(B* buffer, int bufferSize){
	B zeroPoint;
	zeroPoint = std::numeric_limits<B>::max();
	for( int i=0; i<bufferSize; i++){
		if(buffer[i] < (zeroPoint+5) && (buffer[i] > (zeroPoint-5))){
			buffer[i] = zeroPoint;
		}
		
	}

}
#endif
