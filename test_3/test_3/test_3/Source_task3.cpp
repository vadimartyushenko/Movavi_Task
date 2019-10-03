#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

int main()
{

	// �������� ���������� �� �������
	std::vector<int> v{ 1,2,3,1,2,3,3,4,5,4,5,11,6,7 };
	std::cout << "Initial vector" << std::endl;
	for (int i : v)
		std::cout << i << " ";
	std::cout << std::endl;
	std::sort(v.begin(), v.end()); // 1 1 2 2 3 3 3 4 4 5 5 6 7 11
	for (int i : v)
		std::cout << i << " ";
	std::cout << std::endl;
	auto last = std::unique(v.begin(), v.end());
	//������� ��� ��������������� ������������� �������� �� ��������� [v.begin(), v.end()) � ���������� �������� �� 
	//�������, ��������� �� ��������� ��������� ������ ���������. 
	// v ������ �������� {1 2 3 4 5 6 7 11 x x x x x x}, ��� 'x' ���������� ������������� �������
	v.erase(last, v.end());
	for (int i : v)
		std::cout << i << " ";
	std::cout << std::endl;
}