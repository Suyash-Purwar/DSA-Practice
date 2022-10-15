#include<iostream>
#include<stack>

using std::cout;
using std::endl;
using std::stack;

int main() {
    stack<int> stack1;
    stack1.push(23);
    stack1.push(82);
    stack1.push(59);

    cout << "Element at top before deletion: " << stack1.top() << endl;
    stack1.pop();
    cout << "Element at top after deletion: " << stack1.top() << endl;
    cout << stack1.size() << endl;

    if (stack1.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }
    
    stack1.push(100);

    cout << "Size of the stack is: " << stack1.size() << endl;

    stack<int> stack2;
    stack2.push(1);
    stack1.swap(stack2); // Contents of the two stacks are swapped

    cout << stack1.size() << endl;
    cout << stack2.size() << endl;

    cout << stack1.size() << endl;
    cout << stack1.top() << endl;
    stack1.pop();
    cout << stack1.top() << endl;
    return 0;
}