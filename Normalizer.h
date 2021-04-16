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

class Normalizer: public Processor{
int threshold;
public:
	Normalizer(int threshold);
	template <typename B>
   	void processBuffer(B* buffer,int bufferSize);
};
#endif
