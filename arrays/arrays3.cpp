/**
 * @name Single Number
 * @brief Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
 * @link https://leetcode.com/problems/single-number/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 27-09-2022
 */

/**
 * @note Solved using Bruteforce which breaks the TLE. Needs to be implmented using hash table
 */

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            bool flag; int size = nums.size();
            for (int i = 0; i < size; i++) {
                flag = false;
                for (int j = 0; j < size; j++) {
                    if (nums[i] == nums[j] && i != j) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) return nums[i];
            }
            return -1;
        }
};

int main() {
    vector<int> nums = {1};
    Solution sol;
    cout << sol.singleNumber(nums) << endl;
    return 0;
}