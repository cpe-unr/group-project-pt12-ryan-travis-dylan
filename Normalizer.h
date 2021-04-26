//4/15/2021
//Dylan Judy
//semester project

#ifndef NORMALIZER_H
#define NORMALIZER_H

#include "Processor.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <cmath>
/**
This is the templated Normalizer class for mono.
*/

template <typename B>
class Normalizer: public Processor<B>{
int threshold;
public:
	Normalizer(int threshold);
   	void processBuffer(B* buffer,int bufferSize);
};
/**
This is the templated parameterized consuctor.
@param threshold- this is the threshold of audio. 
*/
template <typename B>Normalizer<B>::Normalizer(int threshold): threshold(threshold){}
/**
This is what finds the max and then normalizes the audio for the file using the max.
@param buffer- Our read in wav file with all the information of the file.
@param bufferSize - The size of the buffer that is used in our loops.
*/  
template <typename B>void Normalizer<B>::processBuffer(B* buffer,int bufferSize){
	int max=0;
	for(int i=0; i<bufferSize; i++){
		if(buffer[i]<max){
			buffer[i] = max;
		}
		buffer[i]*(max/std::numeric_limits<B>::max());
	}

}
	

#endif
