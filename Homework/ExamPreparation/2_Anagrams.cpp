#include <iostream>
#include <string>
#include <algorithm>
#include <map>

int getChangesCount(std::string first, std::string second) {
    int letters[26] = { 0 };
    for (int i = 0; i < second.length(); i++) {
        letters[(first[i] - 'A')]++;
        letters[(second[i] - 'A')]--;
    }

    int changesCount = 0;
    for (int i = 0; i < 26; i++) {
        if (letters[i] > 0) {
            int j = i + 1;
            if (j == 26) {
                j = 0;
            }

            int count = 1;
            while (letters[j] >= 0) {
                j++;
                if (j == 26) {
                    j = 0;
                }
                count++;
            }

            changesCount += count;
            letters[i]--;
            letters[j]++;
            i--;
        }
    }

    return changesCount;
}

int main() {
    int T = 0;
    std::cin >> T;
    std::cin.ignore();

    while (T > 0) {
        T--;

        std::string first;
        std::string second;

        std::getline(std::cin, first);
        std::getline(std::cin, second);

        std::cout << getChangesCount(first, second) << "\n";
    }
}