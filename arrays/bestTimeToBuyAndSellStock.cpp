/**
 * @file 121. Best Time to Buy and Sell Stock (Leetcode Easy)
 * @link https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 24-07-2023
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::min;

class Solution {
public:
	// Gives TLE
	// TC: O(n^2)
	// SC: O(1)
	int maxProfit1(vector<int>& prices) {
		int maxProfit = 0;

		for (int i = 0; i < prices.size()-1; i++) {
			for (int j = i+1; j < prices.size(); j++) {
				if (prices[j] > prices[j]) maxProfit = prices[j] - prices[i];
			}
		}

		return maxProfit;
	}

	int maxProfit2(vector<int>& prices) {
		int mini = prices[0];
		int profit = 0;

		for (int i = 1; i < prices.size(); i++) {
			int cost = prices[i] - mini;
			profit = max(cost, profit);
			mini = min(mini, prices[i]);
		}

		return profit;
	}
};

int main() {
	Solution sol;

	vector<int> i1 = {7, 1, 5, 3, 6, 4};
	vector<int> i2 = {7, 6, 4, 3, 1};
	vector<int> i3 = {2, 4, 1};
	cout << sol.maxProfit2(i1) << endl;
}