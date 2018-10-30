/*
Фирма КТЯ ( Кратко Точно Ясно ) ви 'спускат' следната задача:
Тук нощен ястреб, ще ви изпратим масив ARRAY с N числа, след това ще получите Q заявки с число P.
За всяка от заявките трябва да ни отговорите кой е индекса на първото срещане на P и индекса на последното срещане на P при сортиран ARRAY.
Ако P не се среща в масива трябва да върнете -1 -1.
Input Format
Число N - размера на масива
Следват N числа елементите на масива.
Следва число Q брой на заявките.
За всяка заявка се въвежда число P.
Constraints
Q <= 100 000
N <= 100 000
Ai ( елемент от множеството N) <= 3 000 000 000
P <= 3 000 000 000
Output Format
За всяка заявка Q
Изведете индекса на първото и последното срещане на P в редицата.
 ( търсим индекса който отговаря на наредбата при сортираната фома на ARRAY )
Ако P не се среща изведете -1 -1
Вход:
5
1 2 2 4 5
2
2
6

Изход:
2 3
-1 -1
 */
#include <iostream>

int firstIndexBinarySearch(long long* arr, int left, int right, long long target)
{
    if (left <= right)
    {
        int middle = (right + left) / 2;

        if ((middle == 0 || arr[middle - 1] < target) && (arr[middle] == target))
        {
            return middle + 1;
        }

        if (arr[middle] < target)
        {
            return firstIndexBinarySearch(arr, middle + 1, right, target);
        }

        return firstIndexBinarySearch(arr, left, middle - 1, target);
    }

    return -1;
}

int lastIndexBinarySearch(long long* arr, int left, int right, long long target, int length)
{
    if (left <= right)
    {
        int middle = (right + left) / 2;

        if ((middle == length - 1 || arr[middle + 1] > target) && (arr[middle] == target))
        {
            return middle + 1;
        }

        if (arr[middle] > target)
        {
            return lastIndexBinarySearch(arr, left, middle - 1, target, length);
        }

        return lastIndexBinarySearch(arr, middle + 1, right, target, length);
    }

    return -1;
}

int main()
{
    int N;
    long long arr[100000];

    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + N);

    int Q;
    std::cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        long long P;
        std::cin >> P;

        int first = firstIndexBinarySearch(arr, 0, N - 1, P);
        int last = lastIndexBinarySearch(arr, 0, N - 1, P, N);
        std::cout << first << " " << last << "\n";
    }

    return 0;
}