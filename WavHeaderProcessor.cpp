#include <string>
#include <fstream>
#include <iostream>

#include "WavHeaderProcessor.h"

using namespace std;

void WavHeaderProcessor::processHeader(ifstream openFile){

	//Read each individual entry into wavData entry
	//RIFF chunk
	openFile.read((char*)wavData.riff_header, 4);
	openFile.read((char*)wavData.wav_size, sizeof(int));
	openFile.read((char*)wavData.wave_header, 4);

	//FMT chunk
	openFile.read((char*)wavData.fmt_header, 4);
	openFile.read((char*)wavData.fmt_chunk_size, sizeof(int));
	openFile.read((char*)wavData.audio_format, sizeof(short));
	openFile.read((char*)wavData.num_channels, sizeof(short));
	openFile.read((char*)wavData.sample_rate, sizeof(int));
	openFile.read((char*)wavData.byte_rate, sizeof(int));
	openFile.read((char*)wavData.sample_alignment, sizeof(short));
	openFile.read((char*)wavData.bit_depth, sizeof(short));

	//DATA chunk
	openFile.read((char*)wavData.data_header, 4);
	openFile.read((char*)wavData.data_bytes, sizeof(int));
	//End at start of data bytes

}