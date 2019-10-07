#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

int main()
{
	FILE* pFile;
	double f = 12.23;
	pFile = fopen("myfile1.dat", "wb");
	if (pFile != NULL)
	{
		fwrite(&f, sizeof(double), 1, pFile);
		fclose(pFile);
	}
	else
		std::cout << "File is not opened" << std::endl;
	std::system("pause");
	return 0;
}