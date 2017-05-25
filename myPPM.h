/*
 	Header for: MyPPM
	Craigory Coppola
*/

#ifndef MYPPM_H
#define MYPPM_H

class MyPPM{
	private:
		int width;
		int height;
	public:
		MyPPM(std::vector<std::vector<MyRGB>>, std::string); //Custom constructor, takes vector<vector<MyRGB>>
};

#endif