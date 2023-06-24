#include <iostream>
#include <deque>

using namespace std;

void printDeque(deque<int>& d) {
	for (int i: d) {
		cout << i << " ";
	} cout << endl;
}

/**
 * Dequeue is made of doubly ended queue
 * One can insert and remove elements from both ends
 */

int main() {
	deque<int> d1 = {4, 6, 2}; // Size is 3

	// Copying the values of d1 into d2;
	deque<int> d2(d1);
	cout << "Contents of d2: ";
	printDeque(d2);

	d1.push_front(0);
	d1.push_front(390);
	d1.pop_back();

	cout << "Contents of d1: ";
	printDeque(d1); // 390, 0, 4, 6

	d1.pop_front();
	d1.push_back(30);

	cout << "Contents of d1: ";
	printDeque(d1); // 0, 4, 6, 30

	// Is empty or not
	cout << d1.empty() << endl;

	d1.push_front(67);
	d1.push_back(55);
	d1.push_back(60);
	d1.push_front(89);

	// Erasing any arbitrary part of deque
	// d1.begin() returns iterator pointing to the first element
	// d1.end() returns iterator pointing to the last element

	printDeque(d1);
	d1.erase(d1.end() - 2, d1.end()); // Removes the last two elements of the array
	printDeque(d1);

	d1.erase(d1.end()-2); // Removes the second last element
	printDeque(d1);

	d1.erase(d1.begin() + 1, d1.begin() + 4); // Removes the element at index 1, 2, and 3
	printDeque(d1);

	// Note that d1.erase(d1.end()) and d1.erase(d1.end() - 1) both remove the last element only

	// Clearing the deque
	d1.clear();
	cout << "Size of Deque: " << d1.size() << endl; // 0
}