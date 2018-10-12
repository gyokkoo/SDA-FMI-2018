#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n = 0;
    int k = 0;
    int sum = 0;
    int items[100000];

    std::cin >> n;
    std::cin >> k;

    for (int i = 0; i < n; i++)
    {
        std::cin >> items[i];
        sum += items[i];
    }

    std::sort(items, items + n);

    for (int i = n - k; i >= 0; i-=k)
    {
        sum -= items[i];
    }

    std::cout << sum << "\n";

    return 0;
}