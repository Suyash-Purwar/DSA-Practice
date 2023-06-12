/**
 * @name 1281. Subtract the Product and Sum of Digits of an Integer (Leetcode Easy)
 * @brief Given an integer number n, return the difference between the product of its digits and the sum of its digits.
 * @link https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer
 * @author Suyash Purwar (github.com/suyash-purwar)
 * @date 12-06-23
 */


#include <iostream>

using namespace std;

class Solution {
  public:

  int subtractProductAndSum(int n) {
    if (!n) return 0;
    int sum = 0, product = 1;
    while (n != 0) {
      sum += n % 10;
      product *= n % 10;
      n /= 10;
    }
    return product - sum;
  }
};

int main() {
  Solution sol;
  int ans = sol.subtractProductAndSum(0);

  cout << ans;

  return 0;
}