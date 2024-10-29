//Name - Nilesh Jivan Sonawane
//Roll No - FY23M270
//PRN- 123B1B270
//Assignment No - 10
#include <iostream>
using namespace std;

class Job {
    string jobid;
    int jobpriority;
public:
    void adddata() {
        cout << "Enter Job id: ";
        cin >> jobid;
        cout << "Enter Job priority: ";
        cin >> jobpriority;
    }

    void display() {
        cout << "Job Id: " << jobid << " Job Priority: " << jobpriority << endl;
    }

    string getJobId() {
        return jobid;
    }

    friend class JobScheduled;
};

class JobScheduled {
    Job q[10];
    int front, rear;
public:
    JobScheduled() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (front == (rear + 1) % 10);
    }

    void insertAtRear() {
        if (isFull()) {
            cout << "No more Job can be added!" << endl;
            return;
        }
        rear = (rear + 1) % 10;
        q[rear].adddata();
        if (front == -1) {
            front = 0;
        }
    }

    void insertAtFront() {
        if (isFull()) {
            cout << "No more Job can be added!" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = 9;
        } else {
            front = front - 1;
        }
        q[front].adddata();
    }

    void deleteAtRear() {
        if (isEmpty()) {
            cout << "No Job is present." << endl;
            return;
        }
        q[rear].display();
        cout << "is Deleted!" << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = 9;
        } else {
            rear = rear - 1;
        }
    }

    void deleteAtFront() {
        if (isEmpty()) {
            cout << "No Job is present." << endl;
            return;
        }
        q[front].display();
        cout << "is Deleted!" << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % 10;
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "No jobs to display." << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            q[i].display();
            i = (i + 1) % 10;
        }
        q[i].display();
    }

    void searchJob(string jobid) {
        if (isEmpty()) {
            cout << "No Job is present in the queue." << endl;
            return;
        }
        int i = front;
        bool found = false;
        while (i != rear) {
            if (q[i].getJobId() == jobid) {
                q[i].display();
                found = true;
                break;
            }
            i = (i + 1) % 10;
        }
        if (q[i].getJobId() == jobid) {
            q[i].display();
            found = true;
        }
        if (!found) {
            cout << "Job with id " << jobid << " not found." << endl;
        }
    }
};

int main() {
    JobScheduled s;
    int n = 1;

    while (n != 0) {
        cout << "Enter 1 to add Job (at Front) \n";
        cout << "Enter 2 to add Job (at Rear) \n";
        cout << "Enter 3 to Delete Job from Front \n";
        cout << "Enter 4 to Delete Job from Rear \n";
        cout << "Enter 5 to Display all Jobs \n";
        cout << "Enter 6 to Search for a Job by ID \n";
        cout << "Enter 0 to Exit \n";
        cin >> n;

        if (n == 1) {
            s.insertAtFront();
        } else if (n == 2) {
            s.insertAtRear();
        } else if (n == 3) {
            s.deleteAtFront();
        } else if (n == 4) {
            s.deleteAtRear();
        } else if (n == 5) {
            s.displayQueue();
        } else if (n == 6) {
            string jobid;
            cout << "Enter Job ID to search: ";
            cin >> jobid;
            s.searchJob(jobid);
        } else {
            n = 0;
        }
    }

    return 0;
}
