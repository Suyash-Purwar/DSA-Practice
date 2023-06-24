#include <iostream>
#include <queue>

using namespace std;

int main() {
  // Direct access in any of the queues or stacks is not possible

  // By default, priority queue is based on max heap.
  // Always the maximum element will be fetched
  priority_queue<int> maxi;

  maxi.push(1);
  maxi.push(3);
  maxi.push(8);
  maxi.push(0);

  while (maxi.size()) {
    cout << maxi.top() << " ";
    maxi.pop();
  } cout << endl;

  cout << maxi.empty() << endl;

  // Priority queue based on min heap
  priority_queue<int, vector<int>, greater<int>> mini;

  mini.push(20);
  mini.push(1);
  mini.push(41);
  mini.push(9);

  while (mini.size()) {
    cout << mini.top() << " ";
    mini.pop();
  } cout << endl;

  cout << mini.empty() << endl;
}