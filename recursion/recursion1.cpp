#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int factorial(int n) {
    return !n ? 1 : n * factorial(n-1);
}

// Head Recursion
void printNumbersInForward(int n) {
    if (n <= 0) return;
    printNumbersInForward(n-1);
    cout << n << " ";
}

// Tail Recursion
void printNumbersInBackward(int n) {
    if (n <= 0) return;
    cout << n << " ";
    printNumbersInBackward(n-1);
}

int powerOfTwo(int n) {
    if (!n) {
        return 1;
    }
    return 2 * powerOfTwo(n-1);
}

// Head Recursion
bool isArraySorted(int *arr, int size, int index = 0) {
    if (index == size - 1) return true;

    bool recursionResult = isArraySorted(arr, size, index+1);
    bool ans = recursionResult && (arr[index] <= arr[index+1]);

    return ans;
}

int main() {
    int sol = factorial(5);
    cout << sol << endl;

    printNumbersInForward(10);
    cout << endl;
    printNumbersInBackward(10);
    cout << endl;

    cout << powerOfTwo(3) << endl;

    int unsorted[5] = {3, 1, 2, 5, 3};
    int sorted[5] = {1, 2, 3, 3, 5};

    cout << isArraySorted(unsorted, 5) << endl;
    cout << isArraySorted(sorted, 5) << endl;

    return 0;
}