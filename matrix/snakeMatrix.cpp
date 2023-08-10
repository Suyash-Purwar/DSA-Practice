#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
	void snakeMatrix(vector<vector<int>>& matrix) {
		int z = matrix[0].size();
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				cout << ((i % 2 == 0) ? matrix[i][j] : matrix[i][z - j - 1]) << " ";
			}
		}
	}
};

int main() {
	Solution sol;

	vector<vector<int>> matrix = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	sol.snakeMatrix(matrix);
}