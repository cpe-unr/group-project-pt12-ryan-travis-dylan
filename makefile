test: main.cpp Wav.o WavHeaderProcessor.o WavDataProcessor8.o WavDataProcessor16.o WavMetadataProcessor.o WavStructure.h
	g++ main.cpp Wav.o WavHeaderProcessor.o WavDataProcessor8.o WavDataProcessor16.o WavMetadataProcessor.o -o test

Wav.o: Wav.cpp Wav.h
	g++ -c Wav.cpp

WavHeaderProcessor.o: WavHeaderProcessor.cpp WavHeaderProcessor.h
	g++ -c WavHeaderProcessor.cpp

WavDataProcessor8.o: WavDataProcessor8.cpp WavDataProcessor8.h
	g++ -c WavDataProcessor8.cpp

WavDataProcessor16.o: WavDataProcessor16.cpp WavDataProcessor16.h
	g++ -c WavDataProcessor16.cpp

WavMetadataProcessor.o: WavMetadataProcessor.cpp WavMetadataProcessor.h
	g++ -c WavMetadataProcessor.cpp

clean:
	rm *.o
	rm test