/*
Една студена и тежка зима младата програмистка Мърджания решила да си изсуши дрехите.
Нека сега си представим че нашата млада програмистка разполага с простер с N дрехи, които трябва да изсуши.
Тя разполага със сешоар, който във всеки един момент може да се използва върху една дреха.
Мърджания, иска да изсуши всички дрехи за възможно най-кратък период от време.

Разполагате с N дрехи като за всяка дреха N_i се знае колко време в минути е нужно дрехата да изсъхне.
 При дреха която е с <= 0 минути всичате че вече е суха и готова да се прибере.

Сешоарът на Мърджиния не е просто специален той може на всяка кръгла минута по избрана от вас дреха да намаля нейното време
за сушене с K. Тоест ако K = 3 и някоя дреха ai = 3, то ако използвате сешоара върху тази дреха тя за 1 минута ще бъде суха.

Дори и да е навън зима, вятърът понякога помага и в нашият случай той е на ваша страна, знае се че той постоянно
намалява времето за сушене на всички ваши дрехи с 1 минута. Тоест ако имате дреха ai = 2, то дори и
да не използвате сешоара след 2 минути тази дреха ще бъда суха.

От вас се иска по подадени N K и след това N дрехи, и по ваша преценка използвайки сешоара да върнете
мининалният брой минути за които всички дрехи ще бъдат сухи.

ВАЖНО: Когато използваме сешоара, вятърът НЕ ОКАЗВА ВЛИЯНИЕ на тази дреха !!!

Input Format
Вход:
N K
N числа
Constraints
N <= 100000
N > 0

Началното време за сушене на всяка дреха ще е <= 1 000 000 000
K <= 1 000 000 000
K > 0

Output Format
Минималното време използвайки или неизползвайки сешоара за което всички дрехи ще са сухи.
Пример:
3 5
2 3 9

Изход:
3
 */
#include <iostream>

bool dry(long long* arr, int length, long long k, long long minutes)
{
    long long dryingMinutes = 0;
    for (int i = 0; i < length; i++)
    {
        long long number = arr[i] - minutes;
        if (number > 0)
        {
            if (number % (k - 1) == 0)
            {
                dryingMinutes += number / (k - 1);
            }
            else
            {
                dryingMinutes += number / (k - 1) + 1;
            }
        }
    }

    return dryingMinutes <= minutes;
}

long long calculateMinutes(long long* arr, int length, long long k, long long max)
{
    if (k == 1)
    {
        return max;
    }

    long long left = 1;
    long long right = max;
    long long result = 0;
    while (left <= right)
    {
        long long middle = left + (right - left) / 2;
        if (dry(arr, length, k, middle))
        {
            result = middle;
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }

    return result;
}

int main()
{
    long long arr[100000];

    int N;
    std::cin >> N;
    int K;
    std::cin >> K;

    long long max = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    std::cout << calculateMinutes(arr, N, K, max) << "\n";

    return 0;
}