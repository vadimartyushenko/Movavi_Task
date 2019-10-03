#include <iostream>
#include "Shape.h"

class Square: public IShape
{
public:
	Square() : a(2) 
	{}
	virtual ~Square() {}
	//Конкретизация метода Area интерфейса IShape для класса Square
	virtual double Area() { 
		return a * a;
	}
	//сторона квадрата
	double a;
};
int main()
{
	Square fig;
	std::cout << fig.Area() << std::endl;
	system("pause");
	return 0;
}