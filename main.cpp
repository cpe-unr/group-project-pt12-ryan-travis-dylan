/** @file */
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "WavStructure.h"
#include "WavHeaderProcessor.h"
#include "WavDataProcessor8.h"
#include "WavDataProcessor16.h"
#include "WavMetadataProcessor.h"
#include "Wav.h"
#include "Echo.h"
#include "NoiseGate.h"
#include "Normalizer.h"
#include "Processor.h"
#include "EchoStereo.h"
#include "NoiseGateStereo.h"
#include "NormalizerStereo.h"
#include "ProcessorStereo.h"

const std::string testfile = "testing.wav";
const std::string echofile = "echos.wav";
const std::string normalfile = "normal.wav";
const std::string noisefile = "noise.wav";
int main() {
/**
This is the first user interaction that occurs, where the user chooses if they want the file processed using echo, normilization, or  using noise gate.
*/
using namespace std;

std::cout<<"Choose one processor to process a file (1,2, or 3): \n";
std::cout<<"[1] Echo\n"
	 <<"[2] Normilization\n"
	 <<"[3] Noise Gate\n";

std::string input;
std::stringstream in;
int inputs =0;
in>>inputs;
std::getline(std::cin, input);
/**
This is what happens when the user chooses an option and if an option is valid or not.
*/
while(inputs != '1' && inputs != '2' && inputs != '3'){
	std::cout<<"Option is invalid"<<std::endl;

	std::cout<<"Choose one processor to process a file (1,2, or 3): \n";
	std::cout<<"[1] Echo\n"
	 	 <<"[2] Normilization\n"
	 	 <<"[3] Noise Gate\n";
	std::getline(std::cin, input);
	}
/**
This is where the user chooses if they want mono or stereo inside their previous choice made earlier. This particular choice is used for the echo function.
*/
if(inputs == 1){
	std::cout<<"Mono or Stereo? "<<std::endl;
	std::string input;
	std::getline(std::cin, input);
	if(input == "Mono"){

WavDataProcessor8 wav;
    wav.readFile(testfile);
    Echo<unsigned char> *processor = new Echo<unsigned char> (10);
    processor->processBuffer(wav.getBuffer8(),wav.getBufferSize());
    

	WavDataProcessor16 wav2;
    wav2.readFile(testfile);
    Echo<short> *processor2 = new Echo<short>(10);
    processor2->processBuffer(wav2.getBuffer16(),wav2.getBufferSize());
    
}
	if(input == "Stereo"){

	WavDataProcessor8 wav3;
    wav3.readFile(testfile);
    EchoStereo<unsigned char> *processorStereo = new EchoStereo<unsigned char>(10);
    processorStereo->processBufferStereo(wav3.getBuffer8(),wav3.getBufferSize());
  

	WavDataProcessor16 wav4;
    wav4.readFile(testfile);
    EchoStereo<short> *processorStereo2 = new EchoStereo<short>(10);
    processorStereo2->processBufferStereo(wav4.getBuffer16(),wav4.getBufferSize());
    
}}
/**
This is where the user chooses if they want mono or stereo inside their previous choice made earlier. This particular choice is used for the normalization function.
*/
else if(inputs == 2){
	std::cout<<"Mono or Stereo? \n";
	std::string input;
	std::getline(std::cin, input);
	if(input == "Mono"){

WavDataProcessor8 wav;
	wav.readFile(testfile);
    Normalizer<unsigned char> *normal = new Normalizer<unsigned char> ();
    normal->processBuffer(wav.getBuffer8(),wav.getBufferSize());
    

WavDataProcessor16 wav2;
	wav2.readFile(testfile);
    Normalizer<short> *normal2 = new Normalizer<short>();
    normal2->processBuffer(wav2.getBuffer16(),wav2.getBufferSize());
    
}
	if(input == "Stereo"){
WavDataProcessor8 wav3;
	wav3.readFile(testfile);
    NormalizerStereo<unsigned char> *normalStereo = new NormalizerStereo<unsigned char>();
    normalStereo->processBufferStereo(wav3.getBuffer8(),wav3.getBufferSize());
    
WavDataProcessor16 wav4;
	wav4.readFile(testfile);
    NormalizerStereo<short> *normalStereo2 = new NormalizerStereo<short>();
    normalStereo2->processBufferStereo(wav4.getBuffer16(),wav4.getBufferSize());
    
}}
/**
This is where the user chooses if they want mono or stereo inside their previous choice made earlier. This particular choice is used for the noise gate function.
*/
else if(inputs == 3){
	std::cout<<"Mono or Stereo? \n";
	std::string input;
	std::getline(std::cin, input);
	if(input == "Mono"){

WavDataProcessor8 wav;
	 wav.readFile(testfile);
    NoiseGate<unsigned char> *gate = new NoiseGate<unsigned char> (10);
    gate->processBuffer(wav.getBuffer8(),wav.getBufferSize());
    

WavDataProcessor16 wav2;
	wav2.readFile(testfile);
    NoiseGate<short> *gate2 = new NoiseGate<short>(10);
    gate2->processBuffer(wav2.getBuffer16(),wav2.getBufferSize());
    
}
	if(input == "Stereo"){
WavDataProcessor8 wav3;
	wav3.readFile(testfile);
    NoiseGateStereo<unsigned char> *gateStereo = new NoiseGateStereo<unsigned char>(10);
    gateStereo->processBufferStereo(wav3.getBuffer8(),wav3.getBufferSize());
    

WavDataProcessor16 wav4;
	 wav4.readFile(testfile);
    NoiseGateStereo<short> *gateStereo2 = new NoiseGateStereo<short>(10);
    gateStereo2->processBufferStereo(wav4.getBuffer16(),wav4.getBufferSize());
    
}
}}
