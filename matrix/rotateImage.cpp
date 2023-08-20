/*
 * @file 48. Rotate Image (Leetcode Medium)
 * @brief You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise). You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
 * @link https://leetcode.com/problems/rotate-image/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 18-07-2023
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::swap;
using std::reverse;

class Solution {
	void printMatrix(vector<vector<int>>& matrix) {
		for (auto i: matrix) {
			for (auto j: i) {
				cout << j << " ";
			} cout << endl;
		}
	}

public:
	// Better
	void rotate1(vector<vector<int>>& matrix) {
		int n = matrix.size();

		// O(n^2/4)
		for (int i = 0; i < n-1; i++) {
			for (int j = i+1; j < n; j++) {
				swap(matrix[j][i], matrix[i][j]);
			}
		}

		// O(n^2/2)
		for (int i = 0; i < n; i++) {
			reverse(matrix[i].begin(), matrix[i].end());
		}

		printMatrix(matrix);
	}

	// O(n^2/2)
	// Optimal
	void rotate2(vector<vector<int>>& matrix) {
		int layer = 1;
		int n = matrix.size();

		while (layer <= n/2) {
			for (int i = layer-1; i < n-layer; i++) {
				int temp = matrix[layer-1][i];
				swap(temp, matrix[i][n-layer]);
				swap(temp, matrix[n-layer][n-i-1]);
				swap(temp, matrix[n-i-1][layer-1]);
				swap(temp, matrix[layer-1][i]);
			}
			layer++;
		}

		printMatrix(matrix);
	}
};

int main() {
	Solution sol;

	vector<vector<int>> i1 = {
		{5, 1, 9, 11},
		{2, 4, 8, 10},
		{13, 3, 6, 7},
		{15, 14, 12, 16}
	};

	vector<vector<int>> i2 = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	sol.rotate1(i1);

	// sol.rotate2(i1);
}