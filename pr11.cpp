// In any language program mostly syntax error occurs due to unbalancing
// delimiter such as (),{},[]. Write C++ program using stack to check whether given
// expression is well parenthesized or not.


#include <iostream>
using namespace std;

#define SIZE 10

class StackExp {
    int top;
    char stk[SIZE];

public:
    StackExp() { top = -1; }
    void push(char);
    char pop();
    int isFull();
    int isEmpty();
};

void StackExp::push(char x) {
    top = top + 1;  // Increment top
    stk[top] = x;
}

char StackExp::pop() {
    char s = stk[top];
    top = top - 1;  // Decrement the top
    return s;
}

int StackExp::isFull() {  // Check if stack is full
    return (top == SIZE);
}

int StackExp::isEmpty() {  // Check if stack is empty
    return (top == -1);
}

int main() {
    StackExp s1;  // Object of class
    char exp[20], ch;
    int i = 0;

    cout << "**************** PRACTICAL NO-11(D-26) *****************";
    cout << "\nEnter the expression to check whether it is well-formed or not: ";
    cin >> exp;

    if ((exp[0] == ')') || (exp[0] == ']') || (exp[0] == '}')) {
        cout << "\nInvalid Expression.....\n";
        return 0;
    } else {
        while (exp[i] != '\0') {
            ch = exp[i];
            switch (ch) {
                case '(':
                case '[':
                case '{':
                    s1.push(ch);
                    break;
                case ')':
                case ']':
                case '}':
                    if (!s1.isEmpty())
                        s1.pop();
                    else {
                        cout << "\nSorry !!! Invalid Expression or not well-parenthesized....\n";
                        return 0;
                    }
                    break;
            }
            i = i + 1;
        }
    }

    if (s1.isEmpty()) {
        cout << "\nExpression is well-parenthesized...\n";
    } else {
        cout << "\nSorry !!! Invalid Expression or not well-parenthesized....\n";
    }

    return 0;
}
