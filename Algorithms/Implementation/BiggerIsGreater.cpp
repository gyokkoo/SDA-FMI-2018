/*
 * https://www.hackerrank.com/challenges/bigger-is-greater/problem
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Complete the biggerIsGreater function below.
std::string biggerIsGreater(std::string w)
{
    // TODO: Implement own next_permutation function
    if (!std::next_permutation(w.begin(), w.end())) {
        return "no answer";
    }

    return w;
}

int main()
{
    int T;
    std::cin >> T;
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        std::string w;
        std::getline(cin, w);

        std::string result = biggerIsGreater(w);

        std::cout << result << "\n";
    }

    return 0;
}