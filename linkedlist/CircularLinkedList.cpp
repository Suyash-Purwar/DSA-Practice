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

    int length() {
        if (!tail) return 0;
        Node *temp = tail;
        int count = 1;
        while (temp -> next != tail) {
            temp = temp -> next;
            count++;
        }
        return count;
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
        if (!tail) {
            cout << "List is empty" << endl;
            return;
        }
        do {
            cout << current -> data << " ==> ";
            current = current -> next;
        } while (current != tail);
        cout << endl;
    }

    int deleteNode(int value) {
        if (tail == NULL) {
            cout << "List is empty" << endl;
            return -1;
        }
        bool is_iteration_complete = false;
        Node *before_target = tail;
        while (before_target -> next -> data != value && !is_iteration_complete) {
            before_target = before_target -> next;
            if (before_target == tail) is_iteration_complete = true;
        }
        if (is_iteration_complete) {
            cout << "Target not found!" << endl;
            return -1;
        }
        Node *target = before_target -> next;
        int deleted_data = target -> data;
        before_target -> next = target -> next;
        if (before_target == target) tail = NULL;
        if (target == tail) tail = before_target;
        delete target;
        return deleted_data;
    }
};

int main() {
    CircularLinkedList *cll = new CircularLinkedList(10);

    cll -> insertNodeAfter(1, 10);
    cll -> insertNodeAfter(13, 1);

    cll -> traversal();

    cout << cll -> deleteNode(10) << endl;

    cll -> traversal();

    cout << cll -> length() << endl;

    // cll -> insertNodeAfter(7, 10);
    // cll -> traversal();
    
    // cll -> insertNodeAfter(19, 7);
    // cll -> traversal();

    // cll -> insertNodeAfter(1, 19);
    // cll -> traversal();

    // cll -> insertNodeAfter(101, 10);
    // cll -> traversal();

    // cll -> insertNodeAfter(3, 10);
    // cout << cll -> deleteNode(3) << endl;

    // cll -> traversal();
    // cout << cll -> tail -> data << endl;

    // cout << cll -> deleteNode(3) << endl;

    // cll -> traversal();
    // // cout << cll -> length() << endl;
    // cout << cll -> deleteNode(3) << endl;

    return 0;
}