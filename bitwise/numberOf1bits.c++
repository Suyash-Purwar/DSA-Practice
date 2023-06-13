/**
 * @name 191. Number of 1 Bits
 * @brief Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
 * @link https://leetcode.com/problems/number-of-1-bits/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 12-06-23
 */

#include <iostream>

using namespace std;

class Solution {
  public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
      if (n&1) {
        count++;
      }
      n = n >> 1;
    }
    return count;
  }
};

int main() {
  Solution sol;
  cout << sol.hammingWeight(2);  

  return 0;
}