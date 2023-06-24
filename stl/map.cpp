#include <iostream>
#include <map>

using namespace std;

// Map can hold only unique keys
// Each key can point to one value only

// Keys are sorted out in the case of ordered map.
// By default maps are sorted
// Retrieval will be in sorted manner

// In the case of unordered map, keys are stored and retrieved in random fashion

void printMap(map<int, string> m) {
  for (auto i: m) {
    cout << i.first << " " << i.second << endl;
  }
}

// NOTE: In ordered map: insert, erase, find, access, and count have a time complexity of O(logn)
// NOTE: In unordered map: time complexity of access is O(1)
int main() {
  map<int, string> m;
  m[1] = "suyash";
  m[93] = "codes";
  m[2] = "purwar";

  // another way of inserting
  m.insert({ 8, "rashi" });

  cout << m[1] << endl;

  printMap(m);

  // count() tells if the key is present
  cout << m.count(93) << endl;
  cout << m.count(8) << endl;

  // Removes key-val pair
  m.erase(93);
  printMap(m);

  // Find returns the iterator if the key value pair is present
  auto it = m.find(1);
  // Iterating through an iterator
  for (auto i = it; i != m.end(); i++) {
    cout << (*i).first << endl;
  }
  return 0;
}