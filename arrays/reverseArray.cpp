#include <iostream>

using namespace std;

void reverseArray(int arr[], int size) {
	for (int i = 0, j = size - 1; i < size/2; i++, j--) {
		swap(arr[i], arr[j]);
	}
}

int main() {
	int array1[] = {4, 2, 7, 0, 1, 9, 5};
	int array2[] = {1, 2, 3, 4, 5, 6};

	reverseArray(array1, 7);
	reverseArray(array2, 6);

	for(auto i: array1) cout << i << " ";
	cout << endl;

	for(auto j: array2) cout << j << " ";
	cout << endl;

	return 0;
}