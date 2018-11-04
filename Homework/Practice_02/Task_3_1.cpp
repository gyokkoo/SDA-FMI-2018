/*
За тази задача не може да ползвате вградени функции за сортиране и структури от данни

Чичо Скрудж като един любящ паток който изобщо не е стиснат, обича да купува играчки на своите малки патенца.
В магазина се продават N играчки, всяка с цена Ai ( за i = 0…N ).
За съжаление нашият любящ чичо Скрудж, разполага само с K лева, той не е много добър в смеките,
а вие като едни добри програмисти 2-ри курс СДА, трябва да му помогнете като му напишете програма,
която пресмята колко най-много играчки Скрудж може да купи. Знае се че Скрудж разполага с K лева.

Input Format

N K

Следват N числа.

Constraints

N >=1 и N <= 100000 K >=1 и K <= 1000000 Цената на всяка играчка > 0 и <= 1000000

Output Format

Максималният брой играчки които Скрудж може да закупи, разполагайки с K лева.

Пример:
5 7
4
3
1
5
1

Изход: 3
*/

#include <iostream>
#include <algorithm>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low; // index of smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[high]);

    return i;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main()
{
    int N = 0;
    int K = 0;
    std::cin >> N;
    std::cin >> K;

    int toys[100000];
    for (int i = 0; i < N; i++)
    {
        std::cin >> toys[i];
    }

    quickSort(toys, 0, N - 1);

    int count = 0;
    int index = 0;
    while (K - toys[index] >= 0 && index < N)
    {
        count++;
        K -= toys[index++];
    }

    std::cout << count << "\n";

    return 0;
}