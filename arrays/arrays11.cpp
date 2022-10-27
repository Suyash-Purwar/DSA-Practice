/**
 * @file Transpose Matrix (Leetcode Easy)
 * @brief Given a 2D integer array matrix, return the transpose of matrix.
 * @link https://leetcode.com/problems/transpose-matrix/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 27-10-2022
*/
#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
    public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix) {
        vector<vector<int>> transposedMatrix;
        vector<int> temp;
        for (int i = 0; i < matrix[0].size(); i++) {
            for (int l = 0; l < matrix.size(); l++) {
                temp.push_back(matrix[l][i]);
            }
            transposedMatrix.push_back(temp);
            temp.clear();
        }
        return transposedMatrix;
    }
};

int main() {
    Solution sol;
    // vector<vector<int>> matrix = {
    //     {2, 4, -1},
    //     {-10, 5, 11},
    //     {10, 14, -3}
    // };
    vector<vector<int>> matrix = {
        {2, 4,},
        {-10, 5},
        {10, 14}
    };
    vector<vector<int>> transposedMatrix = sol.transpose(matrix);

    for (int k = 0; k < transposedMatrix.size(); k++) {
        for (int m = 0; m < transposedMatrix[k].size(); m++) {
            cout << transposedMatrix[k][m] << " ";
        }
        cout << endl;
    }

    return 0;
}