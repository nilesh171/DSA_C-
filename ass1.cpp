#include <iostream>
using namespace std;

class student {
    public:
        int rno;
        float sgpa;
        char name[10];

        void getinput() {
            cout << "Enter Name of Student: ";
            cin >> name;
            cout << "Enter Roll No: ";
            cin >> rno;
            cout << "Enter SGPA: ";
            cin >> sgpa;
        }

        void display() {
            cout << "Name: " << name << ", Roll No: " << rno << ", SGPA: " << sgpa << endl;
        }
};

// (a) Insertion Sort to sort by Roll No
void insertionSortByRollNo(student s[], int n) {
    for (int i = 1; i < n; i++) {
        student key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].rno > key.rno) {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;
    }
}

// Helper function to compare names without using strcmp
int compareNames(char name1[], char name2[]) {
    for (int i = 0; i < 10; i++) {
        if (name1[i] != name2[i]) {
            return name1[i] - name2[i];
        }
        if (name1[i] == '\0') {
            break;
        }
    }
    return 0;
}

// (b) Shell Sort to sort by Name
void shellSortByName(student s[], int n) {
    int interval = n / 2;
    while (interval >= 1) {
        for (int i = interval; i < n; i++) {
            student temp = s[i];
            int j = i;
            while (j >= interval && compareNames(s[j - interval].name, temp.name) > 0) {
                s[j] = s[j - interval];
                j -= interval;
            }
            s[j] = temp;
        }
        interval /= 2;
    }
}

// (c) Counting Sort for SGPA (floating-point values)
void countingSortBySGPA(student s[], int n, float minSGPA, float maxSGPA) {
    int range = 100;  // Assuming SGPA is in range [0.00, 10.00], scale by 10.
    int count[range] = {0};
    student output[n];

    // Count the frequency of each SGPA scaled by 10
    for (int i = 0; i < n; i++) {
        int scaledSGPA = (s[i].sgpa - minSGPA) * 10;
        count[scaledSGPA]++;
    }

    // Cumulative count
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int scaledSGPA = (s[i].sgpa - minSGPA) * 10;
        output[count[scaledSGPA] - 1] = s[i];
        count[scaledSGPA]--;
    }

    // Copy the output array to the original array
    for (int i = 0; i < n; i++) {
        s[i] = output[i];
    }
}

void sortAndDisplayTop10BySGPA(student s[], int n) {
    // Find the minimum and maximum SGPA
    float minSGPA = s[0].sgpa, maxSGPA = s[0].sgpa;
    for (int i = 1; i < n; i++) {
        if (s[i].sgpa < minSGPA) minSGPA = s[i].sgpa;
        if (s[i].sgpa > maxSGPA) maxSGPA = s[i].sgpa;
    }

    // Sort using counting sort for floating-point SGPA
    countingSortBySGPA(s, n, minSGPA, maxSGPA);

    
    cout << "\nTop 10 Students by SGPA:\n";
    for (int i = n - 1; i >= n - 10 && i >= 0; i--) {
        s[i].display();
    }
}

int main() {
    int n;
    cout << "Enter Total No of Students: ";
    cin >> n;

    student s[n];

    
    for (int i = 0; i < n; i++) {
        s[i].getinput();
    }


    cout << "\nSorted by Roll Number (Ascending Order):\n";
    insertionSortByRollNo(s, n);
    for (int i = 0; i < n; i++) {
        s[i].display();
    }

    cout << "\nSorted by Name (Alphabetical Order):\n";
    shellSortByName(s, n);
    for (int i = 0; i < n; i++) {
        s[i].display();
    }

    sortAndDisplayTop10BySGPA(s, n);

    return 0;
}
