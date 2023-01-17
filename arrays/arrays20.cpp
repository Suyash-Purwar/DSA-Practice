/**
 * @file Difference Between Element Sum and Digit Sum of an Array (Leetcode Easy)
 * @link https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 17-01-2023
*/

#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;
using std::abs;
using std::floor;

class Solution {
  public:
  int differenceOfSum(vector<int>& nums) {
    int element_sum = 0;
    int digit_sum = 0;

    for (int i = 0; i < nums.size(); i++) {
      element_sum += nums[i];
      int num = nums[i];
      while (num != 0) {
        digit_sum += num % 10;
        num = floor(num / 10);
      }
    }

    return abs(element_sum - digit_sum);
  }
};

int main() {
  Solution sol;
  vector<int> a1 = {6, 15, 1, 3};
  cout << sol.differenceOfSum(a1) << endl;
  return 0;
}