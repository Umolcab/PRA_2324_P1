#include "Drawing.h"

Drawing::Drawing(){
	shapes = new ListLinked<Shape*>;
}

Drawing::~Drawing(){
	delete shapes;
}

void Drawing::add_front(Shape* shape){
	shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape){
	shapes->append(shape);
}

void Drawing::print_all(){
	for(int i = 0; i < shapes->size(); i++){
		if(Circle* c = dynamic_cast<Circle*>(shapes->get(i))){
			c->print();
		}else if(Square* s = dynamic_cast<Square*>(shapes->get(i))){
			s->print();
		}else if(Rectangle* r = dynamic_cast<Rectangle*>(shapes->get(i))){
			r->print();
		}
		std::cout << std::endl;
	}
}

double Drawing::get_area_all_circles(){
	double areas = 0;
	for(int i = 0; i < shapes->size(); i++){
		if(Circle* c = dynamic_cast<Circle*>(shapes->get(i))){
			areas += c->area();
		}
	}
	return areas;
}

void Drawing::move_squares(double incX, double incY){
	for(int i = 0; i < shapes->size(); i++){
		if(Square* s = dynamic_cast<Square*>(shapes->get(i))){
			s->translate(incX, incY);
		}
	}
}
