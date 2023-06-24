/**
 * @file 442. Intersection Of Two Sorted Arrays (Coding Ninjas Easy)
 * @brief You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays. Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.
 * @link https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 25-06-2023
*/	

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::swap;

class Solution {
public:
	vector<int> findArrayIntersection(vector<int>& num1, vector<int>& num2) {
		vector<int> ans;
		int num2_index = 0;
		for (int i = 0; i < num1.size(); i++) {
			if (arr2_index == m) break;
			if (num2[num2_index] > num1[i]) continue;
			else if (num2[num2_index] == num1[i]) ans.push_back(num1[i]);
			else i--;
			num2_index++;
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<int> vec2 = {0, 0, 5, 5, 8, 10, 10, 11, 12, 15, 17, 17, 17 };
	vector<int> vec1 = {1, 2, 4, 5, 5, 6, 9, 9, 12, 12, 12 };
	// vector<int> vec1 = {1, 4, 5};
	// vector<int> vec2 = {3, 4, 5};
	// vector<int> vec1 = {1};
	// vector<int> vec2 = {2};

	vector<int> ans = sol.findArrayIntersection(vec1, vec2);
	for (int i: ans) {
		cout << i << " ";
	} cout << endl;
}