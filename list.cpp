#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> nums1;

    std::vector<int> nums = { 1, 3, 2, 5, 4 };


    int num = nums[1];

    nums[1] = 0;


    nums.clear();


    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(4);


    nums.insert(nums.begin() + 3, 6);


    nums.erase(nums.begin() + 3);


    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        count += nums[i];
    }
    std::cout << "Result: " << count << std::endl;


    count = 0;

    for (int num : nums) {
        count += num;
    }
    std::cout << "Result: " << count << std::endl;


    std::vector<int> nums2 = { 6, 8, 7, 10, 9 };

    nums.insert(nums.end(), nums2.begin(), nums2.end());


    std::sort(nums.begin(), nums.end());


    std::cout << "vector";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}