/**
 * @name 338. Counting Bits
 * @brief Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
 * @link https://leetcode.com/problems/counting-bits/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 15-06-23
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// Implementation 1 - O(nlogn)
	vector<int> countBits1(int n) {
		vector<int> ans = {0}; int i = 1;
		while (i <= n) {
			int m = i, count = 0;
			while (m != 0) {
				if (m & 1) count++;
				m = m >> 1;
			}
			ans.push_back(count);
			i++;
		}
		return ans;
	}

	// Implementation 2 - O(n)
	vector<int> countBits2(int n) {
		vector<int> ans = {0};
		for (int i = 1; i <= n; i++) {
			ans.push_back(ans[i/2] + i%2);
		}
		return ans;
	}
};

int main() {
	Solution sol;
	// vector<int> ans = sol.countBits(-1);
	vector<int> ans = sol.countBits2(4);

	for (auto i: ans) {
		cout << i << endl;
	}
}