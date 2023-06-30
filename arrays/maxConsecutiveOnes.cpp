/**
 * @file 485. Max Consecutive Ones
 * @brief Given a binary array nums, return the maximum number of consecutive 1's in the array.
 * @link https://leetcode.com/problems/max-consecutive-ones
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 30-06-2023
*/	

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution {
public:
	// Method 1
	int findMaxConsecutiveOnes1(vector<int>& nums) {
		int count = 0, temp = 0;
		for (int n: nums) {
			if (n) temp++;
			else {
				count = max(temp, count);
				temp = 0;
			}
		}
		count = max(temp, count);
		return count;
	}

	// Method 2
	int findMaxConsecutiveOnes2(vector<int>& nums) {
		int mx = 0, pos = 0;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (nums[i] == 0) {
				mx = max(mx, i-pos);
				pos = i+1;
			}
		}
		mx = max(mx, n-pos);
		return mx;
	}
};

int main() {
	Solution sol;
	vector<int> i1 = {1, 1, 0, 1, 1, 1};
	vector<int> i2 = {0, 1, 0, 0, 1, 0, 1, 1, 1, 0};
	vector<int> i3 = {1};
	vector<int> i4 = {0};
	cout << sol.findMaxConsecutiveOnes2(i4);

	return 0;
}