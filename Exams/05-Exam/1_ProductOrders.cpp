#include <cmath>
#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() {
    std::ios::sync_with_stdio(false);
    long long N = 0;
    std::cin >> N;

    std::unordered_map<long long, long long> products;
    for (int i = 0; i < N; i++) {
        long long currentId = 0;
        std::cin >> currentId;
        if (products.find(currentId) == products.end()) {
            products.insert(std::pair<long, long>(currentId, 0));
        }

        products[currentId]++;
    }

    long long usersCount = 0;
    long long productsLeft = 0;
    for (auto item : products) {
        if (item.second % 10 != 0) {
            usersCount++;
            productsLeft += item.second % 10;
        }
    }

    std::cout << usersCount << " ";
    std::cout << productsLeft << "\n";

    return 0;
}