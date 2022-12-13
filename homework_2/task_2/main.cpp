/*
��� ������� ���� ������������ ��� �� ������� ������� � ���� � ���� ��� ������:
- �������������� ������ (20 ������). ������ ������� ���� ��������� ����� � ��������.
- ������������� ������ (15 ������). ����� �������� ������� �������� point_object.m_y � point_object.m_x. ��� ��� ��� ������ ������ x ��������� y � ��������.
- ������ ��������. �� �������� ����������� ��� ��������� point. � ����� �� ������������, � ��� ���.
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