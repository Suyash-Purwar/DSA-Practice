/**
 * @file Cyclically rotate an array by one
 * @brief Given an array, rotate the array by one position in clock-wise direction.
 * @link https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 27-06-2023
*/	
#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
	void rotate(int arr[], int n) {
		int last = arr[n-1];
		for (int i = n-1; i > 0; i--) {
			arr[i] = arr[i-1];
		}
		arr[0] = last;

		for (int j = 0; j < n; j++) cout << arr[j] << " ";
		cout << endl;
	}
};

int main() {
	Solution sol;
	int arr[5] = { 1 };
	sol.rotate(arr, 1);
}
