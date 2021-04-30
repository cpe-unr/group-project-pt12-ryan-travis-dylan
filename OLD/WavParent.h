#ifndef WAV_PARENT
#define WAV_PARENT

#include <string>

using namespace std;

template <typename W>
class WavParent{
private:
	W* buffer = NULL;
public:
	virtual void readFile(const string &fileName) = 0;
	virtual void writeFile(const string &outputFile) = 0;

	W *getBuffer();
	int getBufferSize() const;
};

#endif