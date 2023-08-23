/**
 * @file 53. Maximum Subarray
 * @brief Given an integer array nums, find the subarray with the largest sum, and return its sum.
 * @link https://leetcode.com/problems/maximum-subarray/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 23-07-2023
*/	

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution {
public:
	// KADANE'S ALGORITHM
	int maxSubArray(vector<int>& nums) {
		int maxi = INT_MIN, sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			maxi = max(maxi, sum);
			if (sum < 0) sum = 0;
		}

		return maxi;
	}
};

int main() {
	Solution sol;

	vector<int> i1 = {-2, -3, 4, -1, -2, 1, 5, -3};

	cout << sol.maxSubArray(i1) << endl;
}