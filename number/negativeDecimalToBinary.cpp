#include <iostream>
#include <cmath>

using namespace std;

class Solution {
  public:
  // This implementation can handle both +ve and -ve numbers
  void negativeDecimalToBinary(int n) {
    int size = sizeof(n) * 8;

    cout << n << endl;

    while (size) {
      int r = (n >> size-1) & 1;
      cout << r;
      size--;
    }
  }
};

int main() {
  Solution sol;
  sol.negativeDecimalToBinary(-10);

  return 0;
}