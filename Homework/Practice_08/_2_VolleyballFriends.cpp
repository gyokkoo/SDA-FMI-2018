#include <iostream>
#include <set>

int main() {
	int firstNumber = 0;
	std::cin >> firstNumber;

	std::set<int> players;
	players.insert(firstNumber);

	int N = 0;
	std::cin >> N;
	int counter = 1;
	for (int i = 0; i < N; i++) {
		int first = 0;
		int second = 0;
		std::cin >> first >> second;

		if (players.count(first) && !(players.count(second))) {
			counter++;
			players.insert(second);
		}
	}

	std::cout << counter << "\n";

	return 0;
}