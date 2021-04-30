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

		WavHeaderProcessor* header = new WavHeaderProcessor();
		header->processHeader(file);
		delete[] header;

		if(wavData.sample_rate == 8){

			WavDataProcessor8* data = new WavDataProcessor8();
			data->processData8(file);
			delete[] data;
		}

		if(wavData.sample_rate == 16){

			WavDataProcessor16* data = new WavDataProcessor16();
			data->processData16(file);
			delete[] data;
		}

		WavMetadataProcessor* metadata = new WavMetadataProcessor();
		metadata->processMetadata(file);
		delete[] metadata;

		file.close();
	}

}

template <typename B>
B Wav::getBuffer(){
	if(wavData.sample_rate == 8){

		WavDataProcessor8* data = new WavDataProcessor8();
		unsigned char* buffer = data->getBuffer8();
		delete[] data;
		return buffer;
	}

	if(wavData.sample_rate == 16){

		WavDataProcessor16* data = new WavDataProcessor16();
		short* buffer = data->getBuffer16();
		delete[] data;
		return buffer;

	}
}

int Wav::getBufferSize() const{
    return wavData.data_bytes;
}


//void writeFile(const std::string &outFileName){};