#include <iostream>
#include <vector>
using namespace std;

void algorithm(int n)
{
	int a = 2;
	a = a + 1;
	a = a * 2;

	for (int i = 0; i < n; i++)
	{
		cout << 0 << endl;
	}
}

void algorithm_A(int n)
{
	cout << 0 << endl;
}

void algorithm_B(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << 0 << endl;
	}
}

void algorithm_C(int n)
{
	for (int i = 0; i < 1000000; i++) {
		cout << 0 << endl;
	}
}

void Algorithm(int n)
{
	int a = 1;
	a = a + n;

	for (int i = 0; i < 5 * n + 1; i++)
	{
		cout << 0 << endl;
	}

	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < n + 1; j++)
		{
			cout << 0 << endl;
		}
	}
}

int constant(int n)
{
	int count = 0;
	int size = 100000;
	for (int i = 0; i < size; i++)
	{
		count++;
	}
	return count;
}

int linear(int n) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count++;
	}
	return count;
}

int arrayTraversal(vector<int>& nums)
{
	int count = 0;
	for (int num : nums) {
		count++;
	}
	return count;
}

int quadratic(int n)
{
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			count++;
		}
	}
	return count;
}

int bubbleSort(vector<int>& nums)
{
	int count = 0;

	for (int i = nums.size() - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[j] > nums[j + 1]) {
				int tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
				count += 3;
			}
		}
	}
	return count;
}

int exponential(int n)
{
	int count = 0, base = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < base; j++) {
			count++;
		}
		base *= 2;
	}
	return count;
}

int expRecur(int n) {
	if (n == 1)
		return 1;
	return expRecur(n - 1) + expRecur(n - 1) + 1;
}

int logarithmic(int n)
{
	int count = 0;
	while (n > 1) {
		n = n / 2;
		count++;
	}
	return count;
}

int logRecur(int n) {
	if (n <= 1)
		return 0;
	return logRecur(n / 2) + 1;
}

int linearLogRecur(int n) {
	if (n <= 1)
		return 1;
	int count = linearLogRecur(n / 2) + linearLogRecur(n / 2);
	for (int i = 0; i < n; i++)
	{
		count++;
	}
	return count;
}

int factorialRecur(int n)
{
	if (n == 0)
		return 1;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		count += factorialRecur(n - 1);
	}
	return count;
}