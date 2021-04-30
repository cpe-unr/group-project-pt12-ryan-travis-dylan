#include <string>
#include <fstream>
#include <iostream>
#include "WavDataProcessor8.h"

using namespace std;

void WavDataProcessor8::processData8(ifstream openFile){

	int seekPos = wavData.wav_size - wavData.data_bytes;
	openFile.seekg(seekPos, openFile.beg);

	buffer = new unsigned char[wavData.data_bytes];
	openFile.read((char*)buffer, wavData.data_bytes);

}

unsigned char* WavDataProcessor8::getBuffer8(){
	return buffer;
}

WavDataProcessor8::~WavDataProcessor8() {
    if(buffer != NULL)
        delete[] buffer;
}