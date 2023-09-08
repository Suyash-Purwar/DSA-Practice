/**
 * @file 167. Two Sum II - Input Array Is Sorted (Leetcode Medium)
 * @link https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 08-09-2023
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
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
	// TC: O(n)
	// SC: O(1)
	vector<int> twoSum1(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		vector<int> ans;

		for (int i = 0; i < nums.size(); i++) {
			int more = target - nums[i];

			if (hash.count(more)) {
				ans.push_back(hash[more]+1);
				ans.push_back(i+1);
				break;
			}

			hash[nums[i]] = i;
		}

		return ans;
	}

	vector<int> twoSum2(vector<int>& nums, int target) {
		vector<int> ans;
		int low = 0, high = nums.size()-1;

		while (low < high) {
			if (nums[low]+nums[high] < target) {
				low++;
			} else if (nums[low]+nums[high] > target) {
				high--;
			} else {
				ans.push_back(low+1);
				ans.push_back(high+1);
				break;
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	vector<int> i1 = {-2, 0, 1};
	vector<int> i2 = {-1, 0, 0, 1};
	vector<int> i3 = {2, 3, 4};

	vector<int> ans1 = sol.twoSum2(i1, 1);
	vector<int> ans2 = sol.twoSum2(i2, 0);
	vector<int> ans3 = sol.twoSum2(i3, 7);


	Util::printArray(ans1);
	Util::printArray(ans2);
	Util::printArray(ans3);
}