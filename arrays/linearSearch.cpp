#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int target) {
	int ans = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] == target) return !ans;
	}

	return ans;
}

int main() {
	int arr[] = {3, 5, 1, -3, 5, -9, 0, 2};
	cout << linearSearch(arr, 8, 10) << endl;
}