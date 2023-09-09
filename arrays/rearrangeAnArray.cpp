/**
 * @file Rearrange an array with O(1) extra space (GeeksForGeeks Medium)
 * @link https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 09-09-2023
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
	void arrange(long long list[], int n) {
		for (int i = 0; i < n; i++) {
			list[i] += (list[list[i]]%n) * n;
		}

		for (int j = 0; j < n; j++) {
			list[j] = list[j]/n;
		}

		// Checking if the rearrangement is correct
		for (int  k = 0; k < n; k++) {
			cout << list[k] << " ";
		} cout << endl;
	}
};

int main() {
	Solution sol;

	long long i1[] = {3, 1, 0, 4, 2, 6, 5, 7, 8};

	sol.arrange(i1, 9);
}

