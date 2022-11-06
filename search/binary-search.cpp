#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int binarySearch(int *nums, int size, int target) {
    int mid;
    int start = 0; 
    int end = size-1;

    while(start <= end) {
        mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    const int size = 7;
    int nums[size] = {3, 9, 12, 31, 32, 45, 100};
    
    cout << "Element " << 3 << " is found at index: " << binarySearch(nums, size, 3) << endl;
    cout << "Element " << 9 << " is found at index: " << binarySearch(nums, size, 9) << endl;
    cout << "Element " << 32 << " is found at index: " << binarySearch(nums, size, 32) << endl;
    cout << "Element " << 100 << " is found at index: " << binarySearch(nums, size, 100) << endl;
    cout << "Element " << 10 << " is found at index: " << binarySearch(nums, size, 10) << endl;

    return 0;
}