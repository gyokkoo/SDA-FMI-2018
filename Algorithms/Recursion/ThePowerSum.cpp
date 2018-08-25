/*
* https://www.hackerrank.com/challenges/the-power-sum/problem
*/

#include <iostream>

int getPower(int base, int exp);

int powerSum(int X, int N, int curr_num = 1, int curr_sum = 0) 
{
	int count = 0;

	int sum = getPower(curr_num, N);
	while (sum + curr_sum < X)
	{
		count += powerSum(X, N, curr_num + 1, sum + curr_sum);
		curr_num++;
		sum = getPower(curr_num, N);
	}

	if (sum + curr_sum == X)
	{
		count++;
	}

	return count;
}

int getPower(int base, int exp)
{
	if (exp == 0)
		return 1;
	if (exp == 1)
		return base;

	return base * getPower(base, exp - 1);
}

int main()
{
	int X;
	std::cin >> X;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	int N;
	std::cin >> N;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	int result = powerSum(X, N);

	std::cout << result << "\n";

	return 0;
}