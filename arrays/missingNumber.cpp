/**
 * @file 283. 268. Missing Number (LC Easy)
 * @brief Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
 * @link https://leetcode.com/problems/missing-number
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 30-06-2023
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;

class Solution {
public:
	// Brute force
	// TC: O(n^2)
	// SC: O(1)
	int missingNumber1(vector<int>& nums) {
		for (int i = 0; i <= nums.size(); i++) {
			bool flag = 0;
			for (int n: nums) {
				if (i == n) flag = 1;
			}
			if (!flag) {
				return i;
			}
		}
		return -1;
	}

	// Better
	// TC: O(nlogn + n)
	// SC: O(1)
	int missingNumber2(vector<int>& nums) {
		sort(nums.begin(), nums.end()); // O(nlogn)
		for (int i = 1; i < nums.size(); i++) { // O(n)
			if (nums[i]-1 != nums[i-1]) return nums[i]+1;
		}
		return (nums[0] ? 0 : nums.size());
	}

	// Better
	// TC: O(2n)
	// SC: O(n)
	int missingNumber3(vector<int>& nums) {
		// Creat an array of size 1 greater than the nums array
		// Initialize each position with 0
		vector<int> hash(nums.size()+1, 0);
		for (int n: nums) hash[n] = 1;
		for (int i = 0; i < hash.size(); i++) {
			if (!hash[i]) return i;
		}
		return -1;
	}

	// Optimal 1
	// TC: O(n)
	// SC: O(1)
	int missingNumber4(vector<int>& nums) {
		int ans = 0, i = 0;
		for (; i < nums.size(); i++) {
			ans = ans ^ nums[i] ^ i;
		}
		ans = ans ^ i;
		return ans;
	}

	// Optimal 2
	// TC: O(n)
	// SC: O(1)
	int missingNumber5(vector<int>& nums) {
		int sum = 0;
		int l = nums.size();
		for (int n: nums) {
			sum += n;
		}
		return (l*(l+1))/2 - sum;
	}
};

int main() {
	Solution sol;
	vector<int> i1 = {0, 2, 1, 3};
	vector<int> i2 = {1};

	cout << sol.missingNumber3(i2);

	return  0;
}