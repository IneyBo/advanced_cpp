#include <Windows.h>

#include <iostream>

class SmartArray // Класс  умный массив
{
private:
	int sizeArr; // Заданный размер массива
    int currentElement; // Индекс добавляемого элемента
	int* arr; // Массив
public:
    SmartArray(int number) // Конструктор
    {
        sizeArr = number;
        currentElement = 0;
        arr = new int[number]();
    }
    ~SmartArray() // Деструктор
    {
        delete[] arr;
    }
    void addElement(int element) // Добавление элемента
    {
        if (currentElement >= sizeArr) // Если количество элементов больше количества элементов, на которую выделена память
        {
            throw std::exception("Попытка добавления элемента в уже заполненный массив");
        }
        else // Иначе добавляю элемент
        {
            arr[currentElement++] = element;
        }
    }
    int getElement(int index) // Получение элемента массива
    {
        if (index >= sizeArr || index < 0) // Проверка на корректность индекса
        {
            throw std::exception("Элемента с данным индексом нет в массиве");
        }
        else
        {
            return arr[index];
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        SmartArray arr(5);
        arr.addElement(1);
        arr.addElement(4);
        arr.addElement(155);
        arr.addElement(14);
        arr.addElement(15);
        std::cout << arr.getElement(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}