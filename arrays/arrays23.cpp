/**
 * @file Rotate Array (Leetcode Medium)
 * @link https://leetcode.com/problems/rotate-array
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 19-01-2023
*/

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      vector<int> temp(nums.size());
      for (int i = 0; i < nums.size(); i++) {
        temp[(i+k)%nums.size()] = nums[i];
      }
      nums = temp;
    }
};

int main() {
  vector<int> a0 = {1, 2, 3, 4, 5, 6, 7};
  Solution sol;
  sol.rotate(a0, 10);

  return 0;
}