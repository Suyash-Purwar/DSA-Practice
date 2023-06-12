#include <iostream>

using namespace std;

int main() {
  cout << "Enter the number: " << endl;
  int n;
  cin >> n;

  int a = 0;
  int b = 1;

  for (int i = 0; i < n; i++) {
    if (i == 0 || i == 1) {
      cout << i << endl;
      continue;
    }
    int temp = a + b;
    a = b;
    b = temp;
    cout << b << endl;
  }

  return 0;
}