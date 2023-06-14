/**
 * @name 7. Reverse Integer (Medium)
 * @brief Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
 * @link https://leetcode.com/problems/reverse-integer
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 14-06-23
 */

#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
  public:
  int reverseInteger(int num) {
    int ans = 0;
    while(num != 0) {
      int digit = num % 10;
      if (ans > INT_MAX/10 || ans < INT_MIN/10) return 0;
      ans = (ans * 10) + digit;
      num /= 10;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  cout << sol.reverseInteger(1234567899);

  return 0;
}