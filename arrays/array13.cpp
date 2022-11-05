// Make a program to reverse an array with a complexity of O(n)

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

void reverseArray(int *arr, int size) {
    int temp;
    for (int i = 0, j = size - 1; i < size/2; i++, j--) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    const int size = 6;
    int arr[size] = {3, 2, -2, 12, 3, 1};
    reverseArray(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    } cout << endl;
    return 0;
}