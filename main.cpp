/** @file */
#include <iostream>

#include "WavProcessor8.h"
#include "WavProcessor16.h"


/*
#include "Echo.h"
#include "NoiseGate.h"
#include "Normalizer.h"
#include "Processor.h"
#include "EchoStereo.h"
#include "NoiseGateStereo.h"
#include "NormalizerStereo.h"
#include "ProcessorStereo.h"
*/

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


=======
void fn(){

}
/*
const std::string testfile = "testing.wav";
const std::string echofile = "echos.wav";
const std::string normalfile = "normal.wav";
const std::string noisefile = "noise.wav";
*/
int main() {
/**
    WavProcessor8 wav;
    wav.readFile(testfile);
    Processor *processor = new Echo(10);
    processor->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile(echofile);

 
    wav.readFile(testfile);
    Processor *normal = new Normalizer();
    normal->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile(normalfile);


    wav.readFile(testfile);
    Processor *gate = new NoiseGate(10);
    gate->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile(noisefile);
 
WavProcessor16 wav;
    wav.readFile(testfile);
    Processor *processor = new Echo(10);
    processor->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile(echofile);

 
    wav.readFile(testfile);
    Processor *normal = new Normalizer();
    normal->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile(normalfile);


    wav.readFile(testfile);
    Processor *gate = new NoiseGate(10);
    gate->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile(noisefile);

 WavProcessor8 wav;
    wav.readFile(testfile);
    ProcessorStereo *processorStereo = new EchoStereo(10);
    processorStereo->processBufferStereo(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile(echofile);

 
    wav.readFile(testfile);
    ProcessorStereo *normalStereo = new NormalizerStereo();
    normalStereo->processBufferStereo(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile(normalfile);


    wav.readFile(testfile);
    ProcessorStereo *gateStereo = new NoiseGateStereo(10);
    gateStereo->processBufferStereo(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile(noisefile);
 
WavProcessor16 wav;
    wav.readFile(testfile);
    ProcessorStereo *processorStereo = new Echo(10);
    processorStereo->processBufferStereo(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile(echofile);

 
    wav.readFile(testfile);
    ProcessorStereo *normalStereo = new NormalizerStereo();
    normalStereo->processBufferStereo(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile(normalfile);


    wav.readFile(testfile);
    ProcessorStereo *gateStereo = new NoiseGateStereo(10);
    gateStereo->processBufferStereo(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile(noisefile);
**/
}
