#include <vector>
#include <unordered_map>

using namespace std;

/* Method 1: Brute Force */
vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    int size = nums.size();
    // Two-level loop, time complexity is O(n^2)
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] + nums[j] == target)
                return { i, j };
        }
    }
    return {};
}

/* Method 2: Auxiliary Hash Table */
vector<int> twoSumHashTable(vector<int>& nums, int target) {
    int size = nums.size();
    // Auxiliary hash table, space complexity is O(n)
    unordered_map<int, int> dic;
    // Single loop, time complexity is O(n)
    for (int i = 0; i < size; i++) {
        if (dic.find(target - nums[i]) != dic.end()) {
            return { dic[target - nums[i]], i };
        }
        dic.emplace(nums[i], i);
    }
    return {};
}