#include <iostream>
#include <cmath>

using namespace std;

class Solution {
  public:
  void negativeDecimalToBinary(int n) {
    int size = 32;

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