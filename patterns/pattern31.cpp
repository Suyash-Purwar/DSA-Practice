#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n, n_copy;
    cout << "Enter the number: ";
    cin >> n;
    n_copy = n;
    for (int i = 0; i < 2*n-1; i++) {
        for (int j = 0; j < 2*n-1; j++) {
            if (n-j >= n_copy) cout << n-j;
            else if (j-n+1>=n_copy) cout << j-n+2;
            else cout << n_copy;
            cout << " ";
        }
        n-1 > i ? n_copy-- : n_copy++;
        cout << endl;
    }

    return 0;
}