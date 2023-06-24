/**
 * @file 442. Find All Duplicates in an Array (Leetcode Medium)
 * @brief Given a non-empty array of integers nums, every element appears twice except for one. Find that single one. You must implement a solution with a linear runtime complexity and use only constant extra space.
 * @link https://leetcode.com/problems/find-all-duplicates-in-an-array
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 25-06-2023
*/	
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;

class Solution {
public:
	vector<int> findDuplicates1(vector<int>& nums) {
		// Method 1 - Bruteforce (TLE)
	    vector<int> ans;
	    for (int i = 0; i < nums.size()-1; i++) {
	        vector<int>::iterator it = nums.begin() + i + 1;
	        for (int j = i+1; j < nums.size(); j++) {
	            if (nums[i] == nums[j]) {
	                nums.erase(it);
	                ans.push_back(nums[i]);
	            }
	            it++;
	        }
	    }
	    return ans;
	}

	vector<int> findDuplicates2(vector<int>& nums) {
		// Method 2 - Sort and compare adjacent elements (Good)
		vector<int> ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++) {
			if(nums[i] == nums[i+1]) {
				ans.push_back(nums[i]);
				i++;
			} 
		}
		return ans;
	}

	vector<int> findDuplicates3(vector<int>& nums) {
		// Method 3 - (Best)
		// Visit each element, and mark the value of nums[abs(nums[i])-1] as
		// negative if it's already not negative
		// If it is negative, then it means an element previously has made this
		// value negative previously. Which implies that current value is duplicate
		// Push this value in the ans vector
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[abs(nums[i])-1] < 0) {
				ans.push_back(abs(nums[i]));
			}
			nums[nums[i]-1] *= -1;
		}
		return ans;
	}
};

int main() {
	Solution sol;
	vector<int> input1 = { 4, 3, 2, 7, 8, 2, 3, 1 };
    vector<int> input2 = { 1, 1, 2, 2 };
    vector<int> input3 = { 2, 2 };

	vector<int> op = sol.findDuplicates3(input1);
	for (int n: op) {
		cout << n << " ";
	} cout << endl;

	return 0;
}