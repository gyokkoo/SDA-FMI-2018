/*
Мишо е млад войник който никак не харесва да бъде наричан "новобранец" или "заек".
Всяка сутрин за да прикрие че е нов в армията той се дегизира като генерал и играе на ССПС "Строй Се Преброй Се".
За всяка една рота от войници, той иска пълен доклад за тяхната "Софтуерна Наредба".

Нареждайки войниците в една редица, Софтуерна Наредба ще наричаме броят двойки войници (A,B), за които A > B и A се намира по-наляво в редицата.
Пример:
N = 5
1,2,3,4,5

Отговор: 0

N = 5
5,4,3,2,1
(5,4),(5,3),(5,2),(5,1),(4,3),(4,2),(4,1),(3,2),(3,1),(2,1) => Отговор: 10

Input Format

За начало на входа се въвежда число Q. Брой заявки на Мишо към армията. за Всяка заяка Qi ( i = 1.. Q ) Следва число N брой войници в строя.
Следват N числа - височината в милиметри на всеки войник
Constraints

N <= 1000000

Височината на всеки войник <= 1000000

Q брой на заявките <= 1000

Output Format

Изход:
За всяка редица от войници изведете нейната Софтуерна Наредба.
Примерен вход:
2
5
1 1 1 2 2
5
2 1 3 1 2
Примерен изход:
0
4
 */

#include <iostream>
#include <algorithm>

long long merge(int* arr, int* temp, int left, int middle, int right)
{
    long long pairCount = 0;

    int i = left;
    int j = middle;
    int index = left;
    while ((i <= middle - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[index] = arr[i];
            i++;
            index++;
        }
        else
        {
            temp[index] = arr[j];
            j++;
            index++;

            pairCount = pairCount + (middle - i);
        }
    }

    while (i <= middle - 1)
    {
        temp[index] = arr[i];
        i++;
        index++;
    }

    while (j <= right)
    {
        temp[index] = arr[j];
        j++;
        index++;
    }

    for (int k = left; k <= right; k++)
    {
        arr[k] = temp[k];
    }

    return pairCount;
}

long long getPairCount(int* arr, int* temp, int left, int right)
{
    int middle = 0;
    long long pairCount = 0;
    if (right > left)
    {
        middle = (right + left) / 2;

        pairCount = getPairCount(arr, temp, left, middle);
        pairCount += getPairCount(arr, temp, middle + 1, right);

        pairCount += merge(arr, temp, left, middle + 1, right);
    }

    return pairCount;
}

int main()
{
    int Q = 0;
    std::cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int N = 0;
        std::cin >> N;

        int ordinance[1000000];

        for (int j = 0; j < N; j++)
        {
            std::cin >> ordinance[j];
        }

        int temp[1000000];
        long long pairCount = getPairCount(ordinance, temp, 0, N - 1);
        std::cout << pairCount << "\n";
    }

    return 0;
}