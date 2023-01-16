/**
 * @file Majority Element (Leetcode Easy)
 * @brief Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
 * @link https://leetcode.com/problems/majority-element/description/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 16-01-2023
*/

#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;
using std::floor;

// Witihout using Hashmap (Not efficient)
// Solution wtih hashmap will be covered soon
class Solution {
  public:
  int majorityElement(vector<int>& nums) {
    vector<vector<int>> kv_store;
    vector<int> temp;
    bool isPresent = false;
    int res = -1;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < kv_store.size(); j++) {
        if (kv_store[j][0] == nums[i]) {
          isPresent = true;
          kv_store[j][1]++;
        }
      }

      if (!isPresent) {
        temp.insert(temp.end(), {nums[i], 1});
        kv_store.push_back(temp);
        temp.clear();
      }
      isPresent = false;

      for (auto pair: kv_store) {
        if (pair[1] > floor(nums.size()/2)) {
          res = pair[0];
          return res;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  vector<int> a1 = {1, 1, 2, 2, 2, 2, 1};
  vector<int> a2 = {3, 2, 3, 2};
  vector<int> a3 = {1};
  cout << sol.majorityElement(a3) << endl;
  return 0;
}