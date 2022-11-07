#include<iostream>

using std::cout;
using std::cin;
using std::endl;

// Make a program to find min and max in an array

void minmaxOfArr(int *nums, int size) {
    int minValueIndex = 0;
    int maxValueIndex = 0;

    for (int i = 1; i < size; i++) {
        // finding min value
        if (nums[minValueIndex] > nums[i]) minValueIndex = i;
        // finding max value
        if (nums[maxValueIndex] < nums[i]) maxValueIndex = i;
    }

    cout << "Max Value: " << nums[maxValueIndex] << endl;
    cout << "Min Value: " << nums[minValueIndex] << endl;
}


int main() {
    int const size = 8;
    int array[size] = {-4, 2, 1, 43, -34, 9, 90, 5};

    minmaxOfArr(array, size);

    return 0;
}