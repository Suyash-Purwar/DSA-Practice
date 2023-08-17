#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::sort;

class Solution {
	void printMap(unordered_map<int, int>& map) {
		unordered_map<int, int>::iterator it = map.begin();

		while (it != map.end()) {
			cout << it->first << " " << it->second << endl;
			it++;
		}
	}

public:
	// TC: O(n^2)
	// SC: O(1)
	vector<int> twoSum1(vector<int>& nums, int target) {
		vector<int> ans;
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			int k = n-1;
			while (i < k) {
				if (nums[i] + nums[k] == target) {
					ans.push_back(i);
					ans.push_back(k);
					return ans;
				}
				k--;
			}
		}

		return ans;
	}

	// TC: O(2n)
	// SC: O(n)
	// Approach: Two-pass Hash Table
	vector<int> twoSum2(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		vector<int> ans;

		for (int i = 0; i < nums.size(); i++) hash[nums[i]] = i;
		
		for (int i = 0; i < nums.size(); i++) {
			int k = target - nums[i];
			if (hash[k] != 0 && hash[k] != i) {
				ans.push_back(i);
				ans.push_back(hash[k]);
				break;
			}
		}

		return ans;
	}

	// TC: O(n)
	// SC: O(n)
	// Approach: One-pass Hash Table (Very interesting)
	vector<int> twoSum3(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		vector<int> ans;

		for (int i = 0; i < nums.size(); i++) {
			int k = target - nums[i];
			if (hash.count(k)) {
				ans.push_back(hash[k]);
				ans.push_back(i);
				break;
			}
			hash[nums[i]] = i;
		}

		return ans;
	}

	/**
	 * There's a variety of this question which just asks if there are any two integers which sum upto the target value.
	 * Return true if exists, otherwise false.
	 * Below is the solution for this scenario. The following code cannot be implemented for the original question
	 */
	int twoSum4(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int right = nums.size() - 1;
		int left = 0;

		while (left < right) {
			int sum = nums[left] + nums[right];

			if (sum == target) return true;
			else if (sum < target) left++;
			else if (sum > target) right--;
		}

		return false;
	}
};

int main() {
	Solution sol;

	vector<int> i1 = {0, 1, 0, -2};

	vector<int> opt = sol.twoSum3(i1, -2);

	for (auto i: opt) {
		cout << i << " ";
	} cout << endl;
}
