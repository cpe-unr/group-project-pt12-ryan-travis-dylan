//4/15/2021
//Dylan Judy
//semester project

#include "NoiseGate.h"

NoiseGate::NoiseGate(int threshold): threshold(threshold){}
void NoiseGate::processBuffer(B* buffer, int bufferSize){
	for( int i=0; i<bufferSize; i++){
		if(buffer[i] < (128+5) && (buffer[i] > (128-5))){
			buffer[i] = 128;
		}
		
	}

}
