// A double-ended queue (deque) is a linear list in which additions and
// deletions may be made at either end. Obtain a data representation mapping a
// deque into a one-dimensional array. Write C++ program to simulate deque with
// functions to add and delete elements from either end of the deqeue.


#include <iostream> // Header file
using namespace std;

#define SIZE 5 // Array size

class Dequeue {
    int a[SIZE], front, rear;

public:
    Dequeue(); // Constructor declaration
    void addAtBeg(int);
    void addAtEnd(int);
    void deleteFromFront();
    void deleteFromRear();
    void display();
};

// Constructor: Initialize front and rear
Dequeue::Dequeue() {
    front = -1;
    rear = -1;
}

// Function to insert element at end (rear)
void Dequeue::addAtEnd(int item) {
    if (rear >= SIZE - 1) { // Check if queue is full
        cout << "\nINSERTION IS NOT POSSIBLE, OVERFLOW!!!!\n";
        return;
    }
    if (front == -1) { // First insertion
        front = 0;
        rear = 0;
    } else {
        rear++;
    }
    a[rear] = item;
    cout << "\nINSERTED ITEM: " << a[rear] << "\n";
}

// Function to insert element at beginning (front)
void Dequeue::addAtBeg(int item) {
    if (front == -1) { // First insertion
        front = 0;
        a[++rear] = item;
        cout << "\nINSERTED ELEMENT: " << item << "\n";
    } else if (front != 0) { // Insert at front
        a[--front] = item;
        cout << "\nINSERTED ELEMENT: " << item << "\n";
    } else {
        cout << "\nINSERTION IS NOT POSSIBLE, OVERFLOW!!!\n";
    }
}

// Function to display the queue
void Dequeue::display() {
    if (front == -1) {
        cout << "DEQUEUE IS EMPTY\n";
        return;
    }
    cout << "DEQUEUE ELEMENTS: ";
    for (int i = front; i <= rear; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

// Function to delete from front
void Dequeue::deleteFromFront() {
    if (front == -1) {
        cout << "DELETION IS NOT POSSIBLE :: DEQUEUE IS EMPTY\n";
        return;
    }
    cout << "DELETED ELEMENT: " << a[front] << "\n";
    if (front == rear) { // Single element case
        front = rear = -1;
    } else {
        front++;
    }
}

// Function to delete from rear
void Dequeue::deleteFromRear() {
    if (front == -1) {
        cout << "DELETION IS NOT POSSIBLE :: DEQUEUE IS EMPTY\n";
        return;
    }
    cout << "DELETED ELEMENT: " << a[rear] << "\n";
    if (front == rear) { // Single element case
        front = rear = -1;
    } else {
        rear--;
    }
}

int main() {
    int choice, item;
    Dequeue d1; // Object of class

    do {
        cout << "\n~~~ Made by Krushna Patil (Roll No. 29) ~~~";
        cout << "\n\n***************** PRACTICAL NO-14(E-31) DEQUEUE *****************\n";
        cout << "1. INSERT AT START\n";
        cout << "2. INSERT AT END\n";
        cout << "3. DISPLAY\n";
        cout << "4. DELETE FROM FRONT\n";
        cout << "5. DELETE FROM REAR\n";
        cout << "6. EXIT\n";
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "ENTER THE ELEMENT TO BE INSERTED: ";
                cin >> item;
                d1.addAtBeg(item);
                break;
            case 2:
                cout << "ENTER THE ELEMENT TO BE INSERTED: ";
                cin >> item;
                d1.addAtEnd(item);
                break;
            case 3:
                d1.display();
                break;
            case 4:
                d1.deleteFromFront();
                break;
            case 5:
                d1.deleteFromRear();
                break;
            case 6:
                exit(0);
            default:
                cout << "INVALID CHOICE!!!!!\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
