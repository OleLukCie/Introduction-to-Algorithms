#include <vector>
#include <chrono>
#include <random>
using namespace std;

vector<int> randomNumbers(int n)
{
	vector<int> nums(n);

	for (int i = 0; i < n; i++)
	{
		nums[i] = i + 1;
	}

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(nums.begin(), nums.end(), default_random_engine(seed));
	return nums;
}

int findOne(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 1)
			return i;
	}
	return -1;
}