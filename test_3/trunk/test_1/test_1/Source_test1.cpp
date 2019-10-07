
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "Shape.h"

class Square: public IShape
{
public:
	Square() : a(1) {}
	Square(double value1) : a(value1) {}
	virtual ~Square() {}
	//Конкретизация метода Area интерфейса IShape для класса Square
	virtual double Area() { 
		return a * a;
	}
	//сторона квадрата
	double a;
};
class Rectangle : public IShape
{
public:
	Rectangle() : a(1), b(1) {}
	Rectangle(double value1, double value2) : a(value1), b(value2) {}
	virtual ~Rectangle() {}
	//Конкретизация метода Area интерфейса IShape для класса Rectangle
	virtual double Area() {
		return a * b;
	}
	//стороны прямоугольника
	double a;
	double b;
};
class Triangle : public IShape
{
public:
	Triangle() : a(1), b(1), c(1) {}
	Triangle(double value1, double value2, double value3) : a(value1), b(value2), c(value3) {}
	virtual ~Triangle() {}
	//Конкретизация метода Area интерфейса IShape для класса Triangle
	virtual double Area() {
		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	//стороны треугольника
	double a, b, c;
};
class Circle : public IShape
{
public:
	Circle() : r(1) {}
	Circle(double value1) : r(value1) {}
	virtual ~Circle() {}
	//Конкретизация метода Area интерфейса IShape для класса Circle
	virtual double Area() {
		return  M_PI*r*r;
	}
	//радиус круга
	double r;
};

int main()
{
	Square fig1;
	Rectangle fig2(2,5);
	Triangle fig3;
	Circle fig4(2.1);
	std::cout << fig1.Area() << std::endl;
	std::cout << fig2.Area() << std::endl;
	std::cout << fig3.Area() << std::endl;
	std::cout << fig4.Area() << std::endl;
	system("pause");
	return 0;
}