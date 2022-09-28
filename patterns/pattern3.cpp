#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    for (; n > 0; n--) {
        for (int j = 0; j < n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}