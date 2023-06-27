/**
 * @file Find minimum and maximum element in an array
 * @brief Given an array A of size N of integers. Your task is to find the minimum and maximum elements in the array.
 * @link https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 27-06-2023
*/	

#include <iostream>
#include <vector>
#include <climits>
#include <utility>

using std::vector;
using std::cout;
using std::endl;
using std::cout;
using std::pair;
using std::make_pair;

/**
 * Pair in C++ behaves similarly to tuple in python. It consists of two elements {first, second}. The first element is referred to as first while the second element is referred to as second. This order must be fixed (first, second). The header file for Pair in C++ is <utility>, and it is also a container class in STL (standard template library).
 */

class Solution {
public:
	pair<long long, long long> getMinMax(long long a[], int n) {
		long long max = LLONG_MIN;
		long long min = LLONG_MAX;

		for (int i = 0; i < n; i++) {
			if (a[i] > max) max = a[i];
			if (a[i] < min) min = a[i];
		}
		return make_pair(min, max);
	}
};

int main() {
	Solution sol;
	long long a[10] = {53242, 50124, 9083, 10482, 94023, 19302, 18362, 0, -18423, 773913};
	pair<int, int> ans = sol.getMinMax(a, 10);
	cout << ans.first << " " << ans.second << endl;

}