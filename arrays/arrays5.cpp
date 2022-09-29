/**
 * @file Remove Duplicates from Sorted Array
 * @brief Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
 * @link https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * @author Suyash Purwar (github.com/suyash-purwar)
 */

#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

class Solution {
    public:
        int removeDuplicates(vector<int> &nums) {
            int size = nums.size();
            for (int i = 0; i < size - 1; i++) {
                if (nums[i] == nums[i+1]) {
                    for (int z = i+1; z < size - 1; z++) {
                        nums[z] = nums[z+1];
                    }
                    i--;
                    size--;
                }
            }
            return size;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << sol.removeDuplicates(nums) << endl;

    return 0;
}