/**
 * @name Remove Element
 * @brief Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.
 * @link https://leetcode.com/problems/remove-element/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 29-09-2022
 */

#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
    public:
        int removeElement(vector<int> &nums, int val) {
            int size = nums.size();
            for(int i = 0; i < size; i++) {
                if (nums[i] == val) {
                    for (int j = i; j < size-1; j++) {
                        nums[j] = nums[j+1];
                    }
                    size--;
                    i--;
                }
            }
            for (int i = 0; i < nums.size(); i++) {
                cout << nums[i] << "\t";
            }
            return size;
        }
};

int main() {
    vector<int> nums = {0, 1, 2, 3, 4, 2, 2, 5};
    int val = 2;
    Solution sol;
    cout << sol.removeElement(nums, val) << endl;
    return 0;
}