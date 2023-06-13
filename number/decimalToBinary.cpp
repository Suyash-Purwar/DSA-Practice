#include <iostream>
#include <cmath>

// Only handles +ve numbers
// Checkout negativeDecimalToBinary to see how both +ve and -ve be supported

using namespace std;

class Solution {
  public:

  // First Implementation
  void decimalToBinary1(int n) {
    int i = 0, ans = 0;
    do {
      int r = n % 2;
      n /= 2;
      ans += pow(10, i++) * r;
    } while (n != 0);
    cout << ans << endl;
  }

  // Second implementation
  void decimalToBinary2(int n) {
    int i = 0, ans = 0;
    while (n != 0) {
      int r = n & 1;
      n = n >> 1;
      ans += pow(10, i++) * r;
    }
    cout << ans << endl;
  }
};

int main() {
  Solution sol;
  sol.decimalToBinary1(10);
  sol.decimalToBinary2(4);

  return 0;
}