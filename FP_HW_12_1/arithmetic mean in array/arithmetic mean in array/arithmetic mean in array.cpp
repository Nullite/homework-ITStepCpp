#include <iostream>

template <typename T, typename N> 
void initArray(T array[], N size)
{
    srand(time(nullptr));
    for (int i = 0; i < size; i++)
    array[i] = rand() % 100 - 50;
        
}

template <typename T, typename N>
void showArray(T array, N size)
{
    std::cout << "random Generated Array: ";

    for (int i = 0; i < size; i++)
    std::cout << array[i] << " ";
    
    std::cout << "\n\n";
}

template <typename T, typename N>
T calculateArithmeticMean(T array[], N size)
{
    auto sum = 0;
    for (int i = 0; i < size; i++) 
        sum += array[i];

    return sum / (double)size;
}

template <typename T>
void showArithmeticMean(T arithmeticMean)
{
    std::cout << "arithmeticMean from this Array is: " << arithmeticMean << "\n";
}

int main()
{
    const int size = 10;
    double arr[size];

    initArray(arr, size);
    showArray(arr, size);
    auto arithmeticMean = calculateArithmeticMean(arr, size);
    showArithmeticMean(arithmeticMean);
}

