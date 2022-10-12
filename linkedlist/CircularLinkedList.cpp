#include<iostream>

using std::cout;
using std::endl;

class Node {
    public:
    int data;
    Node *next;

    Node(int data, Node* next = NULL) {
        this -> data = data;
        this -> next = next;
    }
};

class CircularLinkedList {
    public:
    Node* tail;

    CircularLinkedList(int data) {
        tail = new Node(data);
        tail -> next = tail;
    }

    void insertNodeAfter(int data, int target) {
        if (tail) {
            Node* current = tail;
            bool is_iteration_complete = false;
            while (current -> data != target && !is_iteration_complete) {
                current = current -> next;
                if (current == tail) is_iteration_complete = true;
            }
            if (is_iteration_complete) {
                cout << "Target not found" << endl;
                return;
            }
            Node *new_node = new Node(data, current -> next);
            current -> next = new_node;
        } else {
            tail = new Node(data);
            tail -> next = tail;
        }
    }

    void traversal() {
        Node* current = tail;
        do {
            cout << current -> data << " ==> ";
            current = current -> next;
        } while (current != tail);
        cout << endl;
    }
};

int main() {
    CircularLinkedList *cll = new CircularLinkedList(10);

    cll -> insertNodeAfter(7, 10);
    cll -> traversal();
    
    cll -> insertNodeAfter(19, 7);
    cll -> traversal();

    cll -> insertNodeAfter(1, 19);
    cll -> traversal();

    cll -> insertNodeAfter(101, 10);
    cll -> traversal();

    return 0;
}