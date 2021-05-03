#ifndef WAV_PARENT
#define WAV_PARENT

#include <string>

using namespace std;

class WavParent{
public:
	virtual void readFile(const string &fileName) = 0;
	virtual void writeFile(const string &outputFile) = 0;
};

#endif