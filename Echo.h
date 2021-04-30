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
/**
This is the templated Echo class for mono.
*/
template <typename B>
class Echo: public Processor<B>{
int delay;
public:
	Echo(int delay);
   	void processBuffer(B* buffer,int bufferSize);
};
/**
This is the templated parameterized consuctor.
@param delay- this is the delay that is used to decide how long the echo is. 
*/
template <typename B>Echo<B>::Echo(int delay): delay(delay){}
/**
This takes out buffer and adds a delay that is given to produce a echo in the audio. 
@param buffer- Our read in wav file with all the information of the file.
@param bufferSize - The size of the buffer that is used in our loops.
*/ 
template <typename B>void Echo<B>::processBuffer(B* buffer, int bufferSize){
int i;
	for(i=0; i<bufferSize; i++){
		buffer[i] = buffer[i-delay]/3 + buffer[i];
	}

}
#endif
