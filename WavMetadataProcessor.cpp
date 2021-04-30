#include <string>
#include <fstream>
#include <iostream>
#include "WavMetadataProcessor.h"

using namespace std;

void WavMetadataProcessor::processMetadata(ifstream openFile){

	int seekPos = (wavData.wav_size - wavData.data_bytes) + wavData.data_bytes;
	openFile.seekg(seekPos, openFile.beg);

	//Check to see if character at this position is an EOF
	if(openFile.peek() = EOF){
		wavData.contains_metadata = FALSE;
		break;
	}
	else{
		wavData.contains_metadata = TRUE;

		//Read each individual entry into wavData structure
		openFile.read(wavData.list_header, 4);
		openFile.read(wavData.list_size, sizeof(int));
		openFile.read(wavData.info_header, 4);

		if(openFile.peek() = EOF){
			break;
		}

		openFile.read(wavData.inam_header, 4);
		openFile.read(wavData.title_size, sizeof(int));
		openFile.read(wavData.title.data(), wavData.title_size);

		if(openFile.peek() = EOF){
			break;
		}

		openFile.read(wavData.iart_header, 4);
		openFile.read(wavData.artist_size, sizeof(int));
		openFile.read(wavData.artist.data(), wavData.artist_size);
	}
	
}