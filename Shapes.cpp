#include <iostream>
#include "Shapes.h"
using namespace std;
Shape::Shape(const Shape& s) {
	x = s.x; y = s.y;
}
Shape& Shape::operator=(const Shape& other) {
	if (this != &other) {
		x = other.x; y = other.y;
	}
	return *this;
}
Shape::~Shape() {

}
void Shape::Draw() {
	cout << "[Shape] x = " << x << " y = " << y << endl;
}

Circle::Circle(const Circle& c) 
	:Shape(c)
{
	radius = c.radius;
}
Circle& Circle::operator=(const Circle& other) {
	if (this != &other) {
		x = other.x; y = other.y; radius = other.radius;
	}
	return *this;
}
Circle::~Circle() {

}
void Circle::Draw() {
	cout << "[Circle] x = " << x << " y = " << y;
	cout << " radius = " << radius << endl;
}

Rectangle::Rectangle(const Rectangle& r)
	:Shape(r) 
{
	width = r.width; height = r.height;
}
Rectangle& Rectangle::operator=(const Rectangle& other) {
	if (this != &other) {
		x = other.x; y = other.y;
		width = other.width; height = other.height;
	}
	return *this;
}
Rectangle::~Rectangle() {

}
void Rectangle::Draw() {
	cout << "[Rectangle] x = " << x << " y = " << y;
	cout << " width = " << width << " height = " << height << endl;
}