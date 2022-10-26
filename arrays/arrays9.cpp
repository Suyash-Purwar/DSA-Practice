#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
    public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle = {{1}};
        vector<int> temp;

        for (int m = 1; m < rowIndex+1; m++) {
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
        return triangle[rowIndex];
    }
};

int main() {
    Solution sol;
    vector<int> r1 = sol.getRow(0);
    for (int i = 0; i < r1.size(); i++) {
        cout << r1[i] << " ";
    }
    cout << endl;
    return 0;
}