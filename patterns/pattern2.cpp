#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}