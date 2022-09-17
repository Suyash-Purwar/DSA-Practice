#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}