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
    SmartArray(const SmartArray& smartArr) // Конструктор копирования
    {
        sizeArr = smartArr.sizeArr;
        currentElement = smartArr.currentElement;
        arr = new int[smartArr.sizeArr]; // Создание нового массива
        for (int i = 0; i < sizeArr; ++i) // Заполнение значениями
        {
            arr[i] = smartArr.arr[i];
        }
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

    // Геттеры
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
    int* getArr() // Получение массива
    {
        return arr;
    }
    int getSize() // Получение размера массива
    {
        return sizeArr;
    }

    SmartArray& operator= (const SmartArray& other) // Переопредление оператора присваивания
    {
        if (&other != this)
        {
            delete[] arr; // Освобождение памяти под теекущий массив
            sizeArr = other.sizeArr; // Присвоение размера из заданного
            currentElement = other.currentElement; // Присвоение текущего элемента из заданного
            arr = new int[sizeArr]; // Создание нового массива
            for (int i = 0; i < sizeArr; ++i) // Заполнение значениями
            {
                arr[i] = other.arr[i];
            }
        }
        return *this; // Возвращение нового массива
    }
};

void printArr(SmartArray& smartArr) // Печать массива
{
    for (int i = 0; i < smartArr.getSize(); ++i)
    {
        std::cout << smartArr.getElement(i) << " ";
    }
    std::cout << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SmartArray arr(5);
    arr.addElement(1);
    arr.addElement(4);
    arr.addElement(155);

    SmartArray arr2(arr);

    printArr(arr);
    printArr(arr2);

    SmartArray new_array(2);
    new_array.addElement(44);
    new_array.addElement(34);

    printArr(new_array);

    arr = new_array;

    printArr(arr);

    return 0;
}