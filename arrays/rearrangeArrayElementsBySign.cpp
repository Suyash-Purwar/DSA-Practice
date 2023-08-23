
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

	/* VARIETY 2 OF THIS QUESTION */
	/* Solve this question with the assumption that count of positive numbers in unequal to count of negative numbers. Put the left over positive/negative numbers at the end of the array while maintaining their sequence */
	vector<int> rearrangeArray3(vector<int>& nums) {
		int n = nums.size();
		vector<int> positives;
		vector<int> negatives;

		for (int i = 0; i < n; i++) {
			if (nums[i] > 0) {
				positives.push_back(nums[i]);
			} else {
				negatives.push_back(nums[i]);
			}
		}

		int posCount = positives.size(), negCount = negatives.size();
		int i = 0, j = 0;
		int index = 0;

		while (i < posCount || j < negCount) {
			if (i < posCount) {
				nums[index] = positives[i];
				index++;
			}

			if (j < negCount) {
				nums[index] = negatives[j];
				index++;
			}

			i++;
			j++;
		}

		return nums;
	}
};

int main() {
	Solution sol;

	// vector<int> i1 = {3, 1, -2, -5, 2, -4};
	// vector<int> i1 = {-1, -2, -3, 4, 5, 6};
	// vector<int> i1 = {1, 2, -3, -4, -5, 6};
	vector<int> i1 = {1, 2, 3, -4, -5, -6};

	vector<int> o1 = sol.rearrangeArray2(i1);

	vector<int> i2 = {-4, -2, 3, 8, 9, 1, -1, 7};

	vector<int> o2 = sol.rearrangeArray3(i2);

	for (int i: o2) {
		cout << i << " ";
	}
	cout << endl;
}