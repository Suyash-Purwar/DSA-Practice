#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::min;
using std::vector;

class Solution {
    public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int sum = triangle[0][0];
        int index = 0;
        for (int i = 1; i < triangle.size(); i++) {
            sum += min(triangle[i][index], triangle[i][index+1]);
            index = triangle[i][index] < triangle[i][index+1] ? index : index+1;
        }
        return sum;
    }
};

int main() {
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    // vector<vector<int>> triangle = {
    //     {-2}
    // };

    Solution sol;
    cout << "Soution: " << sol.minimumTotal(triangle) << endl;
    return 0;
}