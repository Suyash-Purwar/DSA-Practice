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
    Node *head;
    Node *tail;

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

    void insertAtPosition(int position, int data) {
        if (position == 1) {
            this -> insertAtHead(data);
        } else {
            Node *temp_before = head;
            int i = 1;
            while (i < position-1) {
                temp_before = temp_before -> next;
                i++;
            }
            Node *temp_after = temp_before -> next;
            Node *new_node = new Node(data, temp_after);
            temp_before -> next = new_node;
            if (temp_after == NULL) {
                tail = new_node;
            }
        }
    }

    int deleteAtHead() {
        Node *temp = head;
        int deleted_data = temp -> data;
        head = head -> next;
        delete temp;
        return deleted_data;
    }

    int deleteAtTail() {
        Node* current = head;
        while (current -> next != tail) {
            current = current -> next;
        }
        int deleted_data = tail -> data;
        delete current -> next;
        current -> next = NULL;
        tail = current;
        return deleted_data;
    }
    
    int deleteAtPosition(int position) {
        if (position == 1) {
            return this -> deleteAtHead();
        }
        Node* temp_before = head;
        int i = 1;
        while (i < position-1) {
            temp_before = temp_before -> next;
            i++;
        }
        Node* toBeDeleted = temp_before -> next;
        int deleted_data = toBeDeleted -> data;
        temp_before -> next = toBeDeleted -> next;
        delete toBeDeleted;
        if (temp_before -> next == NULL) {
            tail = temp_before;
        }
        return deleted_data;
    }

    // Deletes the first occurence of the value
    int deleteOccurenceOf(int value) {
        Node *temp = head;
        if (temp -> data == value) {
            return deleteAtHead();
        }
        while (temp -> next -> data != value) {
            temp = temp -> next;
        }
        Node* to_be_deleted = temp -> next;
        int deleted_data = to_be_deleted -> data;
        temp -> next = to_be_deleted -> next;
        if (to_be_deleted == tail) {
            tail = temp;
        }
        delete to_be_deleted;
        return deleted_data;
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
    LinkedList *ll1 = new LinkedList(4);
    ll1 -> insertAtHead(10);
    ll1 -> insertAtHead(3);
    ll1 -> insertAtTail(1);
    ll1 -> insertAtPosition(1, 8);

    ll1 -> traverse();

    cout << ll1 -> deleteAtTail() << endl;
    cout << ll1 -> deleteOccurenceOf(8) << endl;
    cout << ll1 -> tail -> data << endl;

    ll1 -> traverse();

    ll1 -> insertAtPosition(4, 10);
    ll1 -> traverse();
    return 0;
}