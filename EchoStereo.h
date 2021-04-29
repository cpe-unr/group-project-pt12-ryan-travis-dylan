//4/15/2021
//Dylan Judy
//semester project

#ifndef ECHO_STEREO_H
#define ECHO_STEREO_H

#include "ProcessorStereo.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <cmath>
/**
This is the templated Echo class for stereo.
*/
template <typename BS>
class EchoStereo: public ProcessorStereo<BS>{
int delay;
public:
	EchoStereo(int delay);
   	void processBufferStereo(BS* buffer,int bufferSize);
};
/**
This is the templated parameterized consuctor.
@param delay- this is the delay that is used to decide how long the echo is. 
*/
template <typename BS>EchoStereo<BS>::EchoStereo(int delay): delay(delay){}
/**
This takes out buffer and adds a delay that is given to produce a echo in the audio.
It also makes sure the delay is divisable by 2 to deal with stereo audio and its 2 channels.  
@param buffer- Our read in wav file with all the information of the file.
@param bufferSize - The size of the buffer that is used in our loops.
*/ 
template <typename BS>void EchoStereo<BS>::processBufferStereo(BS* buffer, int bufferSize){
int i;
	if((delay %2)!=0){
		delay+1;
	}
	for(i=0; i<bufferSize; i++){
		buffer[i] = buffer[i-delay]/3 + buffer[i];
	}
}
#endif
