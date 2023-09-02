/**
 * @file 560. Subarray Sum Equals K (Leetcode Medium)
 * @link https://leetcode.com/problems/subarray-sum-equals-k/
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
	// TC: O(n^2)
	// SC: O(1)
	// Throws TLE
	int subarraySum1(vector<int>& nums, int k) {
		int count = 0, sum = 0;

		for (int i = 0; i < nums.size(); i++) {
			sum = 0;
			for (int j = i; j < nums.size(); j++) {
				sum += nums[j];
				if (sum == k) {
					count++;
					cout << i << " " << j << " " << sum << endl;
				}
			}
		}

		return count;
	}

	// TC: O(n)
	// SC: O(n)
	int subarraySum2(vector<int>& nums, int k) {
		int sum = 0, count = 0;
		unordered_map<int, int> sumFreq;

		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];

			if (sum == k) count++;

			int more = sum - k;
			if (sumFreq.count(more)) {
				count += sumFreq[more];
			}

			sumFreq[sum]++;
		}

		return count;
	}
};

int main() {
	Solution sol;
	vector<int> i1 = {1, 1, 2, 0, 1, 2, 1, 1, 0};
	vector<int> i2 = {1, 2, 3, 1, 1};
	vector<int> i3 = {1, 1, 2, -1, 2, 3};
	vector<int> i4 = {1, 0, 1, 1};
	vector<int> i5 = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
	vector<int> i6 = {0, 0, 0, 0};

	cout << sol.subarraySum2(i1, 2) << endl;
	cout << sol.subarraySum2(i2, 1) << endl;
	cout << sol.subarraySum2(i4, 1) << endl;

	cout << sol.subarraySum2(i5, 3) << endl;
	cout << sol.subarraySum2(i6, 0) << endl;

	return 0;
}