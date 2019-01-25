#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int getMaximumSum(const std::vector<int>& numbers) {
    int maxSum = 0;
    size_t length = numbers.size();
    if (length == 0) {
        return 0;
    }

    size_t index = 0;
    if (length % 2 != 0) {
        maxSum += numbers[0];
        index = 1;
    }

    while (index < length - 1) {
        maxSum += numbers[index] * numbers[index + 1];
        index += 2;
    }

    return maxSum;
}

int main() {

    int T = 0;
    std::cin >> T;
    while (T > 0) {
        T--;
        int N = 0;
        std::cin >> N;

        std::vector<int> positiveNumbers;
        std::vector<int> negativeNumbers;
        int maxSum = 0;
        for (int i = 0; i < N; i++) {
            int numberToAdd = 0;
            std::cin >> numberToAdd;

            if (numberToAdd > 0) {
                if (numberToAdd == 1) {
                    maxSum++;
                } else {
                    positiveNumbers.push_back(numberToAdd);
                }
            } else {
                negativeNumbers.push_back(numberToAdd);
            }
        }

        std::sort(positiveNumbers.begin(), positiveNumbers.end());
        std::sort(negativeNumbers.begin(), negativeNumbers.end(), std::greater<>());

        maxSum += getMaximumSum(positiveNumbers);
        maxSum += getMaximumSum(negativeNumbers);

        std::cout << maxSum << "\n";
    }

    return 0;
}
