#include <iostream>

using namespace std;

void printTheArray(int arr[]) {
	int size = sizeof(arr) / 4;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int a[5] = {};
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << *a << endl;

	int arr[3] = {4, 2, 87};
	printTheArray(arr);

	return 0;
}