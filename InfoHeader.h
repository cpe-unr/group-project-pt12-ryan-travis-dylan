#ifndef INFO_HEADER
#define INFO_HEADER

#include <string>

typedef struct info_header {
	char list_header[4]; //"LIST"
	int list_size; //Size of list chunk
	char info_header[4]; //"INFO"

	//Title
	char inam_header[4]; //"INAM"
	int title_size; //Size of title
	char title[title_size]; //Title

	//Artist
	char iart_header[4]; //"IART"
	int artist_size; //Size of artist
	char artist[artist_size]; //Artist
} info_header;