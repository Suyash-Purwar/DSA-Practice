#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n;
    cout << "Enter the odd number: ";
    cin >> n;

    if (n%2 == 0) {
        cout << "Enter odd number only";
        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        if (i <= (n+1)/2) {
            for (int j = 1; j <= i; j++) {
                cout << "* ";
            }
        } else {
            for (int j = n - i; j >= 0; j--) {
                cout << "* ";
            }
        }
        cout << endl;
    }

    return 0;
}