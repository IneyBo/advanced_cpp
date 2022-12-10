#include <Windows.h>

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector<int> arr1{ 4, 7, 9, 14, 12 };

	std::cout << "Входные данные: ";

	std::for_each
	(arr1.begin(), arr1.end(),
		[](const int& n)
		{
			std::cout << n << " ";
		});

	std::cout << std::endl << "Выходные данные: ";

	std::for_each
	(arr1.begin(), arr1.end(),
		[](const int& n)
		{
			if (n % 2 != 0)
			{
				std::cout << n * 3 << " ";
			}
			else
			{
				std::cout << n << " ";
			}
		});

	return 0;
}