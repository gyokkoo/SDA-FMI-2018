/*
 * MergeSortImplementation
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
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main()
{
    int myArray[] = { 4, 6, 1, 9, 5, 35, 4 };
    int length = sizeof(myArray) / sizeof(myArray[0]);

    mergeSort(myArray, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        std::cout << myArray[i] << "\n";
    }

    return 0;
}