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

class LinkedList {
    public:
    Node* head;
    Node* tail;

    LinkedList(int data) {
        head = tail = new Node(data);
    }

    void insertAtHead(int data) {
        Node *temp = new Node(data, head);
        head = temp;
    }

    void insertAtTail(int data) {
        Node *temp = new Node(data);
        tail -> next = temp;
        tail = temp;
    }
    
    void traverse() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp -> data << " ==> ";
            temp = temp -> next;
        }
        cout << "NULL" << endl;
        delete temp;
    }
};

int main() {
    LinkedList *ll1 = new LinkedList(int(4));
    ll1 -> insertAtHead(10);
    ll1 -> traverse();
    ll1 -> insertAtTail(6);
    ll1 -> traverse();
    return 0;
}