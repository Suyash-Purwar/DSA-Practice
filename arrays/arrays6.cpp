/**
 * @file arrays6.cpp
 * @brief Given an m x n matrix, return all elements of the matrix in spiral order.
 * @link https://leetcode.com/problems/spiral-matrix/
 * @author Suyash Purwar (github.com/suyash-purwar)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printSpiralMatrix(vector<vector<int>>& matrix) {
        vector<int> res;
        int top = 0;
        int left = 0;
        int direction = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            cout << top << left << right << bottom << endl;
            if (direction == 0) {
                for (int i = left; i <= right; i++) {
                    res.push_back(matrix[top][i]);
                }
                top++;
                direction = 1;
            } else if (direction == 1) {
                for (int j = top; j <= bottom; j++) {
                    res.push_back(matrix[j][right]);
                }
                right--;
                direction = 2;
            } else if (direction == 2) {
                for (int k = right; k >= left; k--) {
                    res.push_back(matrix[bottom][k]);
                }
                bottom--;
                direction = 3;
            } else if (direction == 3) {
                for (int l = bottom; l >= top; l--) {
                    res.push_back(matrix[l][left]);
                }
                left++;
                direction = 0;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<int> res = sol.printSpiralMatrix(matrix);
    // for (int a = 0; a < res.size(); a++) {
    //     cout << res[a] << "  ";
    // }
    // cout << endl;
    return 0;
}