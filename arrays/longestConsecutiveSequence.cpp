/**
 * @file 128. Longest Consecutive Sequence (Leetcode Medium)
 * @link https://leetcode.com/problems/longest-consecutive-sequence
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 24-08-2023
*/  

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::max;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int prev = nums[0], len = 1, maxLen = 0;
		int n = nums.size();

		if (n <= 1) return n;
		for (int i = 1; i < n; i++) {
			if (prev + 1 == nums[i]) {
				len++;
			} else if (prev == nums[i]){
				continue;
			} else {
				len = 1;
			}
			prev = nums[i];
			maxLen = max(maxLen, len);
		}
		
		return maxLen;
	}
};

int main() {
	Solution sol;

	vector<int> i1 = {100, 4, 200, 1, 3, 2};
	vector<int> i2 = {0,3,7,2,5,8,4,6,0,1};
	vector<int> i3 = {1, 4};
	vector<int> i4 = {};
	vector<int> i5 = {1, 2, 0, 1};

	cout << sol.longestConsecutive(i1) << endl;
	cout << sol.longestConsecutive(i3) << endl;
	cout << sol.longestConsecutive(i5) << endl;
}