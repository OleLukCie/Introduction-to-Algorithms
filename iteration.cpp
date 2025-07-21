#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int forLoop(int n)
{
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res += i;
	}
	return res;
}

int whileLoop(int n)
{
	int res = 0;
	int i = 1;

	while (i <= n)
	{
		res += i;
		i++;
	}
	return res;
}

int whileLoopII(int n)
{
	int res = 0;
	int i = 1;

	while (i <= n)
	{
		res += i;
		i++;
		i *= 2;
	}
	return res;
}


string nestedForLoop(int n)
{
	ostringstream res;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
		{
			res << "(" << i << ", " << j << "), ";
		}
	}
	return res.str();
}