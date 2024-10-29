//Name - Nilesh Jivan Sonawane
//Roll No - FY23M270
//PRN- 123B1B270
//Assignment No - 4
//Implement a simple text editor application using a doubly linked list to manage the text buffer. Text editor should support the following functionalities: a. Insert text b. Delete text c. Display text d. Search text e. Print text in reverse.
#include<iostream>
using namespace std;

class statement {
    string s;
    statement *next, *prev;  // Doubly linked list pointers

public:
    statement() : next(nullptr), prev(nullptr) {}  // Initialize pointers

    // Read input string
    void read() {
        cout << "Enter String: ";
        cin >> s;
    }

    // Display string
    void display() {
        cout << "String: " << s << endl;
    }

    friend class wordprocessor;
};

class wordprocessor {
    statement *head, *tail;  // Pointers for doubly linked list

public:
    wordprocessor() : head(nullptr), tail(nullptr) {}  // Initialize head and tail

    // Insert a new string into the editor
    void adddata() {
        statement *nn = new statement;
        nn->read();
        nn->next = nullptr;

        if (head == nullptr) {  // If the list is empty
            head = tail = nn;
        } else {  // Insert at the end
            tail->next = nn;
            nn->prev = tail;
            tail = nn;
        }
    }

    // Display the list in forward direction
    void displayforward() {
        if (head == nullptr) {
            cout << "Text editor is empty!" << endl;
            return;
        }
        statement *ch = head;
        while (ch != nullptr) {
            ch->display();
            ch = ch->next;
        }
    }

    // Display the list in reverse direction
    void displayrev() {
        if (tail == nullptr) {
            cout << "Text editor is empty!" << endl;
            return;
        }
        statement *ch = tail;
        while (ch != nullptr) {
            ch->display();
            ch = ch->prev;
        }
    }

    // Delete a string from the list
    void deletestr() {
        string str;
        cout << "Enter String to be Deleted: ";
        cin >> str;

        statement *ch = head;
        bool found = false;

        // Find the statement to delete
        while (ch != nullptr) {
            if (ch->s == str) {
                found = true;
                break;
            }
            ch = ch->next;
        }

        if (!found) {
            cout << "String not found!" << endl;
            return;
        }

        // Handle deletion
        if (ch == head && ch == tail) {  // Only one element
            head = tail = nullptr;
        } else if (ch == head) {  // Deleting the head
            head = head->next;
            head->prev = nullptr;
        } else if (ch == tail) {  // Deleting the tail
            tail = tail->prev;
            tail->next = nullptr;
        } else {  // Deleting in between
            ch->prev->next = ch->next;
            ch->next->prev = ch->prev;
        }

        delete ch;
        cout << "String deleted successfully!" << endl;
    }

    // Search for a string in the text editor
    void searchstr() {
        string str;
        cout << "Enter String to search: ";
        cin >> str;

        statement *ch = head;
        bool found = false;

        while (ch != nullptr) {
            if (ch->s == str) {
                found = true;
                break;
            }
            ch = ch->next;
        }

        if (found) {
            cout << "String found in the editor!" << endl;
        } else {
            cout << "String not found!" << endl;
        }
    }
};

int main() {
    wordprocessor editor;
    int choice = 1;

    while (choice != 0) {
        cout << "\nText Editor Menu:\n";
        cout << "1 - Add text\n";
        cout << "2 - Delete text\n";
        cout << "3 - Display text (Forward)\n";
        cout << "4 - Display text (Reverse)\n";
        cout << "5 - Search for text\n";
        cout << "0 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                editor.adddata();
                break;
            case 2:
                editor.deletestr();
                break;
            case 3:
                editor.displayforward();
                break;
            case 4:
                editor.displayrev();
                break;
            case 5:
                editor.searchstr();
                break;
            case 0:
                cout << "Exiting the editor..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
