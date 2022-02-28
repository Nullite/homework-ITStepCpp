#include <iostream>
#include <algorithm>

int tempSize;
int size1;
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
    return arr;
}

void showArray(int* arr)
{
    switch (step)
    {
    case 0:
        std::cout << "random array first: ";
        break;
    case 1:
        std::cout << "random array second: ";
        break;
    case 2:
        std::cout << "array contains both arrays elements: ";
        break;
    case 3:
        std::cout << "common elements of both arrays: ";
        break;
    case 4:
        std::cout << "unique elements of first array: ";
        break;
    case 5: 
        std::cout << "unique elements of second array: ";
        break;
    case 6:
        std::cout << "unique elements of both arrays: ";
    }
    
    
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";
}
int* mergeArrays(int* arr1, int* arr2, int sizeF, int sizeS)
{
    int ArraySize = sizeF + sizeS;
    int* arr = new int[ArraySize];
    int* pArr1 = arr1;
    int* pArr2 = arr2;
    int* index = arr;

    for (; index < &arr[ArraySize]; index++)
    {
        if (pArr1 < &arr1[sizeF])
        {
            *index = *pArr1;
            pArr1++;
        }
        else
        {
            *index = *pArr2;
            pArr2++;
        }
    }
    size = ArraySize;
    return arr;
}

int* commonElements(int* arr1, int* arr2, int sizeF, int sizeS)
{
    int arraySize = 0;
    int* arr = new int[arraySize];

    std::sort(arr1, arr1 + sizeF);
    std::sort(arr2, arr2 + sizeS);

    int* pArr1 = arr1;
    int* pArr2 = arr2;

    for (; ;)
    {
        if (pArr1 > &arr1[sizeF - 1] || pArr2 > &arr2[sizeS - 1])
            break;

        if (*pArr1 == *pArr2)
        {
            arraySize++;
            int* temp = new int[arraySize];
            for (int i = 0; i < arraySize - 1; i++)
                temp[i] = arr[i];
            temp[arraySize - 1] = *pArr1;
            delete[] arr;
            arr = temp;
            temp = nullptr;
            pArr1++;
            pArr2++;
        }
        else if (*pArr1 > *pArr2)
            pArr2++;

        else 
            pArr1++;
    }
    size = arraySize;
    return arr;
}
int* uniqueElements(int* arr1, int* arr2, int sizeF, int sizeS)
{
    int arraySize = 0;
    int* arr = new int[arraySize];
    int* pArr2 = arr2;
    int* pArr1 = arr1;

    for (; pArr1 < &arr1[sizeF];)
    {

        if (*pArr1 == *pArr2)
        {
            pArr1++;
            continue;
        }
        if (*pArr2 > *pArr1)
        {

            arraySize++;
            int* temp = new int[arraySize];
            for (int i = 0; i < arraySize - 1; i++)
                temp[i] = arr[i];
            temp[arraySize - 1] = *pArr1;
            delete[] arr;
            arr = temp;
            temp = nullptr;
            pArr1++;
            continue;
        }
        if (*pArr2 < *pArr1)
        {
            pArr2++;
            continue;
        }


    }
    size = arraySize;
    return arr;
}
int* uniqueElementsBoth(int* arr1, int* arr2, int sizeF, int sizeS)
{
    int arraySize = 0;
    int* arr = new int[arraySize];
    int* pArr2 = arr2;
    int* pArr1 = arr1;

    for (; pArr1 < &arr1[sizeF];)
    {

        if (*pArr1 == *pArr2)
        {
            pArr1++;
            continue;
        }
        if (*pArr2 > *pArr1)
        {

            arraySize++;
            int* temp = new int[arraySize];
            for (int i = 0; i < arraySize - 1; i++)
                temp[i] = arr[i];
            temp[arraySize - 1] = *pArr1;
            delete[] arr;
            arr = temp;
            temp = nullptr;
            pArr1++;
            continue;
        }
        if (*pArr2 < *pArr1)
        {
            pArr2++;
            continue;
        }


    }

    pArr2 = arr2;
    pArr1 = arr1;

    for (; pArr2 < &arr2[sizeS];)
    {
        if (*pArr2 == *pArr1)
        {
            pArr2++;
            continue;
        }

        if (*pArr1 > *pArr2)
        {
            arraySize++;
            int* temp = new int[arraySize];
            for (int i = 0; i < arraySize - 1; i++)
                temp[i] = arr[i];
            temp[arraySize - 1] = *pArr2;
            delete[] arr;
            arr = temp;
            temp = nullptr;
            pArr2++;
            continue;
        }

        if (*pArr1 < *pArr2)
        {
            pArr1++;
            continue;
        }
    }



    size = arraySize;
    return arr;
}


int main()
{
    srand(time(nullptr));
    int* arr1 = initArray();
    showArray(arr1);
    size1 = size;
    step++;
    int* arr2 = initArray();
    showArray(arr2);
    step++;
    tempSize = size;
    int* arr3 = mergeArrays(arr1, arr2, size1, size);
    showArray(arr3);
    delete[] arr3;
    size = tempSize;
    arr3 = commonElements(arr1, arr2, size1, size);
    step++;
    showArray(arr3);
    delete[] arr3;
    size = tempSize;
    arr3 = uniqueElements(arr1, arr2, size1, size);
    step++;
    showArray(arr3);
    delete[] arr3;
    size = tempSize;
    arr3 = uniqueElements(arr2, arr1, size, size1);
    step++;
    showArray(arr3);
    delete[] arr3;
    size = tempSize;
    arr3 = uniqueElementsBoth(arr1, arr2, size1, size);
    step++;
    showArray(arr3);
    delete[] arr3;
    size = tempSize;
    delete[] arr1;
    delete[] arr2;
}
