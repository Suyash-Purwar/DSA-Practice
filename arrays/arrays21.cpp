/**
 * @file Difference Between Element Sum and Digit Sum of an Array (Leetcode Easy)
 * @link https://leetcode.com/problems/summary-ranges/  
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 19-01-2023
*/

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;

class Solution {
  public:
  vector<string> summaryRanges(vector<int> &arr) {
    int start; int size = arr.size();
    vector<string> res;
    if (size != 0) start = arr[0];
    if (size == 1) {
      res.push_back(to_string(arr[0]));
      return res;
    }

    for (int i = 1; i < size; i++) {
      if (arr[i] != arr[i - 1] + 1) {
        res.push_back(
          start != arr[i - 1] ? to_string(start) + "->" + to_string(arr[i - 1]) : to_string(arr[i - 1])
        );
        start = arr[i];
        if (i == size - 1) res.push_back(to_string(start));
      } else if (i == size - 1) {
        res.push_back(to_string(start) + "->" + to_string(arr[i]));
      }
    }

    return res;
  }
};

int main() {
  vector<int> a0 = {0, 1, 2, 4, 5, 7};
  Solution sol;
  vector<string> res = sol.summaryRanges(a0);
  for (auto e: res) {
    cout << e << " ";
  }
  return 0;
}