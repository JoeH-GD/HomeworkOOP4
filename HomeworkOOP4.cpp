// HomeworkOOP4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm> //для swap()
#include <cassert> // для assert()
#include <vector>
#include <math.h>

class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr) { }

    ArrayInt(int length) :
        m_length(length)
    {
        assert(length >= 0);

        if (length > 0) {
            m_data = new int[length];
        }
        else {
            m_data = nullptr;
        }
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        // Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
        m_data = nullptr;
        m_length = 0;
    }

    int getLength() { return m_length; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // Функция resize изменяет размер массива. Все существующие элементы сохраняются. Процесс медленный
    void resize(int newLength)
    {
        // Если массив уже нужной длины — return
        if (newLength == m_length) {
            return;
        }

        // Если нужно сделать массив пустым — делаем это и затем return
        if (newLength <= 0) {
            erase();
            return;
        }

        // Теперь знаем, что newLength >0
        // Выделяем новый массив
        int* data = new int[newLength];

        // Затем нужно разобраться с количеством копируемых элементов в новый массив
        // Нужно скопировать столько элементов, сколько их есть в меньшем из массивов
        if (m_length > 0) {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            // Поочередно копируем элементы
            for (int index = 0; index < elementsToCopy; ++index) {
                data[index] = m_data[index];
            }
        }

        // Удаляем старый массив, так как он нам уже не нужен
        delete[] m_data;

        // И используем вместо старого массива новый! Обратите внимание, m_data указывает
        // на тот же адрес, на который указывает наш новый динамически выделенный массив. Поскольку
        // данные были динамически выделенные — они не будут уничтожены, когда выйдут из области видимости
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        // Проверка корректности передаваемого индекса
        assert(index >= 0 && index <= m_length);

        // Создаем новый массив на один элемент больше старого массива
        int* data = new int[m_length + 1];

        // Копируем все элементы до index-а
        for (int before = 0; before < index; ++before) {
            data[before] = m_data[before];
        }

        // Вставляем новый элемент в новый массив
        data[index] = value;

        // Копируем все значения после вставляемого элемента
        for (int after = index; after < m_length; ++after) {
            data[after + 1] = m_data[after];
        }

        // Удаляем старый массив и используем вместо него новый 
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value) { insertBefore(value, m_length); }

    void pop_back() { resize(m_length - 1); }

    void pop_front() {

        int* data = new int[m_length - 1];

        for (int i = 0; i < m_length -1 ; i++)
        {
            data[i] = m_data[i + 1];
        }
        delete[] m_data;
        m_data = data;
        --m_length;
    }


    

    void arraySort()
    {
        for (int iteration = 0; iteration < m_length - 1; ++iteration)
        {
            
            for (int currentIndex = 0; currentIndex < m_length - 1; ++currentIndex)
            {
                
                if (m_data[currentIndex] > m_data[currentIndex + 1])
                    std::swap(m_data[currentIndex], m_data[currentIndex + 1]);
            }
        }
    }

    void arrayPrint()
    {
        for (int i=0; i < m_length; i++)
        {
            std::cout << m_data[i] << std::endl;
        }
    }
};

void countUnique(std::vector<int> vector, size_t size) {
    size_t count = 0;
    for (size_t i = 0; i < size; i++)
    {
        size_t j = 0;
        while (j < i && vector[j] != vector[i]) ++j;

        count += j == i;
    }

    std::cout << "Unique numbers: "<<count << std::endl;
   
}


int main(int argc, char* argv[])
{
    ArrayInt arrayInt;
    arrayInt.push_back(100);
    arrayInt.push_back(0);
    arrayInt.push_back(1);
    arrayInt.push_back(10);
    arrayInt.arraySort();
    arrayInt.arrayPrint();
    std::cout << std::endl;
    arrayInt.pop_back();
    arrayInt.arrayPrint();
    std::cout << std::endl;
    arrayInt.pop_front();
    arrayInt.arrayPrint();
    std::cout << std::endl;
    //===================================================================================================================================


    //SECOND TASK

    //тест не случайных числах
    size_t size = 10;
    std::vector<int> myVector;
    for (size_t i = 0; i < size; i++)
    {
        myVector.push_back(rand());
        std::cout << myVector[i] << " ";
    }
   
    std::cout << std::endl;

    countUnique(myVector, size);

    //тест с повторяющимися числами
    std::vector<int> myVector2;
    myVector2.push_back(2);
    myVector2.push_back(1);
    myVector2.push_back(10);
    myVector2.push_back(1);
    myVector2.push_back(10);
    myVector2.push_back(13);

    countUnique(myVector2, myVector2.size());

    return 0;
}
