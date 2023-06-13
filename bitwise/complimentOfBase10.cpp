/**
 * @name 1009. Complement of Base 10 Integer (Easy)
 * @brief The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation. For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2. Given an integer n, return its complement.
 * @link https://leetcode.com/problems/complement-of-base-10-integer/
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 14-06-23
 */

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
  public:

  // First Implementation (Not good)
  int bitwiseComplement1(int n) {
    int size = sizeof(n) * 8; int ans = 0; bool isZeroAfterOne = 0;
    while(size) {
      int bit = (n >> (size - 1)) & 1;
      if (bit != 0 || isZeroAfterOne == true) {
        isZeroAfterOne = true;
        ans += pow(2, size-1) * !bit;
      }
      size--;
    }
    return ans;
  }

  // Second Implementation (Good)
  int bitwiseComplement2(int n) {
    int ans = 0; int i = 0; int size = 32;
    while (n != 0) {
      int bit = n & 1;
      ans += pow(2, i++) * !bit;
      n = n >> 1;
      if (!size) break;
      size--;
    };

    return ans;
  }

  // Third implementation (Best)
  int bitwiseComplement3(int n) {
    int m = n;
    int mask = 0;
    if (!n) return 1;
    while (m != 0) {
      mask = (mask << 1) | 1;
      m = m >> 1;
    }
    int ans = (~n) & mask;
    return ans;
  }
};

int main() {
  Solution sol;
  cout << sol.bitwiseComplement1(-5) << endl;

  cout << sol.bitwiseComplement2(5) << endl;

  cout << sol.bitwiseComplement3(5) << endl;

  return 0;
}