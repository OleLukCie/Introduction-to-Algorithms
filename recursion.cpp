#include <stack>
using namespace std;

int recur(int n)
{
	if (n == 1)
		return 1;

	int res = recur(n - 1);

	return n + res;
}

int tailRecur(int n, int res)
{
	if (n == 0)
		return res;

	return tailRecur(n - 1, res + n);
}

int fib(int n)
{
	if (n == 1 || n == 2)
		return n - 1;

	int res = fib(n - 1) + fib(n - 2);

	return res;
}

int firLoopRecur(int n)
{
	stack<int> stack;
	int res = 0;

	for (int i = n; i > 0; i--)
	{
		stack.push(i);
	}

	while (!stack.empty()) {
		res += stack.top();
		stack.pop();
	}

	return res;
}