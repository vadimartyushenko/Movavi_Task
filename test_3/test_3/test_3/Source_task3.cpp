#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
#include <ctime>
#include <chrono>

int main()
{
	std::mt19937 gen{ static_cast<unsigned>(std::time(nullptr)) };// �������� ���������� ��������������� �����
	std::uniform_int_distribution<> dist(1, 100);//���������� ������������� � ��������� [1, 10]
	std::vector<int> v(10000000);
	std::generate(v.begin(), v.end(), std::bind(dist, gen));//��������� ������ 
	std::cout << "Initial vector" << std::endl;
	//for (int i : v) std::cout << i << " ";
	std::cout << "\n-----------------------------------\n";
	auto start = std::chrono::high_resolution_clock::now();//�������� ����� ������
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());
	auto end = std::chrono::high_resolution_clock::now();//�������� ����� �����
	std::cout << "Unique vector" << std::endl;
	//for (int i : v) std::cout << i << " ";
	std::cout << "\n-----------------------------------\n";
	std::chrono::duration<float> time_chrono = end - start;
	std::cout << "Algorithm running time: "<< time_chrono.count() << " seconds" << std::endl;
	return 0;
}