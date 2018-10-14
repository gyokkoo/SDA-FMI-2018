/*

Златар разполагал със антична везна на която от двете страни се поставяли обекти накланяйки се към по тежкият обект.
Златаря решил, че ще е много автентично да я използва за укражение в магазина, като решил за целта да разположи от едната
и страна едно по-голямо парче благороден метал, а от другата страна две други парчета, като единственото му желание било
везната да е балансирана. След известен брой опити златаря видял, че задачата да се намерят 3 парчета за които едното е
равно на сумата на другите не е проста. За това премерил всички парчета, разположил ги в масив и се надява с твоя помощ
да може да си отговори на въпроса съществуват ли такива парчета или не.

Input Format

Вход: N - броя на продуктите X1 ... XN - теглата на продуктите

Constraints

3 < N < 10000 теглата на продуктите са положителни числа от 0 до 1000000

Output Format

true ако съществуват търсените продукти false ако не съществуват

Пример:

Input: 5 1 2 3 4 5

Output: true

Input: 5 1 10 100 1000 100000

Output false
 */

#include <iostream>
#include <algorithm>

bool doesExist(int* arr, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int firstIndex = 0;
        int lastIndex = i - 1;
        while (firstIndex < lastIndex)
        {
            if (arr[i] == arr[firstIndex] + arr[lastIndex])
            {
                return true;
            }

            if (arr[i] > arr[firstIndex] + arr[lastIndex])
            {
                firstIndex++;
            }
            else
            {
                lastIndex--;
            }
        }
    }

    return false;
}

int main() 
{
    int n;
    int products[10000];
    std::cin >> n;


    for (int i = 0; i < n; i++) 
    {
        std::cin >> products[i];
    }
    
    std::sort(products, products + n);

    if(doesExist(products, n)) 
    {
        std::cout << "true\n";
    } 
    else 
    {
        std::cout << "false\n";
    }

    return 0;
}