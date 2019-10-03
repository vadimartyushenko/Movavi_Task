#include <iostream>
#include "Shape.h"

class Square: public IShape
{
public:
	Square() : a(2) 
	{}
	virtual ~Square() {}
	//������������� ������ Area ���������� IShape ��� ������ Square
	virtual double Area() { 
		return a * a;
	}
	//������� ��������
	double a;
};
int main()
{
	Square fig;
	std::cout << fig.Area() << std::endl;
	system("pause");
	return 0;
}