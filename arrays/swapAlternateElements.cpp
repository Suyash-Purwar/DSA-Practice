#include <iostream>

using namespace std;

void swapAltrenateElements(int arr[], int size) {
	if (size % 2 != 0) size--;
	for (int i = 0; i < size; i+=2) {
		swap(arr[i], arr[i+1]);
	}
}

int main() {
	int array1[] = {1, 6, 9, 2, 0};
	int array2[] = {8, 3, 7, 0};

	swapAltrenateElements(array1, 5);
	swapAltrenateElements(array2, 4);

	for (auto i: array1) cout << i << " ";
	cout << endl;

	for (auto i: array2) cout << i << " ";
	cout << endl;

	return 0;
}