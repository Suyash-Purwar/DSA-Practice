
/**
 * @file 2149. Rearrange Array Elements by Sign (Leetcode Medium)
 * @link https://leetcode.com/problems/rearrange-array-elements-by-sign/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 23-07-2023
*/  

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;
using std::endl;
using std::swap;

class Solution {
	void printArray(vector<int>& nums) {
		for (int i: nums) {
			cout << i << " ";
		} cout << endl;
	}
public:
	// TC: O(n + n/2)
	// SC: O(n)
	vector<int> rearrangeArray1(vector<int>& nums) {
		int n = nums.size();
		vector<int> positives;
		vector<int> negatives;

		// O(n)
		for (int i: nums) {
			i > 0 ? positives.push_back(i) : negatives.push_back(i);
		}

		// O(n/2)
		for (int i = 0; i < n/2; i++) {
			nums[2*i] = positives[i];
			nums[2*i+1] = negatives[i];
		}

		return nums;
	}

	// TC: O(n)
	// SC: O(n)
	vector<int> rearrangeArray2(vector<int>& nums) {
		int n = nums.size(), i = 0, j = 1;
		vector<int> ans(n, 0);
		for (int num: nums) {
			if (num > 0) {
				ans[i] = num;
				i+=2;
			} else {
				ans[j] = num;
				j+=2;
			}
		}
		return ans;
	}
};

int main() {
	Solution sol;

	// vector<int> i1 = {3, 1, -2, -5, 2, -4};
	// vector<int> i1 = {-1, -2, -3, 4, 5, 6};
	// vector<int> i1 = {1, 2, -3, -4, -5, 6};
	vector<int> i1 = {1, 2, 3, -4, -5, -6};

	vector<int> o1 = sol.rearrangeArray2(i1);

	for (int i: o1) {
		cout << i << " ";
	}
	cout << endl;
}