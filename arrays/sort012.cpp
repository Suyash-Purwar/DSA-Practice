/**
 * @file 75. Sort Colors (Leetcode Medium)
 * @brief Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively. You must solve this problem without using the library's sort function.
 * @link https://leetcode.com/problems/sort-colors/description/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 28-06-2023
*/	

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::swap;

class Solution {
public:
	// Good
	// TC: O(2n)
	// SC: O(1)
	void sortColors1(vector<int>& nums) {
		int count_0 = 0, count_1 = 0, count_2 = 0;
		for (int n: nums) {
			switch (n) {
			case 0:
				count_0++;
				break;
			case 1:
				count_1++;
				break;
			case 2:
				count_2++;
				break;
			}
		}
		for (int i = 0; i < nums.size(); i++) {
			if (count_0) {
				nums[i] = 0;
				count_0--;
			}
			else if (count_1) {
				nums[i] = 1;
				count_1--;
			} else {
				nums[i] = 2;
				count_2--;
			}
		}
	}

	// Optimal
	// TC: O(n)
	// SC: O(1)
	void sortColors2(vector<int>& nums) {
		int low = 0;
		int high = nums.size() - 1;
		int mid = 0;

		while (mid <= high) {
			if (nums[mid] == 0) {
				swap(nums[mid], nums[low]);
				low++;
				mid++;
			} else if (nums[mid] == 1) {
				mid++;
			} else if (nums[mid] == 2) {
				swap(nums[mid], nums[high]);
				high--;
			}
		}

		for (int i: nums) cout << i << " ";
		cout << endl;
	}
};

int main() {
	Solution sol;
	vector<int> i1 = {2, 0, 1, 1, 2, 0, 0, 1, 2, 1, 2, 0};
	sol.sortColors2(i1);
}
