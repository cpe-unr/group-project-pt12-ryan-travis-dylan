#include <string>
#include <fstream>
#include <iostream>
#include "WavProcessor8.h"

using namespace std;

/**
Read the file if it's 8-bit sample rate
@param fileName - Input file to be read
*/
void WavProcessor8::readFile(const string &fileName) {
    ifstream file(fileName, ios::binary | ios::in);

    char titleC[99], artistC[99];

    if(file.is_open()){

        file.read((char*)&waveHeader, sizeof(wav_header));

        buffer = new unsigned char[waveHeader.data_bytes];
        file.read((char*)buffer, waveHeader.data_bytes);

        file.read((char*)&infoHeader, sizeof(info_header));
        file.read(titleC, reinterpret_cast<int>(infoHeader.title_size));

        file.read((char*)&artistHeader, sizeof(artist_header));
        file.read(artistC, reinterpret_cast<int>(artistHeader.artist_size));

        title = titleC;
        artist = artistC;

        file.close();
    }
}

/**
Return the buffer of an 8-bit file, as an unsigned char.
*/
unsigned char *WavProcessor8::getBuffer8(){
    return buffer;
}

/**
Write a new file with the modified changes
@param outputFile - Output file to be written
*/
void WavProcessor8::writeFile(const string &outputFile) {
    ofstream outFile(outputFile, ios::out | ios::binary);

    outFile.write((char*)&waveHeader, sizeof(wav_header));

    outFile.write((char*)buffer, waveHeader.data_bytes);

    outFile.write((char*)&infoHeader, sizeof(info_header));
    outFile.write(title.c_str(), reinterpret_cast<int>(infoHeader.title_size));

    outFile.write((char*)&artistHeader, sizeof(artist_header));
    outFile.write(artist.c_str(), reinterpret_cast<int>(artistHeader.artist_size));

    outFile.close();
}

WavProcessor8::~WavProcessor8() {
    if(buffer != NULL)
        delete[] buffer;
}

/**
Get the size of the input buffer
*/
int WavProcessor8::getBufferSize() const {
    return waveHeader.data_bytes;
}

string WavProcessor8::getArtist() {return artist;}
void WavProcessor8::setArtist(string newArtist) {artist = newArtist;}

string WavProcessor8::getTitle() {return title;}
void WavProcessor8::setTitle(string newtitle) {title = newtitle;}
