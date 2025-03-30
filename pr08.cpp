// Department of Computer Engineering has student's club named 'Pinnacle
// Club'. Students of second, third and final year of department can be granted
// membership on request. Similarly one may cancel the membership of club. First
// node is reserved for president of club and last node is reserved for secretary of
// club. Write C++ program to maintain club member‘s information using singly
// linked list. Store student PRN and Name. Write functions to:
// a) Add and delete the members as well as president or even secretary.
// b) Compute total number of members of club
// c) Display members

#include <iostream>
#include <cstring>
using namespace std;

struct node {
    int prn;
    char name[20];
    node *next;
};

class pinnacle {
    node *head = NULL, *tail = NULL;

public:
    // Create a new member at the end
    void create() {
        int data;
        char name1[20];
        node *temp = new node;
        cout << "ENTER THE PRN: ";
        cin >> data;
        cout << "ENTER THE NAME: ";
        cin >> name1;
        temp->prn = data;
        strcpy(temp->name, name1);
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = tail->next;
        }
    }

    // Insert President (at the beginning)
    void president() {
        int data;
        char name1[20];
        node *temp = new node;
        cout << "ENTER THE PRN: ";
        cin >> data;
        cout << "ENTER THE NAME: ";
        cin >> name1;
        temp->prn = data;
        strcpy(temp->name, name1);
        temp->next = head;
        head = temp;
    }

    // Insert a member at a specific position
    void member() {
        int data, pos;
        char name1[20];
        node *temp = new node;
        cout << "ENTER THE PRN: ";
        cin >> data;
        cout << "ENTER THE NAME: ";
        cin >> name1;
        temp->prn = data;
        strcpy(temp->name, name1);
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            cout << "ENTER THE PRN AFTER WHICH YOU WANT TO INSERT: ";
            cin >> pos;
            node *mem = head;
            while (mem != NULL && mem->prn != pos) {
                mem = mem->next;
            }
            if (mem == NULL) {
                cout << "PRN NOT FOUND!\n";
                delete temp;
                return;
            }
            temp->next = mem->next;
            mem->next = temp;
            if (mem == tail) {
                tail = temp;
            }
        }
    }

    // Display the linked list
    void display() {
        if (head == NULL) {
            cout << "LIST IS EMPTY!\n";
            return;
        }
        node *print = head;
        while (print != NULL) {
            cout << print->prn << " ---> " << print->name << "\t";
            print = print->next;
        }
        cout << endl;
    }

    // Count total members
    void total() {
        int count = 0;
        node *temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "TOTAL NUMBER OF MEMBERS: " << count << endl;
    }

    // Delete the President (first node)
    void Delete_pre() {
        if (head == NULL) {
            cout << "LIST IS EMPTY!\n";
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
    }

    // Delete the Secretary (last node)
    void Delete_sec() {
        if (head == NULL) {
            cout << "LIST IS EMPTY!\n";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        node *current = head;
        node *prev = NULL;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        tail = prev;
        delete current;
    }

    // Delete a member at a specific position
    void Delete_mem() {
        if (head == NULL) {
            cout << "LIST IS EMPTY!\n";
            return;
        }
        int pos;
        cout << "ENTER THE PRN OF THE MEMBER TO DELETE: ";
        cin >> pos;

        if (head->prn == pos) {
            Delete_pre();
            return;
        }

        node *current = head;
        node *prev = NULL;
        while (current != NULL && current->prn != pos) {
            prev = current;
            current = current->next;
        }
        if (current == NULL) {
            cout << "PRN NOT FOUND!\n";
            return;
        }
        prev->next = current->next;
        if (current == tail) {
            tail = prev;
        }
        delete current;
    }
};

int main() {
    int ch, ch2, ch3;
    char ch1;
    pinnacle p;

    do {
        cout << "\n****** PRACTICAL NO-08(C-19) PINNACLE CLUB ******";
        cout << "\n~~~ by Krushna Patil ~~~";
        cout << "\n-------------------- MENU --------------------\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT MEMBER\n";
        cout << "4. TOTAL MEMBERS\n";
        cout << "5. DELETE\n";
        cout << "************************************************";
        cout << "\nENTER YOUR CHOICE: ";
        cin >> ch;

        switch (ch) {
            case 1:
                p.create();
                break;
            case 2:
                p.display();
                break;
            case 3:
                cout << "**********************\n";
                cout << "1. PRESIDENT\n";
                cout << "2. MEMBER\n";
                cout << "3. SECRETARY\n";
                cout << "ENTER YOUR CHOICE: ";
                cin >> ch2;
                switch (ch2) {
                    case 1:
                        p.president();
                        break;
                    case 2:
                        p.member();
                        break;
                    case 3:
                        p.create();
                        break;
                }
                break;
            case 4:
                p.total();
                break;
            case 5:
                cout << "**********************\n";
                cout << "1. PRESIDENT\n";
                cout << "2. MEMBER\n";
                cout << "3. SECRETARY\n";
                cout << "ENTER YOUR CHOICE: ";
                cin >> ch3;
                switch (ch3) {
                    case 1:
                        p.Delete_pre();
                        break;
                    case 2:
                        p.Delete_mem();
                        break;
                    case 3:
                        p.Delete_sec();
                        break;
                }
                break;
            default:
                cout << "INVALID CHOICE!\n";
        }
        cout << "\nDO YOU WANT TO CONTINUE? (y/n): ";
        cin >> ch1;
    } while (ch1 == 'y' || ch1 == 'Y');

    return 0;
}
