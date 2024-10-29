//Name - Nilesh Jivan Sonawane
//Roll No - FY23M270
//PRN- 123B1B270
//Assignment No - 7
// Implement a browser history management system using a stack data structure to track the user's browsing history. The system should support the following functionalities: a. Add visited page b. Navigate back c. View current page d. Check if history is empty or not Assume no upper bound on number of pages visited.
#include <iostream>
using namespace std;

class webpage {
    string str;  // To store the webpage URL or name
public:
    webpage *next;  // Pointer to the next webpage (for stack structure)
    
    webpage() {
        next = nullptr;  // Initialize next pointer to nullptr
    }

    // Function to read the webpage name
    void read() {
        cout << "Enter Webpage Name: ";
        cin >> str;
        cout << "----------------------------------------------------------------------------" << endl;
    }

    // Function to display the current webpage
    void display() {
        cout << "Current Webpage: " << str << endl;
        cout << "----------------------------------------------------------------------------" << endl;
    }

    friend class browserhistory;  // Allow browserhistory class to access private members
};

class browserhistory {
    webpage *top;  // Pointer to the top of the stack

public:
    // Constructor initializes top to nullptr (stack is empty)
    browserhistory() {
        top = nullptr;
    }

    // Function to add a new webpage to the stack
    void addnewpage() {
        webpage *nn = new webpage;  // Create a new webpage object
        nn->next = nullptr;
        nn->read();  // Read webpage name from user
        
        // Add to the stack
        if (top == nullptr) {  // If the stack is empty
            top = nn;
        } else {
            nn->next = top;  // Link new page to the previous top
            top = nn;  // Update top
        }
    }

    // Function to display the current webpage (top of the stack)
    void showcurrsite() {
        if (top == nullptr) {
            cout << "No pages in the history!" << endl;
            cout << "----------------------------------------------------------------------------" << endl;
        } else {
            top->display();  // Display the current page
        }
    }

    // Function to navigate back (pop the top of the stack)
    void navigateback() {
        if (top == nullptr) {
            cout << "No history to navigate back!" << endl;
            cout << "----------------------------------------------------------------------------" << endl;
        } else {
            webpage *cn = top;  // Store the current top
            top = top->next;  // Move to the previous page
            delete cn;  // Delete the current page
            cout << "Navigated back to the previous page!" << endl;
            cout << "----------------------------------------------------------------------------" << endl;
        }
    }

    // Function to check if the history is empty
    void isempty() {
        if (top == nullptr) {
            cout << "History is empty!" << endl;
            cout << "----------------------------------------------------------------------------" << endl;
        } else {
            cout << "History is not empty!" << endl;
            cout << "----------------------------------------------------------------------------" << endl;
        }
    }
};

// Main function to interact with the user
int main() {
    browserhistory s;
    int n = 1;  // Menu choice
    
    while (n != 0) {
        // Display the menu
        cout << "\nEnter:\n";
        cout << "1 - Visit a new page\n";
        cout << "2 - Show the current site\n";
        cout << "3 - Navigate back (pop element)\n";
        cout << "4 - Check if the history is empty\n";
        cout << "0 - Exit\n";
        cout << "Your choice: ";
        cin >> n;

        // Using if-else conditions instead of switch case
        if (n == 1) {
            s.addnewpage();  // Add a new page
        } else if (n == 2) {
            s.showcurrsite();  // Show the current site
        } else if (n == 3) {
            s.navigateback();  // Navigate back to the previous site
        } else if (n == 4) {
            s.isempty();  // Check if history is empty
        } else if (n == 0) {
            cout << "Exiting the browser history manager..." << endl;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
