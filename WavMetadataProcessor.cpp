#include <string>
#include <fstream>
#include <iostream>
#include "WavMetadataProcessor.h"

using namespace std;

void WavMetadataProcessor::processMetadata(ifstream &openFile){

	int seekPos = (wavData.wav_size - wavData.data_bytes) + wavData.data_bytes;
	openFile.seekg(seekPos, openFile.beg);

	//Check to see if character at this position is an EOF
	if(openFile.peek() == EOF){
		wavData.contains_metadata = 0;
		return;
	}
	else{
		wavData.contains_metadata = 1;

		//Read each individual entry into wavData structure
		openFile.read((char*)wavData.list_header, 4);
		openFile.read((char*)wavData.list_size, sizeof(int));
		openFile.read((char*)wavData.info_header, 4);

		if(openFile.peek() == EOF){
			return;
		}

		openFile.read((char*)wavData.inam_header, 4);
		openFile.read((char*)wavData.title_size, sizeof(int));
		openFile.read((char*)wavData.title.data(), wavData.title_size);

		if(openFile.peek() == EOF){
			return;
		}

		openFile.read((char*)wavData.iart_header, 4);
		openFile.read((char*)wavData.artist_size, sizeof(int));
		openFile.read((char*)wavData.artist.data(), wavData.artist_size);
	}
	
}