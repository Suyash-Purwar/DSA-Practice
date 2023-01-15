/**
 * @file Plus One (Leetcode Easy)
 * @brief You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
 * @link https://leetcode.com/problems/plus-one/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 15-01-2023
*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
  public:
  vector<int> plusOne(vector<int>& array) {
    short int add = 1;
    short int i = array.size() - 1;
    do {
      if (array[i] + add == 10) {
        array[i] = 0;
        if (i == 0) {
          array.insert(array.begin(), 1);
          add = 0;
        }
        i--;
      } else {
        array[i] += 1;
        add = 0;
      }
    } while (add != 0);

  return array;
  }
};

int main() {
  Solution sol;
  
  vector<int> a0 = {3, 4};
  vector<int> a1 = {9, 9};
  vector<int> a2 = {34, 23, 9};
  vector<int> a3 = {9, 9};

  vector<int> res = sol.plusOne(a1);

  for (auto e: res) {
    cout << e << " ";
  }

  return 0;
}