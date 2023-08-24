#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::max;

/**
 * @file 1299. Replace Elements with Greatest Element on Right Side (Leetcode Easy)
 * @link https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 24-08-2023
*/  

class Solution {
public:
	vector<int> superiorElements(vector<int>& nums) {
		int maxi = INT_MIN, n = nums.size()-1;

		while (n >= 0) {
			int temp = nums[n];
			n == nums.size()-1 ? nums[n] = -1 : nums[n] = maxi;
			maxi = max(maxi, temp);
			n--;
		}

		return nums;
	}
};

int main() {
	Solution sol;

	vector<int> i1 = {17,18,5,4,6,1};
	vector<int> i2 = {400};
	vector<int> i3 = {1, 21, 45, 20, 10};
	vector<int> i4 = {2, 1};
	vector<int> o1 = sol.superiorElements(i4);

	for (int i: o1) {
		cout << i << " ";
	} cout << endl;
}