/**
 * @file 448. Find All Numbers Disappeared in an Array (Leetcode Easy)
 * @brief Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
 * @link https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 09-07-2023
*/  

#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::cout;
using std::endl;
using std::abs;

class Solution {
  public:

  // TC: O(2n)
  // SC: O(n)
  vector<int> findDisappearedNumbers1(vector<int>& nums) {
    vector<int> hash(nums.size(), 0);
    vector<int> ans;

    for (int i: nums) hash[i-1] = 1;
    for (int j = 0; j < nums.size(); j++) {
      if (hash[j] == 0) ans.push_back(j+1);
    }

    return ans;
  }

  // TC: O(2n)
  // SC: O(1)
  vector<int> findDisappearedNumbers2(vector<int>& nums) {
    vector<int> ans;
    for (int i: nums) if (nums[abs(i)-1] > 0) nums[abs(i)-1] *= -1;

    for (int j = 0; j < nums.size(); j++) {
      if (nums[j] > 0) ans.push_back(j+1);
    }

    return ans;
  }
};

int main() {
  Solution sol;

  vector<int> i1 = {2, 1, 1, 4, 4};

  vector<int> o1 = sol.findDisappearedNumbers2(i1);

  for (int n: o1) cout << n << endl;

  return 0;
}