#include <Windows.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <variant>

std::variant<int, std::string, std::vector<int>> get_variant()
{
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	auto variant1 = get_variant(); // Инициализирую переменную

	if (std::holds_alternative<int>(variant1)) // Если переменная получилась типа int
	{
		std::cout << std::get<int>(variant1) * 2;
	}
	else if (std::holds_alternative<std::string>(variant1)) // Если переменная получилась типа std::string
	{
		std::cout << std::get<std::string>(variant1);
	}
	else if (std::holds_alternative<std::vector<int>>(variant1)) // Если переменная получилась типа std::vector
	{
		std::vector vector1 = std::get<std::vector<int>>(variant1);
		std::for_each
		(vector1.begin(), vector1.end(),
			[](const int& n)
			{
				std::cout << n << " ";
			});
	}
}