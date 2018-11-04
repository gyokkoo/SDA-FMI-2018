#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <set>

int main ()
{
    int N = 0;
    int K = 0;

    std::cin >> N;
    std::cin >> K;

    int stocks[1000];

    for (int i = 0; i < N; i++)
    {
        std::cin >> stocks[i];
    }

    std::vector<std::vector<int>> allPairs;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            std::vector<int> pair;
            pair.push_back(stocks[j] - stocks[i]);
            pair.push_back(stocks[i]);
            pair.push_back(stocks[j]);

            allPairs.push_back(pair);
        }
    }

    std::sort(allPairs.begin(), allPairs.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) {
                  if (a[0] == b[0]) {
                      return a[1] < b[1];
                  }

                  return a[0] < b[0];
              });

    std::cout << allPairs[K - 1][1] << " " << allPairs[K - 1][2];
    return 0;
}

