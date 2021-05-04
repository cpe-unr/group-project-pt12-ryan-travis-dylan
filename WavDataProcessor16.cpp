#include <string>
#include <fstream>
#include <iostream>
#include "WavDataProcessor16.h"

using namespace std;

void WavDataProcessor16::processData16(ifstream &openFile){

	int seekPos = wavData.wav_size - wavData.data_bytes;
	openFile.seekg(seekPos, openFile.beg);

	buffer = new unsigned char[wavData.data_bytes];
	openFile.read((char*)buffer, wavData.data_bytes);

}

short* WavDataProcessor16::getBuffer16(){
	short* shortBuffer = reinterpret_cast<short*>(buffer);
    return shortBuffer;
}

WavDataProcessor16::~WavDataProcessor16() {
    if(buffer != NULL)
        delete[] buffer;
}
