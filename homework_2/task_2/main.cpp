/*
Для примера взял исправленный код из первого задания и внес в него три ошибки:
- Синтактическая ошибка (20 строка). Вместо запятых надо поставить точки с запятыми.
- Семантическая ошибка (15 строка). Нужно поменять мечтами элементы point_object.m_y и point_object.m_x. Так как при выводе вместо x выводится y и наоборот.
- Ошибка линковки. Не прописан конструктор для структуры point. В мэйне он используется, а его нет.
*/

#include <iostream>

struct point {
	int m_x;
	int m_y;
};

void print_point(const point& point_object) {
	std::cout << "x:" << point_object.m_y << ", y: " << point_object.m_x << std::endl;
}

int main()
{
	for (int i = 0, i < 5, i++) {
		point my_point(i, 2 * i);
		print_point(my_point);
	}
	return 0;
}