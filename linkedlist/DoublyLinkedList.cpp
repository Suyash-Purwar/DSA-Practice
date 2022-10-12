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

    void traverseReverse() {
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
        if (head) {
            head -> previous = temp;
        } else {
            tail = temp;
        }
        head = temp;
    }

    void insertAtTail(int data) {
        Node *temp = new Node(data, tail, NULL);
        if (tail) {
            tail -> next = temp;
        } else {
            head = temp;
        }
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
            if (temp -> next) temp -> next -> previous = new_node;
            temp -> next = new_node;
            if (!new_node -> next) tail = new_node;
        }
    }

    int deleteAtHead() {
        if (this -> length() == 0) {
            cout << "Nothing to delete!" << endl;
            return -1;
        }
        if (this -> length() == 1) {
            int delete_data = head -> data;
            delete head;
            head = tail = NULL;
            return delete_data;
        }
        Node *temp = head;
        temp = temp -> next;
        temp -> previous = NULL;
        int deleted_data = head -> data;
        delete head;
        head = temp;
        return deleted_data;
    }

    int deleteAtTail() {
        if (this -> length() == 0) {
            cout << "Nothing to delete!";
            return -1;
        }
        if (this -> length() == 1) {
            int delete_data = head -> data;
            delete head;
            head = tail = NULL;
            return delete_data;
        }
        Node *temp = head;
        while (temp -> next != tail) {
            temp = temp -> next;
        }
        Node *to_be_deleted = temp -> next;
        int deleted_data = to_be_deleted -> data;
        temp -> next = NULL;
        delete to_be_deleted;
        tail = temp;
        return deleted_data;
    }

    int deleteAtPosition(int position) {
        if (this -> length() == 0) {
            cout << "Nothing to delete!";
            return -1;
        }
        if (position == 1) return this -> deleteAtHead();
        int i = 1;
        Node *before_target = head;
        while (i < position-1) {
            before_target = before_target -> next;
            i++;
        }
        Node *target = before_target -> next;
        Node *after_target = target -> next;
        int deleted_data = target -> data;
        before_target -> next = after_target;
        if (after_target) after_target -> previous = before_target;
        if (!before_target -> next) tail = before_target;
        delete target;
        return deleted_data;
    }

    // Deletes the first occurence of the value
    int deleteOccurenceOf(int value) {
        if (this -> length() == 0) {
            cout << "Nothing to delete!" << endl;
            return -1;
        }
        if (head -> data == value) return deleteAtHead();
        Node *target_before = head;
        while (target_before -> next -> data != value) {
            target_before = target_before -> next;
        }
        Node *target = target_before -> next;
        Node *target_after = target -> next;
        int deleted_data = target -> data;
        target_before -> next = target_after;
        if (target_after) target_after -> previous = target_before;
        if (!target_before -> next) tail = target_before;
        delete target;
        return deleted_data;
    }
};

int main() {
    DoublyLinkedList *dll = new DoublyLinkedList(10);

    dll -> insertAtHead(3);
    dll -> insertAtHead(9);
    dll -> insertAtHead(4);
    dll -> insertAtHead(42);
    dll -> insertAtHead(10);

    dll -> traverse();

    cout << dll -> deleteOccurenceOf(10) << endl;
    dll -> traverse();
    cout << "head: " << dll->head->data << " tail: " << dll->tail->data << endl;

    // cout << dll -> deleteAtHead() << endl;
    // cout << dll -> deleteAtHead() << endl;
    // cout << dll -> deleteAtHead() << endl;
    // cout << dll -> deleteAtHead() << endl;
    // cout << dll -> deleteAtHead() << endl;
    // cout << dll -> deleteAtHead() << endl;
    // cout << dll -> deleteAtHead() << endl;
    
    // dll -> insertAtHead(12);
    // dll -> insertAtTail(2);

    // dll -> traverse();
    // dll -> travsereReverse();

    // cout << dll -> deleteAtPosition(1) << endl;
    // dll -> traverse();

    // cout << dll -> deleteAtPosition(5) << endl;
    // dll -> traverse();
    // cout << dll -> tail -> data << endl;
    
    // dll -> travsereReverse();

    // cout << dll -> deleteAtHead() << endl;
    // cout << dll -> head -> data << endl;
    
    // dll -> traverse();

    // cout << dll -> deleteAtTail() << endl;
    // cout << dll -> tail -> data << endl;

    // dll -> traverse();

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