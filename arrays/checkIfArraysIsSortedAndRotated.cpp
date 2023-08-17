/**
 * @file 1752. Check if Array Is Sorted and Rotated (Leetcode Easy)
 * @brief Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false. There may be duplicates in the original array. Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.
 * @link https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 16-08-2023
*/

#include <iostream>
#include <vector>
#include <climits>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
	// TC: O(n)
	// SC: O(1)
	bool check1(vector<int>& nums) {
		int shiftedBy = 0; int mini = INT_MAX;
		for (int i = 0; i < nums.size(); i++) {
			if (mini >= nums[i]) {
				if (i == 0 || nums[i] != nums[i-1]) {
					mini = nums[i];
					shiftedBy = i;
				}
			}
		}

		for (int i = 1; i < nums.size(); i++) {
			if (nums[(i+shiftedBy-1)%nums.size()] > nums[(i+shiftedBy)%nums.size()]) {
				return false;
			}
		}

		return true;
	}

	// TC: O(n)
	// SC: O(1)
	bool check2(vector<int>& nums) {
		int count = 0;
		int n = nums.size();

		for (int i = 1; i < n; i++) {
			if (nums[i-1] > nums[i]) {
				count++;
			}
		}

		if (nums[n-1] > nums[0]) {
			count++;
		}

		return count <= 1;
	}
};

int main() {
	Solution sol;

	vector<int> i1 = {2, 2, 1, 1, 1, 2, 2};
	vector<int> i2 = {6, 10, 6};

	bool ans = sol.check1(i2);
	cout << ans << endl;
}