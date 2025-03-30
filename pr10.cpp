// Write C++ program for storing appointment schedule for day.
// Appointments are booked randomly using linked list. Set start and end time and
// min and max duration for visit slot. Write functions for- A) Display free slots B)
// Book appointment C) Sort list based on time D) Cancel appointment ( check
// validity, time bounds, availability) E) Sort list based on time using pointer
// manipulation


#include <iostream>
using namespace std;

struct SLL_Node // Node Structure of each Appointment
{
    int start, end, min, max, flag;
    struct SLL_Node *next;
} *head;

class App_Shedule
{
    int size; // Number of Appointments

public:
    void create_Shed();
    void display_Shed();
    void book_App();
    void cancel_App();
    void sort_App();
} A1;

int main()
{
    int ch;
    char ans;
    do
    {
        cout << "\n\n*********** PRACTICAL NO-10(C-21) **************";
        cout << "\n 1. CREATE APPOINTMENT SCHEDULE";
        cout << "\n 2. DISPLAY FREE SLOTS";
        cout << "\n 3. BOOK AN APPOINTMENT";
        cout << "\n 4. CANCEL AN APPOINTMENT";
        cout << "\n 5. SORT SLOT BASED ON TIME";
        cout << "\n***********************************************";
        cout << "\n\n\t Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            A1.create_Shed();
            break;
        case 2:
            A1.display_Shed();
            break;
        case 3:
            A1.book_App();
            break;
        case 4:
            A1.cancel_App();
            break;
        case 5:
            A1.sort_App();
            break;
        default:
            cout << "\n\t Wrong choice!!!";
        }

        cout << "\n\n\t Do you want to continue? (y/n) : ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}

void App_Shedule::create_Shed()
{
    int i;
    struct SLL_Node *temp, *last;
    head = NULL;
    cout << "\n\n\t How many Appointment Slots: ";
    cin >> size;

    for (i = 0; i < size; i++)
    {
        temp = new SLL_Node;
        cout << "\n\n\t Enter Start Time: ";
        cin >> temp->start;
        cout << "\n\t Enter End Time: ";
        cin >> temp->end;
        cout << "\n\n\t Enter Minimum Duration: ";
        cin >> temp->min;
        cout << "\n\t Enter Maximum Duration: ";
        cin >> temp->max;
        temp->flag = 0;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            last = head;
        }
        else
        {
            last->next = temp;
            last = last->next;
        }
    }
}

void App_Shedule::display_Shed()
{
    int cnt = 1;
    struct SLL_Node *temp;
    cout << "\n\n\t **** Appointment Schedule ****";
    cout << "\n\n\t Srno.\tStart\tEnd\tMin_Dur\tMax_Dur\tStatus";
    temp = head;

    while (temp != NULL)
    {
        cout << "\n\n\t " << cnt;
        cout << "\t " << temp->start;
        cout << "\t " << temp->end;
        cout << "\t " << temp->min;
        cout << "\t " << temp->max;
        cout << (temp->flag ? "\t-Booked-" : "\t--Free--");
        temp = temp->next;
        cnt++;
    }
}

void App_Shedule::book_App()
{
    int start;
    struct SLL_Node *temp;
    cout << "\n\n\t Please enter Appointment time: ";
    cin >> start;
    temp = head;

    while (temp != NULL)
    {
        if (start == temp->start)
        {
            if (temp->flag == 0)
            {
                cout << "\n\n\t Appointment Slot is Booked!!!";
                temp->flag = 1;
            }
            else
            {
                cout << "\n\n\t Appointment Slot is not Available!!!";
            }
        }
        temp = temp->next;
    }
}

void App_Shedule::cancel_App()
{
    int start;
    struct SLL_Node *temp;
    cout << "\n\n\t Please enter Appointment time to Cancel: ";
    cin >> start;
    temp = head;

    while (temp != NULL)
    {
        if (start == temp->start)
        {
            if (temp->flag == 1)
            {
                cout << "\n\n\t Your Appointment Slot is Canceled!!!";
                temp->flag = 0;
            }
            else
            {
                cout << "\n\n\t Your Appointment was not Booked!!!";
            }
        }
        temp = temp->next;
    }
}

void App_Shedule::sort_App()
{
    int i, val;
    struct SLL_Node *temp;
    for (i = 0; i < size - 1; i++)
    {
        temp = head;
        while (temp->next != NULL)
        {
            if (temp->start > temp->next->start)
            {
                swap(temp->start, temp->next->start);
                swap(temp->end, temp->next->end);
                swap(temp->min, temp->next->min);
                swap(temp->max, temp->next->max);
                swap(temp->flag, temp->next->flag);
            }
            temp = temp->next;
        }
    }
    cout << "\n\n\t The Appointments got Sorted!!!";
}
