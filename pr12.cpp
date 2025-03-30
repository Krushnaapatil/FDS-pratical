// Implement C++ program for expression conversion as infix to postfix
// using stack based on given conditions: 1. Operands and operator, both must be
// single character 2. Only '+', '-', '*' and '/ ' operators are expected.

#include <iostream>
#include <cstring>
#include <cctype>  // For isalpha() and isdigit()

using namespace std;

class StackIn {
    int top;
    char st[20], exp[20];

public:
    StackIn() { top = -1; }  // Constructor to initialize top
    void push(char);
    char pop();
    void inpost();
    int precedence(char);
};

void StackIn::inpost() {
    cout << "\nENTER THE INFIX EXPRESSION: ";
    cin >> exp;  // Example input: a*b+c

    top = -1;
    char post[20];  // To store postfix expression
    int k = 0;
    char ch;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isalpha(exp[i]) || isdigit(exp[i])) {  // Operand (a-z, A-Z, 0-9)
            post[k++] = exp[i];
        } else if (exp[i] == '(') {
            push('(');
        } else if (exp[i] == ')') {
            while ((ch = pop()) != '(') {
                post[k++] = ch;
            }
        } else {  // Operator case
            while (top >= 0 && precedence(st[top]) >= precedence(exp[i])) {
                post[k++] = pop();
            }
            push(exp[i]);
        }
    }

    while (top >= 0) {  // Pop remaining operators
        post[k++] = pop();
    }
    post[k] = '\0';  // Null-terminate the postfix expression

    cout << "\nTHE POSTFIX EXPRESSION IS: " << post << "\n";
}

void StackIn::push(char ch) {
    top++;
    st[top] = ch;
}

char StackIn::pop() {
    return st[top--];
}

int StackIn::precedence(char c) {
    if (c == '(' || c == ')') return 0;
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return -1;  // Default case for invalid characters
}

int main() {
    StackIn s1;  // Object
    int choice;
    char cont;

    do {
        cout << "\n******************* PRACTICAL NO-12(D-27) **********************";
        cout << "\n!!!! Made by Krushna itself ***************";
        cout << "\n1. INFIX TO POSTFIX";
        cout << "\n2. EXIT.\n";
        cout << "\nENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s1.inpost();
                break;
            case 2:
                return 0;
            default:
                cout << "\nInvalid choice! Please try again.";
        }

        cout << "\nDo you wish to continue? (y/n): ";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');

    return 0;
}
