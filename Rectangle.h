#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <stdexcept>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape{
	private:
		static bool check(Point2D* vertices){
			return Point2D::distance(vertices[0], vertices[2]) == 
				Point2D::distance(vertices[1], vertices[3]);
		}

	protected:
		Point2D* vs;

	public:
		static int const N_VERTICES = 4;
		Rectangle();
		Rectangle(std::string color, Point2D* vertices);
		Rectangle(const Rectangle &r);
		~Rectangle();
		Point2D get_vertex(int ind) const;
		Point2D operator[](int ind) const;
		virtual void set_vertices(Point2D* vertices);
		Rectangle& operator=(const Rectangle &r);
		friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);
		double area() const override;
		double perimeter() const override;
		void translate(double incX, double incY) override;
		void print() override;
};

#endif
