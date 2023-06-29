/**
 * @file Rotating an Array
 * @brief Given an array of size N. The task is to rotate array by D elements where D ≤ N.
 * @link https://practice.geeksforgeeks.org/problems/reversal-algorithm5340/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 29-06-2023
*/	

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::reverse;

// Note the case where d > n is not handled

class Solution {
public:
	// Method - 1 (Brute force) (TLE)
	// TC: O(n^2)
	// SC: O(1)
	void leftRotate1(int arr[], int n, int d) {
		while (d > 0) {
			int temp = arr[0];
			for (int i = 1; i < n; i++) {
				arr[i-1] = arr[i];
			}
			arr[n-1] = temp;
			d--;
		}

		for (int i = 0; i < n; i++) cout << arr[i] << " ";
		cout << endl;
	}

	// Method - 2 (Better)
	// TC : O(2n)
	// SC : O(n)
	void leftRotate2(int arr[], int n, int d) {
		int ans[n] = {}; int k = 0;
		for (int i = d; i < n; i++, k++) { // O(n - d)
			ans[k] = arr[i];
		}
		for (int j = 0; j < d; j++, k++) { // O(d)
			ans[k] = arr[j];
		}
		// Static arrays cannot be copied like this. Vectors can be copied like this though.
		// But this question is using static arrays. So, we can't switch to vectors here.
		// arr = ans;
		copy(ans, ans+n, arr); // It has a complexity of O(n)
	}

	// Method - 3 (Better) (Optimized for time)
	// TC : O(n + d)
	// SC : O(d)
	void leftRotate3(int arr[], int n, int d) {
		int temp[d];
		for (int i = 0; i < d; i++) { // O(d)
			temp[i] = arr[i];
		}
		for (int j = d; j < n; j++) { // O(n - d)
			arr[j - d] = arr[j];
		}
		for (int k = 0; k < d; k++) { // O(d)
			arr[n - d + k] = temp[k];
		}
		// Printing the output
		for (int l = 0; l < n; l++) cout << arr[l] << " ";
		cout << endl;
	}

	// Method - 4 (Same as before) (Optimized for time)
	// TC : O(n + d)
	// SC : O(d)
	void leftRotate4(int arr[], int n, int d) {
		int temp[d];
		copy(arr, arr + d, temp); // O(d)
		copy(arr + d, arr + n, arr); // O(n - d)
		copy(temp, temp + d, arr + n - d); // O(d)
		// Printing the output
		for (int l = 0; l < n; l++) cout << arr[l] << " ";
		cout << endl;
	}

	// Method - 5 (Optimized for space)
	// TC : O(2n)
	// SC : O(1)
	void leftRotate5(int arr[], int n, int d) {
		reverse(arr, arr + d);
		reverse(arr + d, arr + n);
		reverse(arr, arr + n);
		// Printing the output
		for (int l = 0; l < n; l++) cout << arr[l] << " ";
		cout << endl;
	}
};

int main() {
	Solution sol;
	int arr[6] = {1, 2, 3, 4, 5, 6};
	sol.leftRotate5(arr, 6, 1);
	return 0;
}