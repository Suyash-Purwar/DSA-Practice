/**
 * @file Superior Elements
 * @link https://www.codingninjas.com/studio/problems/superior-elements_6783446
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 24-07-2023
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution {
public:
	vector<int> superiorElements(vector<int>& nums) {
		int n = nums.size()-1, maxi = INT_MIN;
		vector<int> ans;

		while (n >= 0) {
			if (nums[n] > maxi) {
				ans.push_back(nums[n]);
				maxi = nums[n];
			}
			n--;
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<int> i1 = {1, 4, 3, 1, 2};

	vector<int> o1 = sol.superiorElements(i1);

	for (int i: o1) {
		cout << i << " ";
	} cout << endl;
}