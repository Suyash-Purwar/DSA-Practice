/**
 * @file Duplicates in Array
 * @brief You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.
 * @link https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 16-06-2023
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// Method 1 (Good)
	int findDuplicate1(vector<int>& nums) {
		int size = nums.size();
		int sum = 0;
		for (auto i: nums) {
			sum += i;
		}
		return size - ((size*(size+1))/2 - sum);
	}

	// Method 2 (Best)
	int findDuplicate2(vector<int>& nums) {
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			ans ^= (nums[i] ^ i);
		}
		return ans;
	}
};

int main() {
	vector<int> arr = {1, 2, 2};
	Solution sol;
	cout << sol.findDuplicate2(arr);

	return 0;
}