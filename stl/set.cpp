#include <iostream>
#include <set>

// Elements are retrieved in an ordered manner
// All elements are unique
// Pushing duplicate values wouldn't result in elements being duplicate.
// Attempts to do so will be ignored
// Ordered Set are implemented through BST

// In Unordered Set, the elements are retrieved in a random order
// Slower than Ordered Set

using namespace std;

void printSet(set<int> s) {
  for (int i: s) {
    cout << i << " ";
  } cout << endl;
}

int main() {
  set<int> s;

  // Time complexity of insert operation is O(n)
  s.insert(94);
  s.insert(8);
  s.insert(8); // Duplicate element is ignored
  s.insert(7);

  printSet(s);

  cout << s.size() << endl;

  // s.begin()+2 wouldn't work. Increment it twice
  s.erase(++s.begin());
  printSet(s);

  // Tells if there exists the element
  cout << s.count(5) << endl;
  cout << s.count(7) << endl;

  s.insert(0);
  s.insert(40);
  printSet(s);

  // Returns the iterator if element is found
  set<int>::iterator it = s.find(40);
  cout << *it << endl;
  cout << *(++it) << endl;

  // NOTE: insert, find, erase, count have time complexity of O(n)
  // NOTE: being, end, size, empty have time complexity of O(1)
  return 0;
}