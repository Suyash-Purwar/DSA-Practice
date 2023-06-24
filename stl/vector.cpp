#include<iostream>
#include<vector>

using namespace std;

/**
 * Vector is a dynamic sized array. Whenever an vector reaches it's capacity, it's size is doubled.
 * It does so by creating a new array of double the size of actual array and copying the original items into it.
 * It deletes the previous smaller array
 */

void printSizeAndCapacity(vector<int>& v) {
	cout << "Size: " << v.size() << endl; // Shows the number of items in the array
	cout << "Capacity: " << v.capacity() << endl; // Shows the number of items that can be present in the array	
}

void printArray(vector<int>& v) {
	for (int i: v) {
		cout << i << " ";
	} cout << endl;
}

int main() {
	vector<int> v1;
	printSizeAndCapacity(v1); // 0, 0

	v1.push_back(10);
	printSizeAndCapacity(v1); // 1, 1 <-- 2^0 can hold 1 elememnt, so capacity is 1

	v1.push_back(23);
	printSizeAndCapacity(v1); // 2, 2 <-- 2^0 can't hold 2 elements, so capacity is 2^1

	v1.push_back(67);
	printSizeAndCapacity(v1); // 3, 4 <-- 2^1 can't hold 3 elements, so capacity is 2^2

	v1.push_back(565);
	printSizeAndCapacity(v1); // 4, 4 <-- 2^4 can hold 4 elements, so capacity is 2^2 only

	v1.push_back(78);
	printSizeAndCapacity(v1); // 5, 8 <-- 2^4 can't hold 5 elements, so capacity is 2^3

	// Initializing the vector with length 3
	vector<int> v2(3);
	printSizeAndCapacity(v2); // 3, 3

	// By default, all the elements of v2 are assigned 0
	cout << "Contents of v2: ";
	printArray(v2); // 0 0 0

	v2.push_back(4); // Pushing the new elements increases the size by 1 and capacity by times 2
	printSizeAndCapacity(v2); // 3, 6

	// Initial size = 5
	// By default all elements are assigned 4
	vector<int> v3(5, 4);
	cout << "Contents of v3: ";
	printArray(v3); // 4 4 4 4 4

	cout << "Front element of v1: " << v1.front() << endl;
	cout << "Last element of v1: " << v1.back() << endl;

	cout << "Contents of v1: ";
	printArray(v1);

	v1.pop_back(); // Last element is removed

	cout << "Contents of v1: ";
	printArray(v1);

	// Copying the elements of v1 into v4
	vector<int> v4(v1);
	cout << "Contents of v4: ";
	printArray(v4);

	// Clearing the vector
	v4.clear(); // All elements are gone
	cout << "Contents of v4: ";
	printArray(v4); // Nothing is printed
	printSizeAndCapacity(v4); // 0, 4 <-- Size = 0, Capacity = 4
	// NOTE: v4.clear() doesn't deallocate the memory space allocated to v4
}