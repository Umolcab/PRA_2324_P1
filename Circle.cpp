#include "Circle.h"

Circle::Circle(){
	Shape::Shape();
	center.x = 0;
	center.y = 0;
	radius = 1;
}

Circle::Circle(std::string color, Point2D center, double radius){
	Shape::Shape(color);
	this->center.x = center.x;
	this->center.y = center.y;
	this->radius = radius;
}
