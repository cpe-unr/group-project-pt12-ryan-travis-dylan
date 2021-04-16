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
#endif
