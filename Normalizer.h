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

template <typename B>
class Normalizer: public Processor<B>{
int threshold;
public:
	Normalizer(int threshold);
   	void processBuffer(B* buffer,int bufferSize);
};
template <typename B>Normalizer<B>::Normalizer(int threshold): threshold(threshold){}
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
