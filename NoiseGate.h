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

template <typename B>
class NoiseGate: public Processor<B>{
int threshold;
public:
	NoiseGate(int threshold);
   	void processBuffer(B* buffer,int bufferSize);
};
template <typename B> NoiseGate <B>::NoiseGate(int threshold): threshold(threshold){}
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
