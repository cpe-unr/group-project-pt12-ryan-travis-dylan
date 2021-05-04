#include <string>
#include <vector>

#include "WavParent.h"
#include "WavHeader.h"
#include "InfoHeader.h"

class WavProcessor16 : public WavParent{

	short audio_format;
	short num_channels;
	int sample_rate;
	int byte_rate;
	bool contains_metadata;

	std::string title;
	std::string artist;

	wav_header waveHeader;
	info_header infoHeader;
	artist_header artistHeader;

	unsigned char* buffer = NULL;
public:
	virtual ~WavProcessor16();

	void readFile(const string &fileName);
	void writeFile(const string &outputFile);

	short *getBuffer();
	int getBufferSize() const;

	std::string getArtist() const;
	void setArtist(std::string newArtist);

	std::string getTitle() const;
	void setTitle(std::string newTitle);

	std::string getMode() const;

	int getSampleRate() const;
};