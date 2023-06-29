/**
 * @file 283. Move Zeroes (LC Easy)
 * @brief Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements. Note that you must do this in-place without making a copy of the array.
 * @link https://leetcode.com/problems/move-zeroes
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 29-06-2023
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
	// Method - 1 (Works but it's complicated)
	// Time Complexity: O(n)
	// Space Complexity: O(1)
	void moveZeroes1(vector<int>& nums) {
		int i = 0, j = 1;
		while (j < nums.size()) {
			if (nums[j] == 0) {
				j++;
				continue;
			} else if (j == i+1 && nums[i] != 0 && nums[j] != 0) {
				i++;
				j++;
				continue;
			}
			if (nums[i] == 0) swap(nums[i++], nums[j++]);
			else swap(nums[++i], nums[j++]);
		}
		// For printing the result
		for (int i: nums) cout << i << " ";
		cout << endl;
	}

	// Method 2 - Optimal
	// TC: O(n)
	// SC: O(1)
	void moveZeroes2(vector<int>& nums) {
		int j = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				if (i > j) {
					nums[j] = nums[i];
					nums[i] = 0;
				}
				j++;
			}
		}
		// For printing the result
		for (int i: nums) cout << i << " ";
		cout << endl;
	}

	// Method 3 - (Smart but not a good one)
	// TC: O(n^2)
	// SC: O(1)
	void moveZeroes3(vector<int>& nums) {
	    vector<int>::iterator nums_it = nums.begin();
	    
	    int i = 0;
	    int n = nums.size();

	    while (i < n) { // O(n)
	        if (*nums_it == 0) {
	            nums.erase(nums_it); // O(n)
	            nums.push_back(0);
	        } else nums_it++;
	        i++;
	    }
	    // For printing the result
	    for (int a: nums) {
	        cout << a << endl;
	    }
	}
};

int main() {
	Solution sol;
	vector<int> i1 = {0, 0, 1, 4, 0, 1, 0, 9, 3, 0};
	vector<int> i2 = {1, 0, 1};
	sol.moveZeroes3(i1);
	return 0;
}