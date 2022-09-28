/**
 * @name Palindromic Substring (Leetcode Medium)
 * @brief Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * @link https://leetcode.com/problems/two-sum/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 27-02-2022
 */

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
    public:
        vector<int> twoSum(vector<int> nums, int target) {
            vector<int> indices;
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i+1; j < nums.size(); j++) {
                    cout << i << j << endl;
                    if (nums[i] + nums[j] == target) {
                        indices.push_back(i);
                        indices.push_back(j);
                    }
                }
            }
            return indices;
        }
};

int main() {
    vector<int> nums = {12, 34, 2};
    Solution sol;
    vector<int> indices = sol.twoSum(nums, 14);
    cout << indices[0] << endl << indices[1] << endl;
    return 0;
}
