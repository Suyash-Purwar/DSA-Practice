/**
 * @file 189. Rotate Array (LC Medium)
 * @brief Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
 * @link https://leetcode.com/problems/rotate-array/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 29-06-2023
*/	

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
	// When vector<int> is the type of incoming array in the parameters
	// TC: O(n)
	// SC: O(1)
	void leftRotate(vector<int>& nums, int d) {
		int size = nums.size();
		vector<int> ans(size);
		for (int i = 0; i < size; i++) { // O(n)
			ans[(size-d+i)%size] = nums[i];
		}
		nums = ans;

		// Printing the result
		for (int n: nums) {
			cout << n << " ";
		} cout << endl;
	}

	// TC: O(n)
	// SC: O(1)
	void rightRotate(vector<int>& nums, int d) {
		int size = nums.size();
		vector<int> ans(size);
		for (int i = 0; i < size; i++) {
			ans[(d+i)%size] = nums[i];
		}
		nums = ans;

		// Printing the result
		for (int n: nums) {
			cout << n << " ";
		} cout << endl;
	}
};

int main() {
	vector<int> i1 = {1, 2, 3, 4, 5, 6, 7};
	vector<int> i2(i1);
	Solution sol;
	sol.leftRotate(i1, 5);
	sol.rightRotate(i2, 4);
}