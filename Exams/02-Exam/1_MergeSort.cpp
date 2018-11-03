/*
Реализирайте сортиране чрез вливане, което да изкарва детайлна информация за вътрешните сортировки направени от алгоритъма т.е.
Всеки път след изпълнение на сливане на два масива принтирайте сортираният масив на стандартният изход.
(Рекурсивното обхождане се дефинира да е е от по-малък индекс към по-голям.)

Input Format
N - големина на масив за сортиране x1 x2 …. xN - елементите на масива

Constraints
0 < N < 100 000
0 < xi < 1 000 000

Output Format

всеки един сортиран подмасив, като принтирате само числа с интервал след всяко едно
(включително интервал след последното число!)

Sample Input 0
4
1 5 2 4

Sample Output 0
1 5 1 5 2 4 2 4 1 2 4 5
 */

#include <iostream>

void merge(int arr[], int left, int middle, int right)
{
    int leftLength = middle - left + 1;
    int rightLength = right - middle;

    int* leftArr = new int[leftLength];
    int* rightArr = new int[rightLength];

    for (int i = 0; i < leftLength; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < rightLength; j++)
    {
        rightArr[j] = arr[middle +  1 + j];
    }

    int i = 0;
    int j = 0;
    int index = left;
    while (i < leftLength && j < rightLength)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[index] = leftArr[i];
            i++;
        }
        else
        {
            arr[index] = rightArr[j];
            j++;
        }
        index++;
    }

    while (i < leftLength)
    {
        arr[index] = leftArr[i];
        i++;
        index++;
    }

    while (j < rightLength)
    {
        arr[index] = rightArr[j];
        j++;
        index++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        for (int i = left; i <= middle; i++)
        {
            std::cout << arr[i] << " ";
        }

        mergeSort(arr, middle + 1, right);
        for (int i = middle + 1; i <= right; i++)
        {
            std::cout << arr[i] << " ";
        }

        merge(arr, left, middle, right);
    }
}

int main()
{
    int N;
    std::cin >> N;

    int myArray[100000];
    for (int i = 0; i < N; i++)
    {
        std::cin >> myArray[i];
    }

    mergeSort(myArray, 0, N - 1);
    for (int i = 0; i < N; i++)
    {
        std::cout << myArray[i] << " ";
    }

    return 0;
}