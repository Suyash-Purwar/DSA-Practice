#include<iostream>

using std::cout;
using std::endl;

class Queue {
    public:
    int *queue;
    int size;
    int front;
    int back;

    Queue(int size) {
        this -> size = size;
        queue = new int[size];
        front = back = 0;
    }

    void push(int element) {
        if (back < size) {
            queue[back] = element;
            back++;
        } else {
            cout << "Queue overflow" << endl;
        }
    }

    void pop() {
        if (front != back) {
            queue[front] = -1;
            front++;
            if (front == back) front = back = 0;
        } else {
            cout << "Queue underflow" << endl;
        }
    }

    int atFront() {
        if (front != back) {
            return queue[front];
        } else {
            cout << "Queue is empty!" << endl;
            return -1;
        }
    }

    int atBack() {
        if (front != back) {
            return queue[back-1];
        } else {
            cout << "Queue is empty!" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return front == back;
    }

    int qsize() {
        return back - front;
    }
};

int main() {
    Queue *q = new Queue(4);
    q->pop();
    cout << q->atFront() << endl;
    cout << q->atBack() << endl;

    q->push(12);
    q->push(90);
    q->push(60);
    
    cout << q -> atFront() << endl;
    cout << q -> atBack() << endl;

    q->push(10);
    q->push(23); // Queue overflow
    q->push(100); // Queue overflow

    cout << "Size: " << q -> qsize() << endl;

    q->pop();
    q->pop();
    q->pop();
    q->pop();

    cout << q->atFront() << endl;
    cout << q->atBack() << endl;

    cout << q -> front << endl;
    cout << q -> back << endl;

    cout << "Size: " << q -> qsize() << endl;

    cout << q -> isEmpty() << endl; // Yes
    q->push(76);
    cout << q -> isEmpty() << endl; // No
    return 0;
}