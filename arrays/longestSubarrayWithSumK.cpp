/**
 * @file Longest Subarray With Sum K. (Coding Ninjas Easy & Medium)
 * @link https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399
 * @link https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_5713505
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 18-08-2023
*/  

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>

using std::cout;
using std::vector;
using std::endl;
using std::max;
using std::unordered_map;

class Solution {
public:
	// TC: O(n^2)
	// SC: O(1)

	// Throws TLE
	// IMP: Works when array contains both positive and negative numbers
	int longestSubarrayWithSumK1(vector<int>& nums, long long target) {
		long long max = 0
		int length = 0, maxLength = INT_MIN;

		for (int i = 0; i < nums.size(); i++) {
			for (int j = i; j <  nums.size(); j++) {
				max += nums[j];
				length++;
				if (max > target) break;
				if (max == target && length > maxLength) maxLength = length;
			}
			length = 0;
			max = 0;
		}

		return maxLength;
	}

	
	// TC: O(n)
	// SC: O(n)
	// IMP: Works when array contains both positive and negative integers
	int longestSubarrayWithSumK2(vector<int> nums, long long target) {
		int maxLength = 0;
		long sum = 0;
		unordered_map<int, int> hash;

		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (sum == target) {
				maxLength = max(i+1, maxLength);
			} else {
				int more = sum - target;
				if (hash.count(more)) {
					maxLength = max(i - hash[more], maxLength);
				}
			}
			if (!hash.count(sum)) hash[sum] = i;
		}

		return maxLength;
	}

	// TC: O(2n)
	// SC: O(1)
	// IMP: Works when array contains only positive and zeroes
	int longestSubarrayWithSumK3(vector<int>& nums, long long target) {
		int maxLength = 0;
		long long sum = 0;
		int i = 0, j = 0;

		while (i < nums.size()) {
			if (sum + nums[i] <= target) {
				sum += nums[i];
				if (sum == target) {
					maxLength = max(i-j+1, maxLength);
					cout << maxLength << endl;
				}
				i++;
			} else {
				sum -= nums[j];
				j++;
			}
		}

		return maxLength;
	}
};

int main() {
	Solution sol;

	vector<int> i1 = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
	vector<int> i2 = {1, 2, 1, 3};
	vector<int> i3 = {2, 2, 4, 1, 2};
	vector<int> i4 = {3, 1, 1, 1, 1, 4, 3, 1, 1, 1, 3};

	cout << sol.longestSubarrayWithSumK3(i2, 1);
}