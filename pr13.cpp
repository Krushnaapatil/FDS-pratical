// Queues are frequently used in computer programming, and a typical
// example is the creation of a job queue by an operating system. If the operating
// system does not use priorities, then the jobs are processed in the order they enter
// the system. Write C++ program for simulating job queue. Write functions to add
// job and delete job from queue


#include <iostream>
using namespace std;

class Queue {
    int queue1[5];  // Queue array to store elements
    int rear, front; // Rear and front pointers

public:
    Queue() { rear = -1; front = -1; } // Constructor to initialize rear and front

    void insertJob(int x) {
        if (rear >= 4) {  // Check if queue is full
            cout << "QUEUE IS OVERFLOW\n";
            front = rear = -1; // Reset queue
            return;
        }
        queue1[++rear] = x;
        cout << "INSERTED - " << x << "\n";
    }

    void deleteJob() {
        if (front == rear) {  // Check if queue is empty
            cout << "QUEUE IS UNDERFLOW\n";
            return;
        }
        cout << "DELETED - " << queue1[++front] << "\n";
    }

    void display() {
        if (rear == front) {  // Check if queue is empty
            cout << "QUEUE IS EMPTY\n";
            return;
        }
        cout << "QUEUE ELEMENTS: ";
        for (int i = front + 1; i <= rear; i++)
            cout << queue1[i] << " ";
        cout << "\n";
    }
};

int main() {
    int ch, jobId;
    Queue qu;  // Queue object

    while (true) {
        cout << "\n~~~~ Made by Krushna Patil (Roll No: 29) ~~~~";
        cout << "\n\n************** PRACTICAL NO-13(E-29) JOB QUEUE ***************";
        cout << "\n1. INSERT JOB";
        cout << "\n2. DELETE JOB";
        cout << "\n3. DISPLAY";
        cout << "\n4. EXIT";
        cout << "\nENTER YOUR CHOICE: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "ENTER ORDER ID OF JOB: ";
                cin >> jobId;
                qu.insertJob(jobId);
                break;
            case 2:
                qu.deleteJob();
                break;
            case 3:
                qu.display();
                break;
            case 4:
                return 0;
            default:
                cout << "INVALID CHOICE! PLEASE TRY AGAIN.\n";
        }
    }

    return 0;
}
