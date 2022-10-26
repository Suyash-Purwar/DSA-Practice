/**
 * @name Pascal's Triangle (LeetCode Easy)
 * @brief Given an integer numRows, return the first numRows of Pascal's triangle.
 * @link https://leetcode.com/problems/pascals-triangle/
 * @author Suyash Purwar (github.com/suyash-purwar)
 */

#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::cin;
using std::vector;

class Solution {
    public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle = {{1}};
        vector<int> temp;

        for (int m = 1; m < numRows; m++) {
            int i = -1; int j = 0;
            for (int n = 0; n < m + 1; n++) {
                if (i < 0) temp.push_back(triangle[m-1][j]);
                else if (j >= m) temp.push_back(triangle[m-1][i]);
                else temp.push_back(triangle[m-1][i] + triangle[m-1][j]);
                i++;
                j++;
            }
            triangle.push_back(temp);
            temp.clear();
        }
        return triangle;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> t1 = sol.generate(10);
    cout << endl << endl;
    for (int i = 0; i < t1.size(); i++) {
        for (int j = 0; j < t1[i].size(); j++) {
            cout << t1[i][j] << " ";
        } cout << endl;
    }
    return 0;
}