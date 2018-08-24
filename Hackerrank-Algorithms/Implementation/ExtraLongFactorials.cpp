/*
* https://www.hackerrank.com/challenges/extra-long-factorials/problem
*/
#include <iostream>

#define MAX 500

int multiply(int x, int res[], int res_size);

void extraLongFactorials(int n) 
{
	int res[MAX];

	res[0] = 1;
	int res_size = 1;

	for (int x = 2; x <= n; x++)
	{
		res_size = multiply(x, res, res_size);
	}

	for (int i = res_size - 1; i >= 0; i--)
	{
		std::cout << res[i];
	}
}

int multiply(int x, int res[], int res_size)
{
	int carry = 0;

	for (int i = 0; i < res_size; i++)
	{
		int product = res[i] * x + carry;
		res[i] = product % 10;
		carry = product / 10;
	}

	while (carry)
	{
		res[res_size] = carry % 10;
		carry = carry / 10;
		res_size++;
	}

	return res_size;
}

int main()
{
	int n;
	std::cin >> n;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	extraLongFactorials(n);

	return 0;
}