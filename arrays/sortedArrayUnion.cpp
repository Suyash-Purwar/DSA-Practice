/**
 * @file Union of Two Sorted Arrays
 * @brief Union of two arrays can be defined as the common and distinct elements in the two arrays. Given two sorted arrays of size n and m respectively, find their union.
 * @link https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 26-06-2023
*/	

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using std::cout;
using std::endl;
using std::set;
using std::vector;
using std::sort;

class Solution {
public:
	// Method 1
	// TC: O(n+m)
	// SC: O(n+m)
	vector<int> findUnion1(int arr1[], int arr2[], int n, int m) {
		set<int> joined;
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			joined.insert(arr1[i]);
		}
		for (int j = 0; j < m; j++) {
			joined.insert(arr2[j]);
		}
		for (int n: joined) {
			ans.push_back(n);
		}
		return ans;
	}
	// Method 2
	// TC: O(n+m)
	// Space Complexity: No extra space
	vector<int> findUnion2(int arr1[], int arr2[], int n, int m) {
		vector<int> ans;
		int i = 0, j = 0, last = INT_MIN;
		while (i < n && j < m) {
			if (arr1[i] >= arr2[j]) {
				if (arr2[j] != last) ans.push_back(arr2[j]);
				last = arr2[j];
				j++;
				if (arr1[i] == arr2[j]) i++;
			} else if (arr1[i] < arr2[j])  {
				if (arr1[i] != last) ans.push_back(arr1[i]);
				last = arr1[i];
				i++;
			}
		}
		while (i < n) {
			if (arr1[i] != last && arr1[i] > last) {
				ans.push_back(arr1[i]);
				last = arr1[i];
			}
			i++;
		}
		while (j < m) {
			if (arr2[j] != last && arr2[j] > last) {
				ans.push_back(arr2[j]);
				last = arr2[j];
			}
			j++;
		}
		return ans;
	}
};

int main() {
	Solution sol;
	int v1[] = {};
	int v2[] = {1, 1, 2};
	// int v1[] = {2, 2, 3, 4, 5};
	// int v2[] = {1, 1, 2, 3, 4, 6};
	vector<int> ans = sol.findUnion2(v1, v2, 0, 3);

	for (int n: ans) {
		cout << n << " ";
	} cout << endl;
}