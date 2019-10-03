//��� �������
#include <vector>
//��� sort � unique
#include <algorithm>
using namespace std;

struct Point
{
	int x, y, z;
	Point(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
};

//�������� ������ ��� sort
bool operator<(const Point& a, const Point& b)
{
	return a.x < b.x || a.x == b.x && (a.y < b.y || a.y == b.y && a.z < b.z);
}
//�������� �������� �� ��������� ��� unique
bool operator==(const Point& a, const Point& b)
{
	return a.x == b.x && a.y == b.y && a.z == b.z;
}


int main()
{
	vector<Point> p;

	sort(p.begin(), p.end());
	//� ������� ���������
	p.resize(unique(p.begin(), p.end()) - p.begin());
	//��, ������ p �������� ������ ���������� �����
}