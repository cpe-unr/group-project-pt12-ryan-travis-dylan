
audio: main.o WavProcessor8.o WavProcessor16.o
	g++ -std=c++11 main.o WavProcessor8.o WavProcessor16.o -o audioprocessor
main.o: main.cpp Echo.h NoiseGate.h Normalizer.h Processor.h
	g++ -std=c++11 main.cpp -c
WavProcessor8.o: WavProcessor8.h
	g++ -std=c++11 WavProcessor8.cpp -c
WavProcessor16.o: WavProcessor8.h
	g++ -std=c++11 WavProcessor16.cpp -c
clean:
	rm *.o audioprocessor
