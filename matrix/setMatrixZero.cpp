/**
 * @file 73. Set Matrix Zeroes (Leetcode Medium)
 * @brief Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. You must do it in-place.
 * @link https://leetcode.com/problems/set-matrix-zeroes/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 16-08-2023
*/  

#include <iostream>
#include <vector>
#include <climits>

using std::cout;
using std::vector;
using std::endl;

class Solution {
	// Helper Functions
	void printArray(vector<int>& nums) {
		for (int i: nums) {
			cout << i << " ";
		} cout << endl;
	}

	void printMatrix(vector<vector<int>>& matrix) {
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				cout << matrix[i][j] << " ";
			} cout << endl;
		}
	}
public:
	// TC: O(2nm)
	// SC: O(n+m)
	// BETTER
	void setZeroes1(vector<vector<int>>& matrix) {
		vector<int> cols(matrix[0].size(), 0);
		vector<int> rows(matrix.size(), 0);

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] == 0) {
					rows[i] = 1;
					cols[j] = 1;
				}
			}
		}

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (rows[i] || cols[j]) matrix[i][j] = 0;
			}
		}
	}

	// TC: O((mn)*(m+n)+(mn))
	// SC: O(1)
	// BRUTE

	// Note: This solution would work only if the test cases do not contain the integer -1.
	// Note: In Binary Matrix it would work.
	void setZeroes2(vector<vector<int>>& matrix) {
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] == 0) {
					// Mark Rows
					for (int k = 0; k < matrix[0].size(); k++) {
						if (matrix[i][k]) matrix[i][k] = -1;
					}
					// Mark Columns
					for (int l = 0; l < matrix.size(); l++) {
						if (matrix[l][j]) matrix[l][j] = -1;
					}
				}
			}
		}

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] == -1) matrix[i][j] = 0;
			}
		}
	}

	// TC: O(2nm)
	// SC: O(1)
	// OPTIMAL SOLUTION
	void setZeroes3(vector<vector<int>>& matrix) {
		bool col0 = false;

		for (int i = 0; i < matrix.size(); i++) {
			if (matrix[i][0] == 0) col0 = true;

			for (int j = 1; j < matrix[0].size(); j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		for (int i = 1; i < matrix.size(); i++) {
			for (int j = 1; j < matrix[0].size(); j++) {
				if (!(matrix[i][0] && matrix[0][j])) matrix[i][j] = 0;
			}
		}

		if (!matrix[0][0]) {
			for (int i = 0; i < matrix[0].size(); i++) matrix[0][i] = 0;
		}

		if (col0) {
			for (int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
		}

		printMatrix(matrix);
	}

};

int main() {
	vector<vector<int>> i1 = {
		{0, 1, 2, 0},
		{3, 4, 5, 2},
		{1, 3, 0, 5}
	};

	// Do dry run on this code
	// Important input as it would explain why we are doing things we are doing.
	vector<vector<int>> i2 = {
		{7, 1, 0, 5},
		{3, 4, 8, 9},
		{1, 0, 7, 2}
	};

	vector<vector<int>> i3 = {
		{8, 1, 2, 3},
		{3, 4, 5, 2},
		{1, 3, 9, 5}
	};


	Solution sol;

	sol.setZeroes3(i3);
}