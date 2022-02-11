#include <iostream>
#include <random>

struct Elements
{
    Elements()
    {
        this->neagative = 0;
        this->positive = 0;
        this->zero = 0;
    }
    int neagative;
    int positive;
    int zero;
};

void initArray(long array[], long size)
{
    std::mt19937 rand(::time(0));
    for (int i = 0; i < size; i++)
        array[i] = rand() % 100 - 50;

}


void showArray(long array[], long size)
{
    std::cout << "Random Generated Array: ";

    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";

    std::cout << "\n\n";
}

struct Elements separateArray(long array[], long size)
{
    Elements separator;

    for (int i = 0; i < size; i++)
    {
        if (array[i] < 0) separator.neagative++;
        else if (array[i] == 0) separator.zero++;
        else separator.positive++;
    }
    return separator;
}

void showNumbers(struct Elements separator)
{
    std::cout << "negative element in this array: " << separator.neagative << "\n";
    std::cout << "positive element in this array: " << separator.positive << "\n";
    std::cout << "zero element in this array: " << separator.zero << "\n";

}

int main()
{
    const long size = 25;
    long array[size];
    initArray(array, size);
    showArray(array, size);
    showNumbers(separateArray(array, size));

}

