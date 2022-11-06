#include<iostream>

using std::cout;
using std::cin;
using std::endl;

// Worst and best case time complexity of selection-sort is same O(n^2)

void selectionSort(int *nums, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minValueIndex = i;
        for (int j = i+1; j < size; j++) {
            if (nums[minValueIndex] > nums[j]) minValueIndex = j;
        }
        int temp = nums[i];
        nums[i] = nums[minValueIndex];
        nums[minValueIndex] = temp;
    }
}

int main() {
    int const size = 6;
    int array[size] = {3, 2, -4, 12, -12, 0};  

    selectionSort(array, size);

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}