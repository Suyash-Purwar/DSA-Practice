#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution {
public:
	int lenOfLongSubarr1(int arr[], int n, int k) {
		int i = 0, window = 0, sum, j;

		while (arr[i] > k) i++;
		sum = arr[i];
		j = i+1;

		while (j < n) {
			if (sum + arr[j] <= k) {
				sum += arr[j];
			} else if (sum <= k) {
				if (sum == k) window = max(window, j-i);
				i++;
				sum = arr[i];
			}
			j++;
		}
		if(sum == k) window = max(window, j-i);
		return window;
	}
};

int main() {
	Solution sol;
	int i1[] = {1, 1, 1};
	int i2[] = {10, 5, 2, 7, 1, 9};
	int i3[] = {-1, 2, 3};
	int i4[] = {9, 6, 5, 3, 0, 1};
	// cout << sol.lenOfLongSubarr1(i2, 6, 15);
	// cout << sol.lenOfLongSubarr1(i1, 3, 2);
	cout << sol.lenOfLongSubarr1(i3, 3, 6);
	// cout << sol.lenOfLongSubarr1(i4, 6, 9);
}