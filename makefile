
audio: main.cpp echo.o NoiseGate.o processor.o
	g++ -std=c++11 main.cpp Echo.o NoiseGate.o Processor.o -o audioprocessor

echo.o: Echo.cpp Echo.h
	g++ -c -std=c++11 Echo.cpp 
NoiseGate.o: NoiseGate.cpp NoiseGate.h
	g++ -c -std=c++11 NoiseGate.cpp
processor.o: Processor.cpp Processor.h
	g++ -c -std=c++11 Processor.cpp
clean:
	rm *.o audioprocessor
