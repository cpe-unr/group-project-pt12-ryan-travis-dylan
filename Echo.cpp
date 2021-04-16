//4/15/2021
//Dylan Judy
//semester project

#include "Echo.h"
using namespace std;

Echo::Echo(int delay): delay(delay){}
void Echo::processBuffer(B* buffer, int bufferSize){
int i;
	for(i=0; i<bufferSize; i++){
		buffer[i] = buffer[i-delay]/3 + buffer[i];
	}

}
