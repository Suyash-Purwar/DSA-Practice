/**
 * @file 136. Single Number (Leetcode Easy)
 * @brief Given a non-empty array of integers nums, every element appears twice except for one. Find that single one. You must implement a solution with a linear runtime complexity and use only constant extra space.
 * @link https://leetcode.com/problems/single-number
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 16-06-2023
*/	

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	 * Rule: A ^ A = 0
	 * Rule: (A ^ B) ^ C = A ^ (B ^ C)
	 * Rule: A ^ 0 = A
	 * So, it can be said => A ^ B ^ A = B
	 */
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			ans = ans ^ nums[i];	
		}
		return ans;
	}
};

int main() {
	Solution sol;
	vector<int> num1 = {1, 2, 1, 2, 3};
	vector<int> num2 = {8};
	vector<int> num3 = {0, -1, -1, 0, 5};

	cout << sol.singleNumber(num1) << endl;
	cout << sol.singleNumber(num2) << endl;
	cout << sol.singleNumber(num3) << endl;

	return 0;
}