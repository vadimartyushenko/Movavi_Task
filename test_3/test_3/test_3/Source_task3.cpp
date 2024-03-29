#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
#include <ctime>
#include <chrono>

const int N = 1000000;

int main()
{
	std::mt19937 gen{static_cast<unsigned>(std::time(nullptr))};// �������� ���������� ��������������� �����
	std::uniform_int_distribution<> dist(1, 10);//����������� ������������� � ��������� [1, 10]
	std::vector<int> v(N);
	std::generate(v.begin(), v.end(), std::bind(dist, gen));//��������� ������ 
	std::cout << "Initial vector" << std::endl;
	//for (int i : v) std::cout << i << " ";
	std::cout << "\n-----------------------------------\n"; 
	std::sort(v.begin(), v.end());
	auto start = std::chrono::high_resolution_clock::now();//�������� ����� ������
	v.erase(std::unique(v.begin(), v.end()), v.end());
	auto end = std::chrono::high_resolution_clock::now();//�������� ����� �����
	std::cout << "Unique vector" << std::endl;
	//for (int i : v) std::cout << i << " ";
	std::cout << "\n-----------------------------------\n";
	std::chrono::duration<float> time_chrono = end - start;
	std::cout << "Algorithm running time: "<< time_chrono.count() << " seconds" << std::endl;
	return 0;
}