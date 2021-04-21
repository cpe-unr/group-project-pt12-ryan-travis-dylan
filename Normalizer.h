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
#endif
