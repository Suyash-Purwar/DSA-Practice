#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<int> v = {5, 9, 3, 1, -2};

  // Sorting the array
  sort(v.begin(), v.end());

  // Performing binary search on this
  cout << binary_search(v.begin(), v.end(), 6) << endl;
  cout << binary_search(v.begin(), v.end(), 9) << endl;

  // Swapping the values of two variables
  float a = 3.10;
  float b = 8.32;
  swap(a, b);

  cout << a << endl;
  cout << b << endl;

  // Reversing the string
  string s1 = "suyash";
  reverse(s1.begin(), s1.end());
  cout << s1 << endl;

  // Finding lower bound and upper bound
  // Lower Bound: This function returns an iterator pointing to the first element in the range that is not less than a specified value. It performs a binary search and finds the position where the element would be inserted in order to maintain the sorted order. If the specified value is found in the range, lower_bound() returns an iterator pointing to that element. If the value is not present, it returns an iterator pointing to the first element that is greater than the specified value.
  // Upper Bound: Similar to lower_bound(), this function returns an iterator pointing to the first element in the range that is greater than a specified value. It finds the position where the element would be inserted to maintain the sorted order. If the specified value is found in the range, upper_bound() returns an iterator pointing to the first element that is greater than the specified value. If the value is not present, it returns an iterator pointing to the first element that is greater than the specified value.
  // For these functions to work the elements must be ordered
  vector<int> v1 = {1, 2, 3, 3, 4, 4, 6, 7};

  auto lower = lower_bound(v1.begin(), v1.end(), 4);
  auto upper = upper_bound(v1.begin(), v1.end(), 4);

  cout << *lower << endl;
  cout << *upper << endl;

  rotate(v1.begin(), v1.begin()+2, v1.end());
  for (int i: v1) {
    cout << i << " ";
  } cout << endl;
  return 0;
}