#include <iostream>
#include <algorithm>
int sizeOfFirstArray;
int size = 0;
int step = 0;

int* initArray()
{
    size = 1 + rand() % 10;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = 1 + rand() % 20;
    }

    std::sort(arr, arr + size);
    return arr;
}

void showArray(int* arr)
{
    switch (step)
    {
    case 0:
        std::cout << "sorted random array first: ";
        break;
    case 1:
        std::cout << "sorted random array second: ";
        break;
    case 2:
        std::cout << "merged array: ";
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";
}

int* mergeSortedArrays(int* arr1, int* arr2, int size1, int size2)
{
    int arrSize = size1 + size2;
    int* arr = new int[arrSize];
    int* index = arr;
    int* pArr1 = arr1;
    int* pArr2 = arr2;

    for (; index < &arr[arrSize];)
    {
        if (pArr1 > &arr1[size1 - 1])
        {
            *index = *pArr2;
            pArr2++;
            index++;
            continue;
        }
        if (pArr2 > &arr2[size2 - 1])
        {
            *index = *pArr1;
            pArr1++;
            index++;
            continue;
        }

        if (*pArr1 == *pArr2)
        {
            *index = *pArr1;
            index++;
            *index = *pArr2;
            index++;
            pArr1++;
            pArr2++;
            continue;
        }

        if (*pArr1 < *pArr2)
        {
            *index = *pArr1;
            index++;
            pArr1++;
            continue;
        }
        if(*pArr2 < *pArr1)
        {
            *index = *pArr2;
            index++;
            pArr2++;
            continue;
        }
    }
    return arr;
}

int main()
{
    srand(time(nullptr));
    int* arr1 = initArray();
    showArray(arr1);
    sizeOfFirstArray = size;
    step++;
    int* arr2 = initArray();
    showArray(arr2);
    step++;
    int* mergedArr = mergeSortedArrays(arr1, arr2, sizeOfFirstArray, size);
    delete[] arr1;
    delete[] arr2;
    size += sizeOfFirstArray;
    showArray(mergedArr);
    delete[] mergedArr;
}
