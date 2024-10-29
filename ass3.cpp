#include <iostream>
using namespace std;

class song {
    string name, artist;
    float duration;
    song* next;  // Linked list pointer

public:
    song() : next(nullptr) {}  // Initialize next pointer to nullptr

    // Input song details
    void read() {
        cout << "Enter Song Title: ";
        cin >> name;
        cout << "Enter Artist of the Song: ";
        cin >> artist;
        cout << "Enter Duration (in minutes): ";
        cin >> duration;
    }

    // Display song details
    void display() const {
        cout << "---------------------------------------------\n";
        cout << "Song Title: " << name << "\nArtist: " << artist << "\nDuration: " << duration << " minutes\n";
    }

    friend class playlist;  // Allow playlist to access private members
};

class playlist {
    song* head;

public:
    playlist() : head(nullptr) {}  // Initialize head to nullptr

    // Add song at the end, beginning, or at a specific location
    void addsong(int val) {
        if (val == 0) {
            song* nn = new song;
            nn->read();
            nn->next = nullptr;  // Initialize next pointer to nullptr

            if (head == nullptr) {
                head = nn;
            } else {
                song* ch;
                for (ch = head; ch->next != nullptr; ch = ch->next);
                ch->next = nn;
            }
        } else if (val == 1) {
            song* nn = new song;
            nn->read();
            nn->next = head;  // Insert at the beginning
            head = nn;
        } else if (val == 2) {
            int val1, count = 1, i = 1;
            song* nn = new song;
            cout << "Enter location to add song: ";
            cin >> val1;
            
            for (song* ch = head; ch != nullptr; ch = ch->next) { count++; }
            if (val1 <= count) {
                nn->read();
                nn->next = nullptr;

                song* ch = head;
                while (i < val1 - 1) {
                    ch = ch->next;
                    i++;
                }
                nn->next = ch->next;
                ch->next = nn;
            } else {
                cout << "Not enough songs in the playlist.\n";
            }
        }
    }

    // Delete song by title
    void delsong(const string& value) {
        song* cur = head;
        song* pre = nullptr;

        if (head != nullptr && head->name == value) {
            head = head->next;
            delete cur;
            cout << "Song deleted: " << value << endl;
            return;
        }

        while (cur != nullptr && cur->name != value) {
            pre = cur;
            cur = cur->next;
        }

        if (cur == nullptr) {
            cout << "Song not found: " << value << endl;
            return;
        }

        pre->next = cur->next;
        delete cur;
        cout << "Song deleted: " << value << endl;
    }

    // Search and play song
    void searchsong(const string& value) const {
        song* ss = head;
        bool found = false;

        while (ss != nullptr) {
            if (ss->name == value) {
                found = true;
                cout << "Playing song:\n";
                ss->display();
                break;
            }
            ss = ss->next;
        }

        if (!found) {
            cout << "Song not found: " << value << endl;
        }
    }

    // Display the entire playlist
    void displayplaylist() const {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        song* ch = head;
        while (ch != nullptr) {
            ch->display();
            ch = ch->next;
        }
    }
};

int main() {
    playlist pl;
    string name, check;
    int n = 0;

    while (n != 3) {
        cout << "\nEnter an option:\n0 - Add song at end\n1 - Add song at head\n2 - Add song at specific location\n3 - Exit\n";
        cin >> n;
        if (n == 3) break;

        pl.addsong(n);
        cout << "\nCurrent Playlist:\n";
        pl.displayplaylist();
    }

    // Example of searching and playing a specific song
    cout << "\nEnter song to play: ";
    cin >> check;
    pl.searchsong(check);

    // Example of deleting a song from the playlist
    cout << "\nEnter song to delete: ";
    cin >> name;
    pl.delsong(name);

    // Display the updated playlist
    cout << "\nUpdated Playlist:\n";
    pl.displayplaylist();

    return 0;
}
