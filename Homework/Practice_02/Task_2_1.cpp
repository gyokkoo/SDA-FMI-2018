/* 
За тази задача не може да ползвате вградени функции за сортиране и структури от данни**

Имате стринг S с дължина до 500 символа и съставен само от малки латиснки букви. ( a - z ).

Изведете “Yes” ако буквите в S могат да бъдат наредени така че да няма 2 еднакви съседни символа.

Input Format
На първия ред се въвежда стринг S

Constraints
|S| <= 500

Output Format
"Yes" ако условието е изпълнено или "No" в противен случай.

Примери:

Вход:
aab

Изход:
Yes ( Пояснение: aab -> aba)

Вход:
aaab

Изход:
No
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void selectionSort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }

        std::swap(arr[maxIndex], arr[i]);
    }
}

int main()
{
    std::string S;
    int frequencies[26];
    for (int i = 0; i < 26; i++)
    {
        frequencies[i] = 0;
    }

    std::getline (std::cin, S);
    for (int i = 0; i < S.length(); i++)
    {
        frequencies[S[i] - 'a']++;
    }

    selectionSort(frequencies, 26);

    if (frequencies[0] > (S.length() + 1) / 2)
    {
        std::cout << "No\n";
    }
    else
    {
        std::cout << "Yes\n";
    }

    return 0;
}