/**
 * @file 26. Remove Duplicates from Sorted Array
 * @brief Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
 * @link https://leetcode.com/problems/remove-duplicates-from-sorted-array
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 27-06-2023
*/	
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::swap;
using std::set;

class Solution {
public: 
	// Method 1 - Brute force (TLE)
	// Bekaar approach
	int removeDuplicates1(vector<int>& nums) {
		int count = 1; int k = nums.size() - 1;
		for (int i = 0, j = i+1; i < k; i++, j=i+1) {
			if (nums[i] == nums[j]) {
				while (j < k) {
					swap(nums[j], nums[j+1]);
					j++;
				}
				k--;
				i--;
			} else {
				count++;
			}
		}
		for (int n: nums) {
			cout << n << " ";
		} cout << endl;
		return count;
	}

	// Method 2 - Brute force
	// TC: O(nlogn + n)
	// SC: O(n)
	int removeDuplicates2(vector<int>& nums) {
		set<int> set_num;
		for (int n: nums) {
			set_num.insert(n);
		}
		int index = 0;
		for (int sn: set_num) {
			nums[index] = sn;
			index++;
		}
		return index;
	}

	// Method 3 - Optimal
	// TC : O(n)
	// SC : O(1)
	int removeDuplicates3(vector<int>& nums) {
		int i = 0, j = 0;
		for (; j < nums.size(); j++) {
			if (nums[i] != nums[j]) {
				nums[i+1] = nums[j];
				i++;
			}
		}
		return i+1;
	}
};

int main() {
	Solution sol;
	// vector<int> i1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	vector<int> i1 = {0, 1};
	int ans = sol.removeDuplicates3(i1);
	cout << ans;
}