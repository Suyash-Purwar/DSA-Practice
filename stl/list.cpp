#include <iostream>
#include <list>

using namespace std;

/**
 * List is like doubly linked list
 * Any random element can't be accessed like list[2];
 * List has to be traversed a specific element
 */

void printList(list<int> l) {
	for (int i: l) {
		cout << i << " ";
	} cout << endl;
}

int main() {
	list<int> l1 = {5, 3, 2};
	printList(l1);

	l1.push_back(8);
	l1.push_front(1);
	l1.push_front(0);
	l1.pop_front();

	printList(l1);

	cout << l1.empty() << endl;

	l1.push_back(6);
	l1.push_front(4);

	printList(l1);
}