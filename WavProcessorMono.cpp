#include <string>
#include <fstream>
#include <iostream>
#include "WavProcessorMono.h"

using namespace std;

void WavProcessorMono::readFile(const string &fileName) {
    ifstream file(fileName, ios::binary | ios::in);

    if(file.is_open()){

        file.read((char*)&waveHeader, sizeof(wav_header));

        buffer = new unsigned char[waveHeader.data_bytes];
        file.read((char*)buffer, waveHeader.data_bytes);

        file.read((char*)&infoHeader, sizeof(info_header));
        file.close();
    }
}


unsigned char *WavProcessorMono::getBuffer(){
    return buffer;
}

void WavProcessorMono::writeFile(const string &outputFile) {
    std::ofstream outFile(outputFile, ios::out | ios::binary);
    outFile.write((char*)&waveHeader, sizeof(wav_header));
    outFile.write((char*)buffer, waveHeader.data_bytes);
    outFile.write((char*)&infoHeader, sizeof(info_header));
    outFile.close();
}

WavProcessorMono::~WavProcessorMono() {
    if(buffer != NULL)
        delete[] buffer;
}

int WavProcessorMono::getBufferSize() const {
    return waveHeader.data_bytes;
}
