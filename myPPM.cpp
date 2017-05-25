/*
 	CLASS FILE FOR: MyPPM
	Craigory Coppola
*/

#include <vector>
#include <string>
#include <iostream>
#include <fstream>


MyPPM::MyPPM(std::vector<std::vector<MyRGB>> pixels, std::string fileName){
	std::ofstream OutputFile;
	OutputFile.open(fileName);
	OutputFile << "P3" << "\n"; //Header for PPM
	OutputFile << pixels[0].size() << " " <<pixels.size() << " 255"<< "\n"; //Width -> height
	for(int y = 0; y < pixels.size(); y++){
		for(int x = 0; x < pixels[y].size(); x++){
			OutputFile << pixels[y][x].r << " ";
			OutputFile << pixels[y][x].g << " ";
			OutputFile << pixels[y][x].b << " ";
		}
		OutputFile << "\n";
	}
	OutputFile.close();
}

