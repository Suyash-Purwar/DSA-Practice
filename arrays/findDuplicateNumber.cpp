/**
 * @file Duplicates in Array
 * @brief You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.
 * @link https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 16-06-2023
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
	// Method 1 - Sort the vector and check if any adjacent elements are same. If yes, return that element.
	// TC: O(nlogn + n)
	// SC: O(1)
	int findDuplicate1(vector<int>& nums) {
		sort(nums.begin(), nums.end()); // O(nlogn)
		for (int i = 1; i < nums.size(); i++) { // O(n)
			if (nums[i-1] == nums[i]) return nums[i];
		}
		return -1;
	}

	// Method 2 - Hashing
	// TC: O(2n)
	// SC: O(n)
	int findDuplicate2(vector<int> &nums) {
		vector<int> hash(nums.size(), 0);
		for (int n: nums) hash[n]++;
		for (int i = 0; i < hash.size(); i++) {
			if (hash[i] == 2) return i;
		}
		return -1;
	}

	// Method 3 (Optimal)
	// TC: O(n)
	// SC: O(1)
	int findDuplicate3(vector<int>& nums) {
		int n = nums.size()-1;
		int sum = 0;
		for (auto i: nums) {
			sum += i;
		}
		return sum - (n*(n+1))/2;
	}

	// Method 4 (Optimal)
	// TC: O(n)
	// SC: O(1)
	int findDuplicate4(vector<int>& nums) {
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			ans ^= (nums[i] ^ i);
		}
		return ans;
	}
};

int main() {
	vector<int> arr = {1, 2, 3, 3};
	Solution sol;
	cout << sol.findDuplicate3(arr);

	return 0;
}