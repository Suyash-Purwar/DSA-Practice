#include <iostream>
#include <cmath>

using namespace std;

class Solution {
  public:

  int binaryToDecimal(long b) {
    int i = 0; int decimal = 0;
    while (b != 0) {
      int digit = b % 10;
      decimal += pow(2, i) * digit;
      b = b / 10;
      i++;
    }

    return decimal;
  }
};

int main() {
  Solution sol;
  cout << sol.binaryToDecimal(111111111);
  
  return 0;
}