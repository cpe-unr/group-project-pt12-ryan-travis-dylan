#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <cmath>
#include <limits>

using namespace std;

void CSV::outputCSV(string OUTPUT, string CSVFile1, string CSVFile2, string CSVFile3, string CSVFile4){

OUTPUT=OUTPUT+".csv";
std::ofstream myFile(OUTPUT);

myFile<<",Artist,Track,Album,Data,Genre,Track Number,Comments,";
myFile<<"\n";
myFile<<CSVFile1;
myFile<<"\n";
myFile<<CSVFile2;
myFile<<"\n";
myFile<<CSVFile3;
myFile<<"\n";
myFile<<CSVFile4;

myFile.close();
}
