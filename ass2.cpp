//Name - Nilesh Jivan Sonawane
//Roll No - FY23M270
//PRN- 123B1B270
//Assignment No - 2
//Consider Employee database of PCCOE (at least 20 records). Database contains different fields of every employee like EMP-ID, EMP-Name and EMP-Salary. a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort b. Arrange list of Employee alphabetically using Merge Sort.
#include <iostream>
using namespace std;

class employee {
    int id;
    string name;
    int salary;

public:
    void getdata() {
        cout << "Enter Id of Employee: ";
        cin >> id;
        cout << "Enter Name of Employee: ";
        cin >> name;
        cout << "Enter Salary of Employee: ";
        cin >> salary;
    }

    void display() {
        cout << "Employee Id: " << id << endl;
        cout << "Name of Employee: " << name << endl;
        cout << "Salary of Employee: Rs " << salary << endl;
    }

    friend void mergesort(employee arr[], int left, int right);
    friend void merge(employee arr[], int left, int mid, int right);
    friend int partition(employee arr[], int low, int high);
    friend void quickSort(employee arr[], int low, int high);
};

// Function to merge two subarrays
void merge(employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    employee L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].name <= R[j].name) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort Function
void mergesort(employee arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Partition function for Quick Sort
int partition(employee arr[], int low, int high) {
    int pivot = arr[high].id; // Pivot is the last element
    int i = (low - 1); // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j].id < pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quick Sort Function
void quickSort(employee arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1); // Recursively sort elements before partition
        quickSort(arr, pi + 1, high); // Recursively sort elements after partition
    }
}

int main() {
    int n;
    cout << "Enter Total No of Employees: ";
    cin >> n;
    employee arr[n];

    // Input employee data
    for (int i = 0; i < n; i++) {
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Enter Details of Employee " << i + 1 << endl;
        arr[i].getdata();
    }

    // Sort employees by EMP-ID using Quick Sort
    quickSort(arr, 0, n - 1);
    cout << "\nEmployees sorted by EMP-ID:\n";
    for (int i = 0; i < n; i++) {
        cout << "--------------------------------------------------------------------" << endl;
        arr[i].display();
    }

    // Sort employees by Name using Merge Sort
    mergesort(arr, 0, n - 1);
    cout << "\nEmployees sorted by Name:\n";
    for (int i = 0; i < n; i++) {
        cout << "--------------------------------------------------------------------" << endl;
        arr[i].display();
    }

    return 0;
}
