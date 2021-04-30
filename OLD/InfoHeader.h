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

} info_header;

typedef struct artist_header {
	char iart_header[4];
	int artist_size;
} artist_header;

#endif