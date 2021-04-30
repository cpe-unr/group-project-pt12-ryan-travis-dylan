/** @file */
#include <iostream>
#include <string>
#include "WavProcessor8.h"
#include "WavProcessor16.h"
#include "Echo.h"
#include "NoiseGate.h"
#include "Normalizer.h"
#include "Processor.h"
#include "EchoStereo.h"
#include "NoiseGateStereo.h"
#include "NormalizerStereo.h"
#include "ProcessorStereo.h"

/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */

void fn(){

}
const std::string testfile = "testing.wav";
const std::string echofile = "echos.wav";
const std::string normalfile = "normal.wav";
const std::string noisefile = "noise.wav";
int main() {

    WavProcessor8 wav;
    wav.readFile(testfile);
    Echo<unsigned char> *processor = new Echo<unsigned char> (10);
    processor->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile(echofile);

    wav.readFile(testfile);
    Normalizer<unsigned char> *normal = new Normalizer<unsigned char> ();
    normal->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile(normalfile);


    wav.readFile(testfile);
    NoiseGate<unsigned char> *gate = new NoiseGate<unsigned char> (10);
    gate->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile(noisefile);
 
WavProcessor16 wav2;
    wav2.readFile(testfile);
    Echo<short> *processor2 = new Echo<short>(10);
    processor2->processBuffer(wav2.getBuffer(),wav2.getBufferSize());
    wav2.writeFile(echofile);

 
    wav2.readFile(testfile);
    Normalizer<short> *normal2 = new Normalizer<short>();
    normal2->processBuffer(wav2.getBuffer(),wav2.getBufferSize());
    wav2.writeFile(normalfile);


    wav2.readFile(testfile);
    NoiseGate<short> *gate2 = new NoiseGate<short>(10);
    gate2->processBuffer(wav2.getBuffer(),wav2.getBufferSize());
    wav2.writeFile(noisefile);

 WavProcessor8 wav3;
    wav3.readFile(testfile);
    EchoStereo<unsigned char> *processorStereo = new EchoStereo<unsigned char>(10);
    processorStereo->processBufferStereo(wav3.getBuffer(),wav3.getBufferSize());
    wav3.writeFile(echofile);

 
    wav3.readFile(testfile);
    NormalizerStereo<unsigned char> *normalStereo = new NormalizerStereo<unsigned char>();
    normalStereo->processBufferStereo(wav3.getBuffer(),wav3.getBufferSize());
    wav3.writeFile(normalfile);


    wav3.readFile(testfile);
    NoiseGateStereo<unsigned char> *gateStereo = new NoiseGateStereo<unsigned char>(10);
    gateStereo->processBufferStereo(wav3.getBuffer(),wav3.getBufferSize());
    wav3.writeFile(noisefile);
 
WavProcessor16 wav4;
    wav4.readFile(testfile);
    EchoStereo<short> *processorStereo2 = new EchoStereo<short>(10);
    processorStereo2->processBufferStereo(wav4.getBuffer(),wav4.getBufferSize());
    wav4.writeFile(echofile);

 
    wav4.readFile(testfile);
    NormalizerStereo<short> *normalStereo2 = new NormalizerStereo<short>();
    normalStereo2->processBufferStereo(wav4.getBuffer(),wav4.getBufferSize());
    wav4.writeFile(normalfile);


    wav4.readFile(testfile);
    NoiseGateStereo<short> *gateStereo2 = new NoiseGateStereo<short>(10);
    gateStereo2->processBufferStereo(wav4.getBuffer(),wav4.getBufferSize());
    wav4.writeFile(noisefile);

}
