#include<iostream>

using std::cout;
using std::endl;

class Node {
    public:
    int data;
    Node *next;

    Node(int data, Node* next) {
        this -> data = data;
        this -> next = next;
    }
};

class Stack {
    int size_of_stack = 0;
    public:
    Node *top = NULL;
    Node *bottom = NULL;

    void push(int element) {
        Node *new_node = new Node(element, NULL);
        if (top) {
            top -> next = new_node;
        } else {
            bottom = new_node;
        }
        top = new_node;
        size_of_stack++;
    }

    void pop() {
        if (top) {
            if (top == bottom) {
                delete top;
                size_of_stack--;
                top = bottom = NULL;
                return;
            }
            Node *temp = bottom;
            while (temp -> next != top) {
                temp = temp -> next;
            }
            temp -> next = NULL;
            delete top;
            top = temp;
            size_of_stack--;
        } else {
            cout << "Stack underflow" << endl;
        }
    }

    int peek() {
        if (top) {
            return top -> data;
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    int size() {
        return size_of_stack;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    Stack *st = new Stack();
    st -> push(12);
    st -> push(9);
    st -> push(4);

    cout << "Size: " << st -> size() << endl;

    cout << st -> top -> data << endl;
    cout << st -> bottom -> data << endl;

    st -> pop();

    cout << "Size: " << st -> size() << endl;

    cout << st -> top -> data << endl;
    cout << st -> bottom -> data << endl;

    st -> pop();
    st -> pop();

    cout << "Size: " << st -> size() << endl;

    st -> pop();

    cout << st -> peek() << endl;

    cout << st -> isEmpty() << endl;

    st -> push(10);
    st -> push(9);

    cout << st -> peek() << endl;

    cout << st -> isEmpty() << endl;
    return 0;
}