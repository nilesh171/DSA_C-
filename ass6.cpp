//Name - Nilesh Jivan Sonawane
//Roll No - FY23M270
//PRN- 123B1B270
//Assignment No - 6
//Consider two polynomial expressions of any degree. Design solution to perform addition of these two polynomials with suitable data structure and display results.
#include <iostream>
using namespace std;

class node {
public:
	int coeff, power;
	node* next;

	// Constructor to initialize node with coefficient and power
	node() : coeff(0), power(0), next(nullptr) {}

	void read() {
    	cout << "Enter Coefficient of variable: ";
    	cin >> coeff;
    	cout << "Enter Power Of Variable: ";
    	cin >> power;
	}

	void display() {
    	if (coeff == 0) {
        	cout << "0 ";
    	} else if (power == 0) {
        	cout << coeff;
    	} else {
        	cout << coeff << "X^" << power;
        	if (next != nullptr && next->coeff != 0) {
            	cout << " + ";
        	}
    	}
	}

	friend class polynomial;  // Grant access to the polynomial class
};

class polynomial {
	node* head;

public:
	// Constructor initializes head to nullptr
	polynomial() : head(nullptr) {}

	// Function to add a node (term) to the polynomial
	void addnode() {
    	node* nn = new node;
    	nn->read();
    	nn->next = nullptr;
    	if (head == nullptr) {
        	head = nn;
    	} else {
        	node* ch = head;
        	while (ch->next != nullptr) {
            	ch = ch->next;
        	}
        	ch->next = nn;
    	}
	}

	// Function to display the polynomial
	void displaynode() {
    	if (head == nullptr) {
        	cout << "0" << endl;
        	return;
    	}
    	node* nn = head;
    	while (nn != nullptr) {
        	nn->display();
        	nn = nn->next;
    	}
    	cout << endl;
	}

	// Function to add two polynomials
	void addpolynomial(polynomial& s1, polynomial& s2) {
    	node* p1 = s1.head;
    	node* p2 = s2.head;

    	while (p1 != nullptr && p2 != nullptr) {
        	node* nn = new node;
        	if (p1->power > p2->power) {
            	nn->coeff = p1->coeff;
            	nn->power = p1->power;
            	p1 = p1->next;
        	} else if (p1->power < p2->power) {
            	nn->coeff = p2->coeff;
            	nn->power = p2->power;
            	p2 = p2->next;
        	} else {
            	nn->coeff = p1->coeff + p2->coeff;
            	nn->power = p1->power;
            	p1 = p1->next;
            	p2 = p2->next;
        	}
        	nn->next = nullptr;

        	// Insert result into the resulting polynomial
        	if (head == nullptr) {
            	head = nn;
        	} else {
            	node* ch = head;
            	while (ch->next != nullptr) {
                	ch = ch->next;
            	}
            	ch->next = nn;
        	}
    	}

    	// If there are remaining terms in either polynomial, add them to the result
    	while (p1 != nullptr) {
        	node* nn = new node;
        	nn->coeff = p1->coeff;
        	nn->power = p1->power;
        	nn->next = nullptr;

        	node* ch = head;
        	while (ch->next != nullptr) {
            	ch = ch->next;
        	}
        	ch->next = nn;
        	p1 = p1->next;
    	}

    	while (p2 != nullptr) {
        	node* nn = new node;
        	nn->coeff = p2->coeff;
        	nn->power = p2->power;
        	nn->next = nullptr;

        	node* ch = head;
        	while (ch->next != nullptr) {
            	ch = ch->next;
        	}
        	ch->next = nn;
        	p2 = p2->next;
    	}
	}
};

int main() {
	polynomial s1, s2, result;

	int n = 1;
	cout << "Enter the first polynomial terms (Enter 0 for exit):" << endl;
	while (n != 0) {
    	s1.addnode();
    	cout << "Enter 0 to stop or 1 to continue: ";
    	cin >> n;
	}

	n = 1;
	cout << "Enter the second polynomial terms (Enter 0 for exit):" << endl;
	while (n != 0) {
    	s2.addnode();
    	cout << "Enter 0 to stop or 1 to continue: ";
    	cin >> n;
	}
	cout<<"---------------------------------------------------------"<<endl;
	cout << "First Polynomial: ";
	s1.displaynode();
	cout<<endl;
	cout << "Second Polynomial: ";
	s2.displaynode();
	cout<<"---------------------------------------------------------"<<endl;
	// Adding the two polynomials
	result.addpolynomial(s1, s2);

	cout << "Resulting Polynomial after addition: ";
	result.displaynode();

	return 0;
}


