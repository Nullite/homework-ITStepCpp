#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> &initArray()
{
    srand(time(nullptr));
    static std::vector <int> randArray;
    for (int i = 0; i < 100; i++)
    {
        randArray.push_back (rand() % 20 - 10);
    }
    return randArray;
}

void showArray(std::vector<int> &array)
{
    printf("random generated array elements are: ");
    for (int elem : array) printf("%d ", elem);
    printf("\n\n");
}

int searchIndex(std::vector<int>& array, int sum)
{
    for (int i = 0; i < 90; i++)
    {
        int temp = 0;
        for (int j = i; j < i + 10; j++)
        {
            temp += array[j];
            if (sum == temp) return i;
        }
    }
}

int indexOfminValSeq(std::vector<int>& array, int index)
{ 
    int sum = 0;
    for (int i = index; i < index + 10; i++)
    {
        sum += array[i];
    }
    
    if (index == 90)
    {
        return sum;
    }
    return std::min(sum, indexOfminValSeq(array, index + 1));
}
int main()
{
    std::vector <int>& arr = initArray();
    showArray(arr);
    std::cout <<"minimal value sequence of 10 elements in a row begins from index: " << searchIndex(arr, indexOfminValSeq(arr, 0));
}
