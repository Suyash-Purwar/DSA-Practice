#include <iostream>
#include <queue>

using namespace std;

void printFrontElement(queue<string>& q) {
  cout << "Queue's First Element: " << q.front() << endl;
}

// First in first out
// Complexity of all the operations below is O(1)
// Can not be accessed directly like q1[0]
int main() {
  queue<string> q1;

  q1.push("suyash");
  q1.push("sangeeta");
  q1.push("purwar");

  printFrontElement(q1);  

  q1.pop();

  printFrontElement(q1);

  cout << q1.size() << endl;

  cout << q1.empty() << endl;

  return 0;
}