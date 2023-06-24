#include <iostream>
#include <vector>
#include <deque>

using std::cout;
using std::endl;
using std::vector;
using std::deque;

int main() {
	vector<int> v1 = {4, 2, 6, 7, 23, -9, 0, 1, 3};
	vector<int>::iterator v1_iter = v1.begin();

	while (v1_iter != v1.end()) {
		cout << *v1_iter << " ";
		v1_iter++;
	} cout << endl;

	deque<int> d1 = {7, 3, 0, 1};
	deque<int>::iterator d1_iter = d1.begin();

	while (d1_iter != d1.end()) {
		cout << *d1_iter << " ";
		d1_iter++;
	} cout << endl;

	return 0;
}