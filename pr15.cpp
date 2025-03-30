// Pizza parlor accepting maximum M orders. Orders are served in first
// come first served basis. Order once placed cannot be cancelled. Write C++
// program to simulate the system using circular queue using array.

#include <iostream>
using namespace std;

class Pizza {
    int order[10];
    int max = 5;
    int f, r;

public:
    Pizza() { f = -1; r = -1; }

    int isFull() {
        return ((f == 0 && r == max - 1) || (f == (r + 1) % max));
    }

    int isEmpty() {
        return (f == -1);
    }

    void add(int a) {
        if (isFull()) {
            cout << "\nORDER IS FULL!!!\n";
            return;
        }
        if (f == -1) {
            f = r = 0;
        } else {
            r = (r + 1) % max;
        }
        order[r] = a;
        cout << "\nORDER PLACED: " << a << "\n";
    }

    void remove() {
        if (isEmpty()) {
            cout << "\nNO ORDER TO DELETE\n";
            return;
        }
        int removedOrder = order[f];
        if (f == r) {
            f = r = -1;
        } else {
            f = (f + 1) % max;
        }
        cout << "\nORDER DELETED: " << removedOrder << "\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "\nCURRENTLY NO ORDERS\n";
            return;
        }
        cout << "\nCURRENT ORDERS:\n";
        int temp = f;
        while (temp != r) {
            cout << " " << order[temp];
            temp = (temp + 1) % max;
        }
        cout << " " << order[temp] << "\n";
    }
};

int main() {
    int ch, orderNum;
    Pizza p;

    do {
        cout << "\n~~ By Krushna Patil (29) ~~";
        cout << "\n\n************** PRACTICAL NO-15(E-32) PIZZA PARLOUR **************";
        cout << "\n1. ORDER";
        cout << "\n2. REMOVE ORDER";
        cout << "\n3. DISPLAY ORDERS";
        cout << "\n4. EXIT";
        cout << "\nENTER YOUR CHOICE: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter Order Number: ";
                cin >> orderNum;
                p.add(orderNum);
                break;
            case 2:
                p.remove();
                break;
            case 3:
                p.display();
                break;
            case 4:
                cout << "\nEXITING... THANK YOU!\n";
                break;
            default:
                cout << "\nINVALID CHOICE! TRY AGAIN.\n";
        }
    } while (ch != 4);

    return 0;
}
