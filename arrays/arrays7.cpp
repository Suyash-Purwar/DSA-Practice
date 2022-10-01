/**
 * @name Maximum Subarray (LeetCode Medium)
 * @brief Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * @link https://leetcode.com/problems/maximum-subarray/
 * @author Suyash Purwar (github.com/suyash-purwar)
 */

#include <iostream>
#include <vector>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::numeric_limits;

class Solution {
    public:
    // Bruteforce Solution
    // Gives TLE on LeetCode
    int maxSubArray(vector<int> &nums) {
        int tempSum; float sum = -numeric_limits<float>::infinity();
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            tempSum = 0;
            for (int j = i; j < size; j++) {
                tempSum += nums[j];
                if (tempSum > sum) sum = tempSum;
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    // vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    // vector<int> nums = {5,4,-1,7,8};
    vector<int> nums = {-1};
    cout << sol.maxSubArray(nums) << endl;
    return 0;   
}