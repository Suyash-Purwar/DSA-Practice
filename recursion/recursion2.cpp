#include<iostream>

using std::endl;
using std::cout;

void printName(int times) {
    if (times == 0) {
        cout << endl;
        return;
    };
    cout << "Suyash" << " ";
    printName(times - 1);
}

// Uses global variables
// How to get rid of these global variables
int i = 1;
void print1toN(int n) {
    if (i == n + 1) {
        cout << endl;
        return;
    }
    cout << i << " ";
    i++;
    print1toN(n);
}

// Without using gloval variables
void print1toN_better(int n, int i = 1) {
    if (i == n + 1) {
        cout << endl;
        return;
    }
    cout << i << " ";
    print1toN_better(n, ++i);
}

void printNto1(int n) {
    if (n == 0) {
        cout << endl;
        return;
    }
    cout << n << " ";
    printNto1(--n);
}

void print1toN_backtracking(int n) {
    if (n <= 0) return;
    print1toN_backtracking(n-1);
    cout << n << " ";
}

void printNto1_backtracking(int n, int i = 1) {
    if (i > n) return;
    printNto1_backtracking(n, i+1);
    cout << i << " ";
}

int main() {
    printName(4);
    print1toN(10);
    printNto1(10);

    print1toN_better(8);

    print1toN_backtracking(5);
    cout << endl;

    printNto1_backtracking(9);
    cout << endl;
    return 0;
}