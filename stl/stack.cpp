#include<iostream>
#include<stack>

using namespace std;

void printElement(stack<string>& s) {
  cout << "Top Element: " << s.top() << endl;
}

// Last in first out
int main() {
  stack<string> s1;

  s1.push("suyash");
  s1.push("purwar");

  printElement(s1);

  cout << s1.size() << endl;
  cout << s1.empty() << endl;

  return 0;
}