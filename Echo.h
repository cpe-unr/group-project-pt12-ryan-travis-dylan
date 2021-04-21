//4/15/2021
//Dylan Judy
//semester project

#ifndef ECHO_H
#define ECHO_H

#include "Processor.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <cmath>

template <typename B>
class Echo: public Processor<B>{
int delay;
public:
	Echo(int delay);
   	void processBuffer(B* buffer,int bufferSize);
};
template <typename B>Echo<B>::Echo(int delay): delay(delay){}
template <typename B>void Echo<B>::processBuffer(B* buffer, int bufferSize){
int i;
	for(i=0; i<bufferSize; i++){
		buffer[i] = buffer[i-delay]/3 + buffer[i];
	}

}
#endif
