#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <cmath>
#include <limits>

using namespace std;

std::cout<<"Enter one processor to process a file: \n";
std::cout<<"[1] Echo\n"
	 <<"[2] Normilization\n"
	 <<"[3] Noise Gate\n";

std::string input;
std::getline(std::cin, input);

while(input != "1" && input != "2" && input != "3"){
	std::cout<<"Option is invalid"\n;

	std::cout<<"Enter one processor to process a file: \n";
	std::cout<<"[1] Echo\n"
	 	 <<"[2] Normilization\n"
	 	 <<"[3] Noise Gate\n";
	std::getline(std::cin, input);
	}
if(choice == 1){
//code
}
else if(choice == 2){
//code
}
else if(choice == 3){
//code
}




cout<<"No metadata present"<<<<endl //???
