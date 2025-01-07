#include <iostream>

template <class T>
void selectionSort(T* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minElementIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minElementIndex])
                minElementIndex = j;
        }

        if (i != minElementIndex)
            std::swap(arr[i], arr[minElementIndex]);
    }
}

template <class T>
void insertionSort(T* arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        T element = arr[i];
        int index = i - 1;
        while (index >= 0 && arr[index] > element)
        {
            arr[index + 1] = arr[index];
            index--;
        }
        arr[index + 1] = element; // Inserting the element at the correct position
    }
}

template <class T>
void bubbleSort(T* arr, unsigned len)
{
    unsigned end = len - 1;
    for (int i = 0; i < len; i++)
    {
        unsigned lastSwappedIndex = 0;

        for (int j = 0; j < end; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                lastSwappedIndex = j;
            }
        }

        end = lastSwappedIndex;
        if (lastSwappedIndex == 0) // Is the array already sorted?
            return;
    }
}

