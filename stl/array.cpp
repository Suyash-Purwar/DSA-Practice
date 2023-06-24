#include <iostream>
#include <array>

using namespace std;

int main() {
	// Static fixed-size array
	int a1[4] = {4, 2, 1, 9};

	// Also, static fixed-size array
	// Made from the above array implementation only
	// Since it's fixed-size array like the normal one above, it's not used much
	array<int, 4> a2 = {8, 3, 0, 1};

	cout << "Size of the array: " << a2.size() << endl;
	cout << "Front of the array: " << a2.front() << endl;
	cout << "Back of the array: " << a2.back() << endl;
	cout << "Element at 2nd position: " << a2.at(1) << endl;

	for (int i = 0; i < a2.size(); i++) {
		cout << a2[i] << " ";
	} cout << endl;
}