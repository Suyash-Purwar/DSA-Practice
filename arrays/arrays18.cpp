/**
 * @file Search Insert Position (Leetcode Easy)
 * @brief Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * @link https://leetcode.com/problems/search-insert-position/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 15-01-2023
*/

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Solution {
  public:
  int searchInsert(vector<int>& nums, int target) {
    int size = nums.size();
    int res;
    for (int i = 0; i < size; i++) {
      if (nums[i] >= target) {
        cout << i << " " << "\n";
        res = i;
        break;
      } else if (i == size - 1) {
        res = i + 1;
      }
    }
    return res;
  }
};

int main() {
  vector<int> a1 = {1, 3, 5, 6};

  Solution sol;
  cout << sol.searchInsert(a1, 5);
  return 0;
}