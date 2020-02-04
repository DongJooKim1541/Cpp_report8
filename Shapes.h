#ifndef SHAPES_H
#define SHAPES_H
class Shape {
protected:
	int x, y;
public:
	Shape(int x1 = 0, int y1 = 0) {
		x = x1;
		y = y1;
	}
	Shape(const Shape& s);
	Shape& operator=(const Shape& other);
	virtual ~Shape();
	virtual void Draw();
};

class Circle :public Shape {
private:
	int radius;
public:
	Circle(int x1 = 0, int y1 = 0, int radius1 = 0)
		:Shape(x1, y1)
	{
		radius = radius1;
	}
	Circle(const Circle& c);
	Circle& operator=(const Circle& other);
	~Circle();
	void Draw();
};

class Rectangle :public Shape {
private:
	int width, height;
public:
	Rectangle(int x1 = 0, int y1 = 0, int width1 = 0, int height1 = 0)
		:Shape(x1, y1)
	{
		width = width1;
		height = height1;
	}
	Rectangle(const Rectangle& r);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle();
	void Draw();
};
#endif