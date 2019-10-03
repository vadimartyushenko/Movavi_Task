//для вектора
#include <vector>
//для sort и unique
#include <algorithm>
using namespace std;

struct Point
{
	int x, y, z;
	Point(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
};

//оператор меньше для sort
bool operator<(const Point& a, const Point& b)
{
	return a.x < b.x || a.x == b.x && (a.y < b.y || a.y == b.y && a.z < b.z);
}
//оператор проверки на равенство для unique
bool operator==(const Point& a, const Point& b)
{
	return a.x == b.x && a.y == b.y && a.z == b.z;
}


int main()
{
	vector<Point> p;

	sort(p.begin(), p.end());
	//и удаляем дубликаты
	p.resize(unique(p.begin(), p.end()) - p.begin());
	//всё, теперь p содержит только уникальные точки
}