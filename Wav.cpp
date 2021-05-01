#include <string>
#include <fstream>
#include <iostream>
#include <vector>

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

auto Wav::getBuffer(){
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

vector<string> getMetadata(){
	//Create vector of all data contained in WAV file, searchable by going to specific pos in vector

	vector<string> container;

	//RIFF
	container.push_back(wavData.riff_header);
	container.push_back(to_string(wavData.wav_size));
	container.push_back(wavData.wave_header);

	//FMT
	container.push_back(wavData.fmt_header);
	container.push_back(to_string(wavData.fmt_chunk_size));
	container.push_back(to_string(wavData.audio_format));
	container.push_back(to_string(wavData.num_channels));
	container.push_back(to_string(wavData.sample_rate));
	container.push_back(to_string(wavData.byte_rate));
	container.push_back(to_string(wavData.sample_alignment));
	container.push_back(to_string(wavData.bit_depth));

	//DATA
	container.push_back(wavData.data_header);
	container.push_back(to_string(wavData.data_bytes));

	//FLAG (local)
	container.push_back(to_string(wavData.contains_metadata));

	if(wavData.contains_metadata == 1){
		//LIST
		container.push_back(wavData.list_header);
		container.push_back(to_string(wavData.list_size));
		container.push_back(wavData.info_header);

		//Title
		container.push_back(wavData.inam_header);
		container.push_back(to_string(wavData.title_size));
		container.push_back(wavData.title);

		//Artist
		container.push_back(wavData.iart_header);
		container.push_back(to_string(wavData.artist_size));
		container.push_back(wavData.artist);
	}

	return container;
}


//void writeFile(const std::string &outFileName){};