/*
	CLASS FILE FOR LAYER
*/

#include<vector>

#include "layer.h"

Layer::Layer(int w, int h){
	width = w;
	height = h;
	
	std::vector<std::vector<int>> p(height, std::vector<int>(width, 0)); //Create vector for points
	points = p; //set point matrix to created matrix
}

void Layer::setPoint(int x, int y){
	points[y][x] = points[y][x] + 1;
}

int Layer::getPoint(int x, int y) const{
	return points[y][x];
}

std::vector<std::vector<int>> Layer::getPixelMap() const{
	return points;
}