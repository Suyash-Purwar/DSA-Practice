
/**
 * @file Check if array is sorted
 * @brief Given an array arr[] of size N, check if it is sorted in non-decreasing order or not. 
 * @link hhttps://practice.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 27-06-2023
*/	
#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
	// Method 1 - Brute force
	// TC: O(n)
	// SC: O(1)
	bool arraySortedOrNot1(int arr[], int n) {
		for (int i = 1; i < n; i++) {
			if (arr[i-1] > arr[i]) return 0;
		}
		return 1;
	}

	// Method 2 - Optimal
	// TC: O(n/2)
	// SC: O(1)
	bool arraySortedOrNot2(int arr[], int n) {
		for (int i = 0; i <= n/2; i++) {
			if (arr[i] > arr[i+1]) return 0;
			if (arr[(n-1)-i] < arr[(n-2)-i]) return 0;
		}
		return 1;
	}

};

int main() {
	Solution sol;
	int arr[8] = {4, 4, 9, 13, 23, 40, 40};
	// int arr[1] = {4};
	cout << sol.arraySortedOrNot2(arr, 7);
}