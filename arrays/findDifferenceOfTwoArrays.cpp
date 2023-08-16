/**
 * @file 2215. Find the Difference of Two Arrays (Leetcode Easy)
 * @brief Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where: answer[0] is a list of all distinct integers in nums1 which are not present in nums2. answer[1] is a list of all distinct integers in nums2 which are not present in nums1. Note that the integers in the lists may be returned in any order.
 * @link https://leetcode.com/problems/find-the-difference-of-two-arrays/description/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 16-08-2023
*/	

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::binary_search;

class Solution {
public:
	vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> ans;
		vector<int> temp;

		sort(nums1.begin(), nums1.end()); // nlogn
		sort(nums2.begin(), nums2.end()); // mlogm

		int last = INT_MIN;

		for (int i = 0; i < nums1.size(); i++) { // nlogn
			bool isFound = binary_search(nums2.begin(), nums2.end(), nums1[i]);
			
			if (isFound == 0 && last != nums1[i]) {
				temp.push_back(nums1[i]);
				last = nums1[i];
			}
		}
		ans.push_back(temp);
		temp.clear();
		last = INT_MIN;
		for (int i = 0; i < nums2.size(); i++) { // mlogm
			bool isFound = binary_search(nums1.begin(), nums1.end(), nums2[i]);
			
			if (isFound == 0 && last != nums2[i]) {
				temp.push_back(nums2[i]);
				last = nums2[i];
			}
		}
		ans.push_back(temp);

		return ans;
	}
};

int main() {
	Solution sol;

	vector<int> i1 = {};
	vector<int> i2 = {1, 6, 7, 1};

	vector<vector<int>> ans = sol.findDifference(i1, i2);

	for (auto i: ans) {
		for (auto j: i) {
			cout << j << " ";
		} cout << endl;
	}

	return 0;
}