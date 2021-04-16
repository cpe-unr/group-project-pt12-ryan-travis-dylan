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
#endif
