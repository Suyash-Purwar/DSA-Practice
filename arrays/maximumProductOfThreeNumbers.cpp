/**
 * @file 628. Maximum Product of Three Numbers
 * @brief Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
 * @link https://leetcode.com/problems/maximum-product-of-three-numbers/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 24-08-2023
*/	

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::sort;
using std::vector;
using std::max;

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());

		int sum1, sum2;

		sum1 = nums[0] * nums[1] * nums[n-1];
		sum2 = nums[n-1] * nums[n-2] * nums[n-3];

		return max(sum1, sum2);
	}
};

int main() {
	Solution sol;

	vector<int> i1 = {1, 2, 3};
	vector<int> i2 = {1, 2, 3, 4};
	vector<int> i3 = {-1, -2, -3};
	vector<int> i4 = {-100, -98, -1, 2, 3, 4};
	vector<int> i5 = {-1, 2, 0};

	cout << sol.maximumProduct(i1) << endl;
	cout << sol.maximumProduct(i2) << endl;
	cout << sol.maximumProduct(i3) << endl;
	cout << sol.maximumProduct(i4) << endl;
	cout << sol.maximumProduct(i5) << endl
}