/**
 * @name Single Number
 * @brief Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
 * @link https://leetcode.com/problems/single-number/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 27-09-2022
 */

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
    public:
        int singleNumber(vector<int>& nums1, vector<int> *nums2) {
            cout << &nums1 << endl;
            cout << nums2 << endl;
            
            return 0;
        }
};

int main() {
    vector<int> nums = {2, 5, 2, 5, 1};
    Solution sol;
    cout << sol.singleNumber(nums, &nums) << endl;
    return 0;
}