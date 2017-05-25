#ifndef LAYER_H
#define LAYER_H

class Layer{
	private:
		int width; //layer width
		int height; //layer height
		std::vector<std::vector<int>> points; //Matrix of points
	public:
		Layer(int, int);
		void setPoint(int, int);
		int getPoint(int, int) const;
		std::vector<std::vector<int>> getPixelMap() const;
		
};

#endif