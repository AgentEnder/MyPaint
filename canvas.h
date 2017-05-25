/* 
	Header for canvas class 
	Craigory Coppola
*/

#ifndef CANVAS_H
#define CANVAS_H

class Canvas{
	private:
		int width; //canvas width
		int height; //canvas height
		std::map<int, MyRGB> colors;
		bool canvasUpdated;
		std::vector<std::vector<int>> points; //Matrix of points
		std::vector<Layer> layers; //list of each layer
		int activeLayer; //index of active layer
	public:
		Canvas(int, int, std::map<int, MyRGB>); //Constructor (args = width and height)
		void createNewLayer(); //Add a new layer
		void setActiveLayer(int); //set active layer to int
		void drawRect(int, int, int, int); //args = x & y coords + w & h
		void drawLine(int, int, int, int); //args = x & y coords
		void drawCircle(int, int, int); //args = x & y coords + radius
		void updateCanvas(); //Update the canvas based on each layer
		void displayCanvas(); //Draw points (currently through cout <<)
		std::vector<std::vector<MyRGB>> getColorMap(); //return vector<vector<MyRGB>
		void setGrayscaleColorPallate();
};

#endif