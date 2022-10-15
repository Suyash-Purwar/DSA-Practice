#include<iostream>

using std::cout;
using std::endl;

class Stack {
    int top = -1;
    int *stack;
    int size_of_stack;

    public:
    Stack(int size) {
        this -> size_of_stack = size;
        this -> stack = new int[size];
    }

    void push(int element) {
        if (top < size_of_stack-1) {
            stack[++top] = element;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
        } else {
            delete &stack[top];
            top--;
        }
    }

    int peek() {
        if (top >= 0) {
            return stack[top];
        } else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }

    int size() {
        return top+1;
    }

    int empty() {
        return top == -1;
    }
};

int main() {
    Stack *st = new Stack(5);
    st -> push(12);
    cout << st -> peek() << endl;
    cout << st -> size() << endl;
    cout << st -> empty() << endl;

    st -> pop();
    st -> pop();

    cout << st -> peek() << endl;
    cout << st -> size() << endl;

    st -> push(8);
    st -> push(2);
    st -> push(9);
    st -> push(3);
    st -> push(15);
    st -> push(12);

    cout << st -> size() << endl;
    cout << st -> peek() << endl;

    return 0;
}