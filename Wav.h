#ifndef WAV_MAIN
#define WAV_MAIN

#include "WavStructure.h"
#include "WavDataProcessor8.h"
#include "WavDataProcessor16.h"

class Wav{
protected:
	wav_structure wavData;

public:
	//Reading Functions
	void readFile(const std::string &fileName);

	template <typename M>
    M getMetadata(int paramNum){
        switch(paramNum){
            case 1:
                return wavData.riff_header;
            case 2:
                return wavData.wav_size;
            case 3:
                return wavData.wave_header;
            case 4:
                return wavData.fmt_header;
            case 5:
                return wavData.fmt_chunk_size;
            case 6:
                return wavData.audio_format;
            case 7:
                return wavData.num_channels;
            case 8:
                return wavData.sample_rate;
            case 9:
                return wavData.byte_rate;
            case 10:
                return wavData.sample_alignment;
            case 11:
                return wavData.bit_depth;
            case 12:
                return wavData.data_header;
            case 13:
                return wavData.data_bytes;
            case 14:
                return wavData.contains_metadata;
            case 15:
                return wavData.list_header;
            case 16:
                return wavData.list_size;
            case 17:
                return wavData.info_header;
            case 18:
                return wavData.inam_header;
            case 19:
                return wavData.title_size;
            case 20:
                return wavData.title;
            case 21:
                return wavData.iart_header;
            case 22:
                return wavData.artist_size;
            case 23:
                return wavData.artist;
    };

    template <typename B>
    B getBuffer(){
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
    };

    int getBufferSize() const;

    //Writing Functions
    //void writeFile(const std::string &outFileName);
};

#endif