/**
 * @name 231. Power of Two
 * @brief Given an integer n, return true if it is a power of two. Otherwise, return false. An integer n is a power of two, if there exists an integer x such that n == 2x.
 * @link https://leetcode.com/problems/power-of-two
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 14-06-23
 */

#include <iostream>
#include <climits>

using namespace std;

class Solution {
  public:

  // Implementation 1
  bool isPowerOfTwo1(int n) {
    int times = 1; bool ans = false;
    if (n <= 0) return ans;
    while (n != 0) {
      n = n >> 1;
      if (n % 2 != 0) return false;
      if (n == 2) {
        return true;
      }
    }
    return ans;
  }

  // Implementation 2 (Best implementation)
  bool isPowerOfTwo2(int n) {
  	int value = 1;
  	for (int i = 0; i < 31; i++) {
  		if (value == n) return true;
  		if (value < INT_MAX/2) value *= 2;
   	}
  	return false;
  }
};

int main() {
  Solution sol;
  cout << sol.isPowerOfTwo1(2048) << endl;

  cout << sol.isPowerOfTwo2(1073741824) << endl;

  return 0;
}