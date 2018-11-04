#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>

int main()
{
    std::string first;
    std::string second;

    std::cin >> first;
    std::cin >> second;

    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());

    std::string result;

    if (first.length() > second.length())
    {
        std::string temp = first;
        first = second;
        second = temp;
    }

    if (first.length() < second.length())
    {
        for (int i = 0; i < first.length(); i++)
        {
            for (int j = 0; j < second.length(); j++)
            {
                if (first[i] == second[j])
                {
                    result += first[i];
                    second[j] = '0';
                    break;
                }
            }
        }
    }

    std::cout << result << "\n";

    return 0;
}