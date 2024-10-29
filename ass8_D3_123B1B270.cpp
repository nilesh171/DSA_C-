//Name - Nilesh Jivan Sonawane
//Roll No - FY23M270
//PRN- 123B1B270
//Assignment No - 8
#include <iostream>
#include <string>
#include <cmath> // For pow()

using namespace std;

// Node structure to represent each element in the stack
struct Node {
    char data;
    Node* next;
};

// Stack class implemented using a linked list
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == nullptr) {
            return '\0';
        }
        Node* temp = top;
        char poppedValue = top->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    char peek() {
        if (top == nullptr) {
            return '\0';
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to return precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    return 0;
}

// Custom function to reverse a string without using algorithm library
string reverseString(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    return str;
}

// Custom function to check if a character is a digit without using cctype
bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to convert infix to postfix expression
string infixToPostfix(string infix) {
    Stack stack;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If the scanned character is an operand, add it to the postfix string
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || isDigit(c)) {
            postfix += c;
        }
        // If the scanned character is '(', push it onto the stack
        else if (c == '(') {
            stack.push(c);
        }
        // If the scanned character is ')', pop from the stack until '(' is found
        else if (c == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop();
        }
        // If the scanned character is an operator
        else if (isOperator(c)) {
            while (!stack.isEmpty() && precedence(stack.peek()) > precedence(c)) {
                postfix += stack.pop();
            }
            stack.push(c);
        }
    }

    // Pop all remaining operators from the stack
    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

// Function to convert infix to prefix expression
string infixToPrefix(string infix) {
    // Reverse the infix expression using custom reverse function
    infix = reverseString(infix);

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // Convert the modified infix to postfix
    string postfix = infixToPostfix(infix);

    // Reverse the postfix expression to get the prefix
    return reverseString(postfix);
}

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix) {
    Stack stack;
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        // If the scanned character is an operand, push it onto the stack
        if (isDigit(c)) {
            stack.push(c - '0');  // Convert char to int
        }
        // If the scanned character is an operator, pop two elements and apply the operator
        else if (isOperator(c)) {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            switch (c) {
                case '+': stack.push(operand1 + operand2); break;
                case '-': stack.push(operand1 - operand2); break;
                case '*': stack.push(operand1 * operand2); break;
                case '/': stack.push(operand1 / operand2); break;
                case '^': stack.push(pow(operand1, operand2)); break;
            }
        }
    }
    return stack.pop();
}

// Function to evaluate a prefix expression
int evaluatePrefix(string prefix) {
    Stack stack;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        // If the scanned character is an operand, push it onto the stack
        if (isDigit(c)) {
            stack.push(c - '0');  // Convert char to int
        }
        // If the scanned character is an operator, pop two elements and apply the operator
        else if (isOperator(c)) {
            int operand1 = stack.pop();
            int operand2 = stack.pop();
            switch (c) {
                case '+': stack.push(operand1 + operand2); break;
                case '-': stack.push(operand1 - operand2); break;
                case '*': stack.push(operand1 * operand2); break;
                case '/': stack.push(operand1 / operand2); break;
                case '^': stack.push(pow(operand1, operand2)); break;
            }
        }
    }
    return stack.pop();
}

int main() {
    string infix;

    // Input the infix expression
    cout << "Enter infix expression: ";
    cin >> infix;

    // Convert infix to postfix
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    // Convert infix to prefix
    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    // Evaluate postfix expression
    cout << "Postfix Evaluation: " << evaluatePostfix(postfix) << endl;

    // Evaluate prefix expression
    cout << "Prefix Evaluation: " << evaluatePrefix(prefix) << endl;

    return 0;
}
