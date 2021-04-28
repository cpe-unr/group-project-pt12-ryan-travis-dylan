#include <string>
#include <vector>

#include "WavParent.h"
#include "WavHeader.h"
#include "InfoHeader.h"

class WavProcessor8 : public WavParent<unsigned char>{
	int wav_size;
	short format_size;
	short num_channels;
	int sample_rate;
	int byte_rate;
	short bit_depth;
	std::string title;
	std::string artist;

	wav_header waveHeader;
	info_header infoHeader;
	artist_header artistHeader;
	unsigned char* buffer = NULL;
public:
	virtual ~WavProcessor8();

	void readFile(const string &fileName);
	void writeFile(const string &outputFile);

	unsigned char *getBuffer();
	int getBufferSize() const;

	std::string getArtist();
	void setArtist(std::string newArtist);

	std::string getTitle();
	void setTitle(std::string newTitle);
};