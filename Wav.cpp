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

	WavHeaderProcessor header;
	WavMetadataProcessor metadata;


	if(file.is_open()){

		header.processHeader(file);

		if(wavData.sample_rate == 8){

			WavDataProcessor8 8bitData;
			8bitData.processData8(file);
		}

		if(wavData.sample_rate == 16){

			WavDataProcessor16 16bitData;
			16bitData.processData16(file);
		}

		metadata.processMetadata(file);

		file.close();
	}

}

auto Wav::getBuffer(){
	if(wavData.sample_rate == 8){
		return WavDataProcessor8.getBuffer8();
	}

	if(wavData.sample_rate == 16){
		return WavDataProcessor16.getBuffer16();
	}
}

int Wav::getBufferSize() const{
    return wavData.data_bytes;
}

auto Wav::getMetadata(string param){
	switch(param){
		case 'riff_header':
			return wavData.riff_header;
		case 'wav_size':
			return wavData.wav_size;
		case 'wave_header':
			return wavData.wave_header;
		case 'fmt_header':
			return wavData.fmt_header;
		case 'fmt_chunk_size':
			return wavData.fmt_chunk_size;
		case 'audio_format':
			return wavData.audio_format;
		case 'num_channels':
			return wavData.num_channels;
		case 'sample_rate':
			return wavData.sample_rate;
		case 'byte_rate':
			return wavData.byte_rate;
		case 'sample_alignment':
			return wavData.sample_alignment;
		case 'bit_depth':
			return wavData.bit_depth;
		case 'data_header':
			return wavData.data_header;
		case 'data_bytes':
			return wavData.data_bytes;
		case 'contains_metadata':
			return wavData.contains_metadata;
		case 'list_header':
			return wavData.list_header;
		case 'list_size':
			return wavData.list_size;
		case 'info_header':
			return wavData.info_header;
		case 'inam_header':
			return wavData.inam_header;
		case 'title_size':
			return wavData.title_size;
		case 'title':
			return wavData.title;
		case 'iart_header':
			return wavData.iart_header;
		case 'artist_size':
			return wavData.artist_size;
		case 'artist':
			return wavData.artist;
	}

}

//void writeFile(const std::string &outFileName){};