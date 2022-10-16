#include<iostream>
#include<queue>

using std::endl;
using std::cout;
using std::queue;

int main() {
    queue<int> q;
    q.push(21);
    
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Is Empty: " << q.empty() << endl;
    cout << endl;

    q.push(80);

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Is Empty: " << q.empty() << endl;
    cout << endl;

    q.push(45);
    q.push(10);
    q.push(93);
    q.push(70);
    q.pop();

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    cout << endl;

    // Clearing the queue
    while (!q.empty()) {
        q.pop();
    }

    cout << "Size: " << q.empty() << endl;
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl; // 70, I don't know why
        
    return 0;
}