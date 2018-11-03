/*
Използвайте двоично търсене за намиране на индекс на търсено число в масив и броят на двоичните разделяния до намиране на число в сортиран масив.
Ако числото не е налично в масива следва да се върне индекс -1 и съответно колко разделяния са направени докато се разбере, че числото не е в масива.
(Уточнение: При разделяне на масив със четен брой елементи средата се закръгля надолу.)

Input Format
N - големина на масив за сортиране
x1 x2 …. xN - елементи на сортирания масив
К - брой на заявките за търсене
y1 y2 … yK - числата, който ще търсим

Constraints
0 < N,K < 100 000
0 < xi, yi < 1 000 000

Output Format
Iy1 Iy2 … IyK - индекси на който се срещат търсените числа в масива(след всяко число има интервал)
Zy1 Zy2 … ZyK - брой на проверки до намирането на число в масива с дроично търсене
(тези числа са отделени с нов ред от предишните и отново след всяко число има интервал)

Sample Input:
7
1 3 5 6 7 8 9
5
3 6 7 8 9
Sample Output:
1 3 4 5 6
2 1 3 2 3
 */

#include <iostream>

int main()
{
    int indexes[100000];
    int counts[100000];

    int N;
    std::cin >> N;
    int arr[100000];
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }

    int K;
    std::cin >> K;
    int targets[100000];
    for (int i = 0; i < K; i++)
    {
        std::cin >> targets[i];
    }

    for (int i = 0; i < K; i++)
    {
        int target = targets[i];
        int counter = 0;
        int left = 0;
        int right = N - 1;
        bool isFound = false;

        while (left <= right)
        {
            counter++;
            int middle = (left + right) / 2;

            if (arr[middle] == target)
            {
                indexes[i] = middle;
                isFound = true;
                break;
            }

            if (arr[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }

        if (!isFound)
        {
            indexes[i] = -1;
        }

        counts[i] = counter;
    }

    for (int i = 0; i < K; i++)
    {
        std::cout << indexes[i] << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < K; i++)
    {
        std::cout << counts[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
