#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
#include <ctime>

int main()
{
	std::clock_t t;
	std::mt19937 gen{ static_cast<unsigned>(std::time(nullptr)) };// создание генератора псевдослучайных чисел
	std::uniform_int_distribution<> dist(1, 10);//раномерное распределение в диапазоне [1, 10]
	std::vector<int> v(10);
	std::generate(v.begin(), v.end(), std::bind(dist, gen));//заполняем вектор 
	std::cout << "Initial vector" << std::endl;
	//for (int i : v) std::cout << i << " ";
	std::cout << "\n-----------------------------------\n";
	t = clock();
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());
	t = clock() - t;
	std::cout << "Unique vector" << std::endl;
	//for (int i : v) std::cout << i << " ";
	std::cout << "\n-----------------------------------\n";
	std::cout << "Algorithm running time: " << t << " clicks, " << ((double)t / CLOCKS_PER_SEC) << " seconds" << std::endl;
	return 0;
}