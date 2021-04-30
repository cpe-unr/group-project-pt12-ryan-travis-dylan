#include <string>
#include <fstream>
#include <iostream>

#include "Wav.h"
#include "WavHeaderProcessor.h"
#include "WavDataProcessor8.h"
#include "WavDataProcessor16.h"
#include "WavMetadataProcessor.h"


using namespace std;

void Wav::readFile(const std::string &fileName){

	ifstream file(fileName, ios::binary | ios::in);

	if(file.is_open()){

		processHeader(file);

		if(wavData.sample_rate == 8){
			processData8(file);
		}

		if(wavData.sample_rate == 16){
			processData16(file);
		}

		processMetadata(file);

		file.close();
	}

}

template <typename B>
B* Wav<B>::getBuffer(){
	if(wavData.sample_rate == 8){
		return getBuffer8();
	}

	if(wavData.sample_rate == 16){
		return getBuffer16();
	}
}

Wav::getBufferSize() {
    return wavData.data_bytes;
}

template <typename M>
M Wav<M>::getMetadata(const std::string &param){
	M = wavData.param;
	return M;
}

//void writeFile(const std::string &outFileName){};