#include<iostream>

using std::cout;
using std::endl;

class Node {
    public:
    int data;
    Node* previous;
    Node* next;

    Node(int data, Node* previous = NULL, Node* next = NULL) {
        this -> data = data;
        this -> previous = previous;
        this -> next = next;
    }
};

class DoublyLinkedList {
    public:
    Node *head;
    Node *tail;

    DoublyLinkedList(int data) {
        head = tail = new Node(data);
    }

    int length() {
        int count = 0;
        Node *temp = head;
        while (temp != NULL) {
            temp = temp -> next;
            count++;
        }
        return count;
    }

    void traverse() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp -> data << " ==> ";
            temp = temp -> next;
        }
        cout << "NULL" << endl;
    }

    void travsereReverse() {
        Node *temp = tail;
        cout << "NULL";
        while (temp != NULL) {
            cout << " <== " << temp -> data;
            temp = temp -> previous;
        }
        cout << endl;
    }

    void insertAtHead(int data) {
        Node *temp = new Node(data, NULL, head);
        head -> previous = temp;
        head = temp;
    }

    void insertAtTail(int data) {
        Node *temp = new Node(data, tail, NULL);
        tail -> next = temp;
        tail = temp;
    }

    void insertAtPosition(int position, int data) {
        if (position == 1) {
            this -> insertAtHead(data);
        } else {
            Node* temp = head;
            int i = 1;
            while (i < position-1) {
                temp = temp -> next;
                i++;
            }
            Node *new_node = new Node(data, temp, temp->next);
            if (temp -> next) {
                temp -> next -> previous = new_node;
            }
            temp -> next = new_node;
            if (!new_node -> next) {
                tail = new_node;
            }
        }
    }
};

int main() {
    DoublyLinkedList *dll = new DoublyLinkedList(10);

    dll -> insertAtHead(3);
    dll -> insertAtHead(9);
    dll -> insertAtHead(4);

    dll -> traverse();


    // dll -> insertAtHead(2);

    // cout << dll -> head -> data << endl;
    // cout << dll -> tail -> data << endl;
    // cout << dll -> head -> next << endl;
    // cout << dll -> head -> previous << endl;
    
    // cout << dll -> tail -> previous << endl;
    // cout << dll -> head << endl;

    // dll -> insertAtTail(4);
    // cout << dll -> tail -> data << endl;

    // dll -> traverse();
    // dll -> travsereReverse();

    // cout << "Length is: " << dll -> length() << endl;

    // dll -> insertAtPosition(1, 99);

    // dll -> traverse();
    // dll -> travsereReverse();

    // cout << dll -> tail -> data << endl;

    return 0;
}