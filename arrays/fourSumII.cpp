/**
 * @file 454. 4Sum II (Leetcode Medium)
 * @link https://leetcode.com/problems/4sum-ii
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 09-09-2023
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::unordered_map;

class Util {
public:
	static void printArray(vector<int>& nums) {
		for (auto i: nums) {
			cout << i << " ";
		} cout << endl;
	}

	static void print2dArray(vector<vector<int>>& nums) {
		for (auto i: nums) {
			for (auto j: i) {
				cout << j << " ";
			} cout << endl;
		}
	}
};

class Solution {
public:
	// TC: O(n^3)
	// SC: O(n)
	// Throws TLE
	int fourSumCount1(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		int cnt = 0, n = nums1.size();

		unordered_map<int, int> num4map;
		for (int i = 0; i < n; i++) num4map[nums4[i]]++;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					int sum = nums1[i] + nums2[j];
					sum = -(sum + nums3[k]);
					if (num4map.count(sum)) {
						cnt += num4map[sum];
					}
				}
			}
		}

		return cnt;
	}

	// TC: O(n^2)
	// SC: O(n^2)
	int fourSumCount2(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		int cnt = 0, n = nums1.size();
		unordered_map<int, int> twoSum;

		for (int i: nums1) {
			for (int j: nums2) {
				twoSum[i+j]++;
			}
		}

		for (int k: nums3) {
			for (int l: nums4) {
				int more = -(k+l);
				if (twoSum.count(more)) {
					cnt += twoSum[more];
				}
			}
		}

		return cnt;
	}
};

int main() {
	Solution sol;

	// vector<int> nums1 = {1, 2};
	// vector<int> nums2 = {-2, -1};
	// vector<int> nums3 = {-1, 2};
	// vector<int> nums4 = {0, 2};

	vector<int> nums1 = {0, -2, 1};
	vector<int> nums2 = {-1, 1, 0};
	vector<int> nums3 = {1, 2, 0};
	vector<int> nums4 = {0, 0, 1};

	cout << sol.fourSumCount2(nums1, nums2, nums3, nums4) << endl;
}