
audio: main.o
	g++ -std=c++11 main.o -o audioprocessor
main.o: main.cpp Echo.h NoiseGate.h Normalizer.h Processor.h
	g++ -std=c++11 main.cpp -c
clean:
	rm *.o audioprocessor
