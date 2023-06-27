/**
 * @file Second largest element in the array
 * @brief You have been given an array/list 'ARR' of integers. Your task is to find the second largest element present in the 'ARR'.
 * @link https://www.codingninjas.com/studio/problems/second-largest-element-in-the-array_873375
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 27-06-2023
*/	

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::cout;
using std::endl;
using std::vector;
using std::sort;

class Solution {
public:
	// Method 1 - Brute force
	// TC : O(n+nlogn)
	// SC : O(1)
	int findSecondLargest1(int n, vector<int> &arr) {
		sort(arr.begin(), arr.end());
		for (int i = n-1; i > 0; i--) {
			if (arr[i] != arr[i-1]) return arr[i-1];
		}
		return -1;
	}

	// Method 2 - Optimal
	// TC : O(n)
	// SC : O(1)
	int findSecondLargest2(int n, vector<int> &arr) {
		bool isAllSame = 1; int prev = arr[0];
		int fMax = INT_MIN; int sMax;
		for (int i = 0; i < n; i++) {
			if (prev != arr[i]) isAllSame = 0;
			if (arr[i] > fMax) {
				sMax = fMax;
				fMax = arr[i];
			} else if (arr[i] > sMax && arr[i] != fMax) {
				sMax = arr[i];
			}
		}
		return (isAllSame ? -1 : sMax);
	}
};

int main() {
	// vector<int> i1 = {4, 1, 0, -3, 39, 39, 20, 20, 21, 40};
	vector<int> i1 = {4, 4, 4};
	Solution sol;
	int ans = sol.findSecondLargest2(3, i1);
	cout << ans;
}