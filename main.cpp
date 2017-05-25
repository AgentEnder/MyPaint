/*
	My Paint
	Craigory Coppola
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#include "myRGB.h" //MUST BE LOADED FIRST
#include "myPPM.h" //MUST LOAD BEFORE CANVAS
#include "myPPM.cpp" //MUST LOAD BEFORE CANVAS
#include "layer.h" //MUST LOAD BEFORE CANVAS
#include "layer.cpp" //MUST LOAD BEFORE CANVAS
#include "canvas.h"
#include "canvas.cpp"

using namespace std;

void waitForUserInput();
void clearConsole();
int convertStringToNumber(string);


int main(){
	//Initialization
	enum MenuStates {MAINMENU, DRAWRECT, DRAWLINE, DRAWCIRCLE, ADDLAYER,SAVECANVAS, NEWCANVAS};
	MenuStates m = NEWCANVAS;
	bool programRunning = true;
	map<int, MyRGB> colors;
	MyRGB color1;
	color1.r = 255*10/10;
	color1.g = 255*10/10;
	color1.b = 255*10/10;
	colors[0] = color1;
	MyRGB color2;
	color2.r = 255*8/10;
	color2.g = 255*8/10;
	color2.b = 255*8/10;
	colors[4] = color2;
	MyRGB color3;
	color3.r = 255*6/10;
	color3.g = 255*6/10;
	color3.b = 255*6/10;
	colors[3] = color3;
	MyRGB color4;
	color4.r = 255*4/10;
	color4.g = 255*4/10;
	color4.b = 255*4/10;
	colors[2] = color4;
	MyRGB color5;
	color5.r = 255*0/10;
	color5.g = 255*0/10;
	color5.b = 255*0/10;
	colors[1] = color5;
	// STARTUP
	int w;
	int h;
	
	
	Canvas mainCanvas(0,0,colors);
	//STARTUP COMPLETE
	while(programRunning){
		switch(m){
			case MAINMENU:{
				clearConsole();
				mainCanvas.displayCanvas(); //Main canvas is initalized before mainmenu is displayed
				cout << "Would you like to:" << endl; //Display Menu Options
				cout << "(1)Draw a rectangle," << endl; //Rectangle Options
				cout << "(2)Draw a line," << endl; //Line Options
				cout << "(3)Draw a circle," << endl; //Circle Options
				cout << "(4)Add a layer," << endl; //Layer Options
				cout << "(5)Save your canvas," << endl; //Save Options
				cout << "(6)Start a new canvas," << endl; //Save Options
				cout << "(7)Exit the program" << endl << endl;
				
				string userChoice; //Variable to hold user's raw input.
				int integerChoice; //Variable to hold integer formed by parsing raw input
				cin >> userChoice; //Get raw Input
				
				integerChoice = convertStringToNumber(userChoice); //Parse raw input and store it in container
				
				if(integerChoice == 7){ //If choice is 7, program should exit!
					clearConsole(); //Clear out the menu
					programRunning = false; //Exit the Infinite Loop
				}else if (1 <= integerChoice && integerChoice <= 6){ //Valid menu state range
					m = static_cast<MenuStates>(integerChoice); //Set menu state to user choice
				}
				
				break;
			}
			case DRAWRECT:{
				clearConsole();
				mainCanvas.displayCanvas();
				int x1,y1,w,h;
				cout << "Enter the first co-ordinates, with a space between each ordinate." << endl;
				cin >> x1;
				cin >> y1;
				cout << "Enter the width and height, with a space between each dimension." << endl;
				cin >>w;
				cin >>h;
				mainCanvas.drawRect(x1,y1,w,h);
				m = MAINMENU;
				break;
			}
			case DRAWLINE:{
				clearConsole();
				mainCanvas.displayCanvas();
				int x1,y1,x2,y2;
				cout << "Enter the first co-ordinates, with a space between each ordinate." << endl;
				cin >> x1;
				cin >> y1;
				cout << "Enter the second co-ordinates, with a space between each ordinate." << endl;
				cin >>x2;
				cin >>y2;
				mainCanvas.drawLine(x1,y1,x2,y2);
				m = MAINMENU;
				break;
			}
			case DRAWCIRCLE:{
				clearConsole();
				mainCanvas.displayCanvas();
				int x1,y1,r;
				cout << "Enter the first co-ordinates, with a space between each ordinate." << endl;
				cin >> x1;
				cin >> y1;
				cout << "Enter the radius of the circle." << endl;
				cin >>r;
				mainCanvas.drawCircle(x1,y1,r);
				m = MAINMENU;
				break;
			}
			case ADDLAYER:{
				mainCanvas.createNewLayer();
				m = MAINMENU;
				break;
			}
			case NEWCANVAS:{
				clearConsole(); //Refresh console display
				cout << "How wide of a canvas would you like?" << endl; //Query the user
				cin >> w; //Store Width
				cout << "How tall of a canvas would you like?" << endl; //Query the user
				cin >> h; //Store height
				mainCanvas = Canvas(w, h, colors); //Reinitialize the mainCanvas
				m = MAINMENU; //Go back to the main menu
				break;
			}
			case SAVECANVAS:{
				mainCanvas.setGrayscaleColorPallate();	
				MyPPM testImage(mainCanvas.getColorMap(), "testImage.ppm");
				m = MAINMENU;
				break;
			}
			default:{
				break;
			}
		}
	}
	return 0;
}

void waitForUserInput(){
	system("PAUSE"); //Abstracted function for readability in code and easy refactoring.
}

void clearConsole(){
	system("cls"); //Abstracted function for readability in code and system dependance.
}


//This function uses a stringstream object to convert text to an integer.
int convertStringToNumber(string i){
	string text = i;//string containing the number
	int result;//number which will contain the result

	stringstream convert(text); // stringstream used for the conversion initialized with the contents of Text

	if ( !(convert >> result) ){//give the value to Result using the characters in the string
		result = 0;
	}
	return result;
}