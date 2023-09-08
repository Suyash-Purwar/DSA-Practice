/**
 * @file 15. 4 Sum (Leetcode Medium)
 * @link https://leetcode.com/problems/4sum/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 08-09-2023
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;

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
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		int n = nums.size();

		if (n < 4) return ans;

		for (int i = 0; i < n-3; i++) {
			if (i > 0 && nums[i] == nums[i-1]) continue;

			for (int j = i+1; j < n-2; j++) {
				if (j != i+1 && nums[j] == nums[j-1]) continue;

				int low = j+1;
				int high = n-1;

				while (low < high) {
					long long int sum = nums[i] + nums[j];
					sum += (nums[high] + nums[low]);

					if (sum < target) {
						low++;
					} else if (sum > target) {
						high--;
					} else {
						ans.push_back({nums[i], nums[j], nums[low], nums[high]});

						while (low < high && nums[low] == nums[low+1]) low++;
						while (low < high && nums[high] == nums[high-1]) high--;
						low++;
						high--;
					}
				}
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	vector<int> i1 = {1, 0, -1, 0, -2, 2};
	vector<int> i2 = {2, 2, 2, 2};

	vector<vector<int>> ans1 = sol.fourSum(i1, 0);
	vector<vector<int>> ans2 = sol.fourSum(i2, 0);

	Util::print2dArray(ans1);
	Util::print2dArray(ans2);
}