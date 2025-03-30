// The ticket booking system of Cinemax theater has to be implemented using
// C++ program. There are 10 rows and 7 seats in each row. Doubly circular linked
// list has to be maintained to keep track of free seats at rows. Assume some random
// booking to start with. Use array to store pointers (Head pointer) to each row. On
// demand a) The list of available seats is to be displayed b) The seats are to be
// booked c) The booking can be cancelled.


#include<iostream>
using namespace std;

class node {
public:
    char status;
    int stn;
    node *next, *prev;
};

class cinemax {
public:
    node *head, *tail;
    
    cinemax() { head = tail = NULL; }  // Constructor initializes head and tail

    void create(); 
    void display();
    void book();
    void cancel();
};

void cinemax::create() {
    node *n;
    for (int i = 1; i <= 7; i++) {
        n = new node;
        n->status = 'F'; // 'F' for free seat
        n->stn = i;
        n->next = n->prev = NULL;

        if (head == NULL) {
            head = tail = n;
            head->next = head;
            head->prev = head;
        } else {
            tail->next = n;
            n->prev = tail;
            n->next = head; // Circular link
            head->prev = n;
            tail = n;
        }
    }
}

void cinemax::display() {
    node *temp = head;
    if (head == NULL) return;

    do {
        cout << "(" << temp->status << ") ";
        temp = temp->next;
    } while (temp != head);
}

void cinemax::book() {
    node *temp = head;
    int seatNo;
    cout << "\nEnter seat number you want to book: ";
    cin >> seatNo;

    for (int i = 1; i < seatNo; i++)
        temp = temp->next;

    if (temp->status == 'B')
        cout << "\nSelected seat is already booked!\n";
    else {
        temp->status = 'B';
        cout << "\nSeat " << seatNo << " booked successfully!\n";
    }
}

void cinemax::cancel() {
    node *temp = head;
    int seatNo;
    cout << "\nEnter seat number you want to cancel: ";
    cin >> seatNo;

    for (int i = 1; i < seatNo; i++)
        temp = temp->next;

    if (temp->status == 'F')
        cout << "\nThe selected seat is already free.\n";
    else {
        temp->status = 'F';
        cout << "\nSeat " << seatNo << " cancelled successfully!\n";
    }
}

int main() {
    cinemax c[11]; // Creating 10 rows (1-10)
    int choice, row;
    char ans;
    
    cout << "\n*********** CINEMAX TICKET BOOKING SYSTEM ************\n";
    cout << "*************** SEAT AVAILABILITY CHART ***************\n";
    
    for (int i = 1; i <= 10; i++) c[i].create(); // Initialize rows
    
    cout << "\nSeat Numbers: ";
    for (int a = 1; a <= 7; a++) cout << "\t" << a;
    cout << endl;
    
    for (int i = 1; i <= 10; i++) {
        cout << i << "\t";
        c[i].display();
        cout << endl;
    }
    
    do {
        cout << "\n*********** MENU ************\n";
        cout << "1. Book Seat\n2. Cancel Seat\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "\nEnter row number (1-10): ";
                cin >> row;
                if (row >= 1 && row <= 10) {
                    c[row].book();
                } else {
                    cout << "Invalid row number!";
                }
                break;

            case 2:
                cout << "\nEnter row number (1-10): ";
                cin >> row;
                if (row >= 1 && row <= 10) {
                    c[row].cancel();
                } else {
                    cout << "Invalid row number!";
                }
                break;

            default:
                cout << "Invalid choice!";
        }

        cout << "\n\nDo you want to continue? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
