#include "Rectangle.h"

Rectangle::Rectangle(){
	vs = new Point2D[N_VERTICES];
	vs[0] = Point2D(-1, 0.5);
	vs[1] = Point2D(1, 0.5);
	vs[2] = Point2D(1, -0.5);
	vs[3] = Point2D(-1, -0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color){
	if(Rectangle::check(vertices)){
		vs = new Point2D[N_VERTICES];
		for(int i = 0; i < N_VERTICES; i++){
			vs[i] = vertices[i];
		}
	}else{
		throw std::invalid_argument("Rectángulo incorrecto");
	}
}

Rectangle::Rectangle(const Rectangle &r){
	vs = new Point2D[N_VERTICES];
	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = r.vs[i];
	}
	std::string color = r.get_color();
	set_color(color);
}

Rectangle::~Rectangle(){
	delete vs;
}

Point2D Rectangle::get_vertex(int ind) const{
	if(ind >= 0 && ind < N_VERTICES){
		return vs[ind];
	}else{
		throw std::out_of_range("Índice fuera de rango");
	}
}

Point2D Rectangle::operator[](int ind) const{
	return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* vertices){
	if(Rectangle::check(vertices)){
		for(int i = 0; i < N_VERTICES; i++){
			this->vs[i] = vertices[i];
		}
	}else{
		throw std::invalid_argument("Vértices inválidos");
	}
}

Rectangle& Rectangle::operator=(const Rectangle &r){
	this->~Rectangle();
	vs = new Point2D[N_VERTICES];
	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = r.vs[i];
	}
	return *this;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r){
	out << "Rectangle: Color: " << r.get_color();
	for(int i = 0; i < Rectangle::N_VERTICES; i++){
		out << " v[" << i << "] = (" << r.vs[i].x << ", " << r.vs[i].y << ")";
	}
	return out;
}

double Rectangle::area() const{
	return (Point2D::distance(this->vs[0],this->vs[1])) *
	       (Point2D::distance(this->vs[1],this->vs[2]));
}

double Rectangle::perimeter() const{
	return 2 * (Point2D::distance(this->vs[0],this->vs[1])) +
	       2 * (Point2D::distance(this->vs[1],this->vs[2]));
}

void Rectangle::translate(double incX, double incY){
	for(int i = 0; i < N_VERTICES; i++){
		this->vs[i].x += incX;
		this->vs[i].y += incY;
	}
}

void Rectangle::print(){
	std::cout << *this;
}
