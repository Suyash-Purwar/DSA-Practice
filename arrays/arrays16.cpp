#include<iostream>

using std::cout;
using std::endl;

void swapAdjacentValues(int *nums, int size) {
    int temp;
    for (int i = 0; i < size; i+=2) {
        if (i+1 < size) {
            temp = nums[i];
            nums[i] = nums[i+1];
            nums[i+1] = temp;
        }
    }
}

int main() {
    const int size = 5;
    int array[size] = {4, 9, 3, 6, 1};
    swapAdjacentValues(array, size);

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}