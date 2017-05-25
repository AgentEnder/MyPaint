/*
	CLASS FILE FOR CANVAS
	Craigory Coppola
*/

#include<vector>
#include<cmath>

#include "canvas.h"

Canvas::Canvas(int w, int h, std::map<int, MyRGB> c){
	width = w;
	height = h;
	colors = c;
	std::vector<std::vector<int>> p(height, std::vector<int>(width, 0)); //Create vector for points
	points = p; //set point matrix to created matrix
	
	createNewLayer();
	activeLayer = 0;
	
	canvasUpdated = false;
	
	std::cout << "New canvas created" << std::endl;
}

void Canvas::createNewLayer(){
	Layer initLayer(width, height);
	layers.push_back(initLayer);
	activeLayer = layers.size()-1;
}

void Canvas::drawRect(int x1, int y1, int w, int h){
	if(x1 < 0){
		w = w+x1;
		x1 = 0;
	}
	if(y1 < 0){
		h = h+y1;
		x1 = 0;
	}
	if(x1 >= width){
		w = 0;
		x1 = 0;
	}
	if(x1 >= height){
		h = 0;
		y1 = 0;
	}
	for(int y = y1; y < y1+h; y++){ // loop through each y from init y to init y + height
		for(int x = x1; x < x1+w; x++){ // loop through each x from init x to init x + width
			layers[activeLayer].setPoint(x, y); // Set bits on active layer for the rectangle
		}
	}
	canvasUpdated = false;
}

void Canvas::drawLine(int x1, int y1, int x2, int y2){
	if(x1 < 0){
		x1 = 0;
	}else if (x1 > width){
		x1 = width;
	}
	if(x2 < 0){
		x2 = 0;
	}else if (x2 > width){
		x2 = width;
	}
	if(y1 < 0){
		y1 = 0;
	}else if (y1 > height){
		y1 = height;
	}
	if(y2 < 0){
		y2 = 0;
	}else if (y2 > width){
		y2 = width;
	}
	double slope = static_cast<double>((y2-y1))/static_cast<double>((x2-x1));
	double yval; //Value of y=mx+b for each x`
	double decimalValue;
	for(int x = x1; x <= x2; x++){
		yval = y1 + (x-x1)*slope; //determine yval at x
		decimalValue = yval - static_cast<int>(yval); //determine decimal part of yval
		if(decimalValue >= 0.45){
			layers[activeLayer].setPoint(x,static_cast<int>(yval)+1);
		}
		if(decimalValue <= 0.55){
			layers[activeLayer].setPoint(x,static_cast<int>(yval));
		}
	}
	canvasUpdated = false;
}

void Canvas::drawCircle(int _x, int _y, int r){
	for(int y = _y-r; y <= _y+r; y++ ){
		for(int x = _x-r; x <= _x + r; x++){
			double distToCenter = sqrt((pow(y-_y,2.0)+pow(x-_x,2.0)));
			if(distToCenter <= r && !(x<0) && !(x>=width) && !(y<0) &&!(y >= height)){
				layers[activeLayer].setPoint(x,y);
				if(distToCenter == 0){
					layers[activeLayer].setPoint(x,y);
				}
			}
		}
	}
	canvasUpdated = false;
}

void Canvas::updateCanvas(){
	for(int i = 0; i < layers.size(); i++){ //Loop through each layer
		for(int y = 0; y < height; y++){ //Loop through each row of pixels
			for(int x = 0; x < width; x++){ //Loop through each column
				int p = layers[i].getPoint(x, y);
				if(p > 0){ //If layer bit not set, should be transparent
					points[y][x] = p; //update point matrix to opaque bit
				}
			}
		}
	}
}

void Canvas::displayCanvas(){
	if(!canvasUpdated){
		updateCanvas();
		canvasUpdated = true;
	}
	for(int y = 0; y < height; y++){ //Loop through each row of pixels
		for(int x = 0; x < width; x++){ //Loop through each column
			std::cout << points[y][x];
		}
		std::cout << std::endl;
	}
	
	std::cout<<std::endl<<std::endl;
}

std::vector<std::vector<MyRGB>> Canvas::getColorMap(){
	if(!canvasUpdated){
		updateCanvas();
		canvasUpdated = true;
	}
	std::vector<std::vector<MyRGB>> colorMap(height, std::vector<MyRGB>(width));
	for(int y = 0; y < height; y++){
		for(int x = 0; x < width; x++){
			int point = points[y][x];
			colorMap[y][x] = colors[point];
		}
	}
	return colorMap;
}

void Canvas::setGrayscaleColorPallate(){
	int maxNumber = 0;
	colors.clear();
	for(int y = 0; y < height; y++){
		for(int x = 0; x < height; x++){
			if(points[y][x] > maxNumber){
				maxNumber = points[y][x];
			}
		}
	}
	for(int i = 0; i < maxNumber; i++){
		MyRGB scaleColor;
		scaleColor.r = (255*i)/maxNumber;
		scaleColor.g = (255*i)/maxNumber;
		scaleColor.b = (255*i)/maxNumber;
		colors[i] = scaleColor;
	}
}