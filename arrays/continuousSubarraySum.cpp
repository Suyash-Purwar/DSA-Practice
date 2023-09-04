/**
 * @file 523. Continuous Subarray Sum (Leetcode Medium)
 * @link https://leetcode.com/problems/continuous-subarray-sum/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 03-09-2023
*/  

#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

class Solution {
public:
	// TC: > O(n)
	// SC: O(n)
	bool checkSubarraySum1(vector<int>& nums, int k) {
		int sum = 0;
		unordered_map<int, int> hash;

		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];

			if (!i) {
				hash[sum] = i;
				continue;
			}
			if (sum % k == 0) return true;

			int j = 0;
			while (k * j < sum) {
				int rem = sum - k * j;

				if (hash.count(rem) && i - hash[rem] >= 2) {
					return true;
				}

				j++;
			}

			if (!hash.count(sum)) hash[sum] = i;
		}

		return false;
	}

	bool checkSubarraySum2(vector<int>& nums, int k) {
		
	}
};

int main() {
	Solution sol;

	vector<int> i1 = {23, 2, 6, 4, 7};
	vector<int> i2 = {23, 2, 4, 6, 7};
	vector<int> i3 = {5, 7};
	vector<int> i4 = {5, 8, 4};
	vector<int> i5 = {5, 0, 0};

	cout << sol.checkSubarraySum(i1, 6);
	cout << sol.checkSubarraySum(i1, 13);
	cout << sol.checkSubarraySum(i2, 6);
	cout << sol.checkSubarraySum(i3, 6);
	cout << sol.checkSubarraySum(i4, 6);
	cout << sol.checkSubarraySum(i5, 4);
}