#include "Point2D.h"

Point2D::Point2D(double x = 0, double y = 0) : x{x}, y{y} {}

bool operator==(const Point2D &a, const Point2D &b){
	return a.x == b.x && a.y ==b.x;
}

bool operator!=(const Point2D &a, const Point2D &b){
	return a.x != b.x || a.y != b.y;
}

std::ostream& operator<<(std::ostream &out, const Point2D &p){
	out << "El punto tiene las coordenadas: (" << p.x << "," << p.y << ")";
	return out;
}
