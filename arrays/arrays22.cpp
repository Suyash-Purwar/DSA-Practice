/**
 * @file Intersection (Leetcode Easy)
 * @link https://leetcode.com/problems/intersection-of-two-arrays/ 
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 19-01-2023
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
  public:
  vector<int> intersection(vector<int> nums1, vector<int> nums2) {
    vector<int> res;
    
    if (nums1.size() == 0 || nums2.size() == 0) return !nums1.size() ? nums2 : nums1;
    
    for (int i = 0; i <  nums1.size(); i++) {
      for (int j = 0; j < nums2.size(); j++) {
        if (nums1[i] == nums2[j]) {
          if (res.size() != 0) {
            bool isPresent = false;
            for (int k = 0; k < res.size(); k++) {
              if (nums1[i] == res[k]) {
                isPresent = true;
                break;
              }
            }
            if (!isPresent) res.push_back(nums1[i]);
          } else {
            res.push_back(nums1[i]);
          }
          break;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  vector<int> a1 = {1, 3, 2, 2, 1};
  vector<int> a2 = {1, 3, 1, 2};

  vector<int> res = sol.intersection(a1, a2);

  for(auto num: res) {
    cout << num << " ";
  }
}