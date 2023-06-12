#include <iostream>

using namespace std;

int main() {
  cout << "Enter the number: " << endl;
  int n;
  cin >> n;

  int isPrime = 1;

  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      isPrime = 0;
      break;
    }
  }

  cout << (isPrime ? "Prime" : "Not Prime");
  
  return 0;
}