#include <iostream>
#include <string>
#include <limits>
#include <cctype>
using namespace std;

// Node class
class Node {
public:
    string title;
    string artist;
    Node* prev;
    Node* next;

    Node(string t, string a) {
        title = t;
        artist = a;
        prev = nullptr;
        next = nullptr;
    }
};

// Music Playlist Manager
class MusicPlaylist {
private:
    Node* head;
    Node* current;

    // Case-insensitive title comparison
    bool sameTitle(const string& a, const string& b) {
        if (a.size() != b.size())
            return false;

        for (size_t i = 0; i < a.size(); i++) {
            if (tolower((unsigned char)a[i]) !=
                tolower((unsigned char)b[i]))
                return false;
        }
        return true;
    }

public:
    MusicPlaylist() {
        head = nullptr;
        current = nullptr;
    }

    // Destructor
    ~MusicPlaylist() {
        Node* q = head;

        while (q != nullptr) {
            Node* p = q;
            q = q->next;
            delete p;
        }
    }

    // 1. Add Song
    void addSong(string title, string artist) {
        Node* p = new Node(title, artist);

        if (head == nullptr) {
            head = p;
            current = p;
        } else {
            Node* q = head;

            while (q->next != nullptr)
                q = q->next;

            q->next = p;
            p->prev = q;
        }

        cout << "Added: \"" << title
             << "\" by " << artist << "\n";
    }

    // 2. Delete Song
    void deleteSong(string title) {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* q = head;

        while (q != nullptr && !sameTitle(q->title, title))
            q = q->next;

        if (q == nullptr) {
            cout << "Song not found in the playlist.\n";
            return;
        }

        if (current == q) {
            if (q->next != nullptr)
                current = q->next;
            else
                current = q->prev;
        }

        if (q->prev == nullptr) {
            head = q->next;

            if (head != nullptr)
                head->prev = nullptr;
        } else if (q->next == nullptr) {
            q->prev->next = nullptr;
        } else {
            q->prev->next = q->next;
            q->next->prev = q->prev;
        }

        cout << "Deleted: \"" << q->title
             << "\" by " << q->artist << "\n";

        delete q;
    }

    // 3. Display Playlist Forward
    void displayPlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* q = head;
        int i = 1;

        cout << "\n--- Playlist (Forward) ---\n";

        while (q != nullptr) {
            cout << i++ << ". " << q->title
                 << " - " << q->artist;

            if (q == current)
                cout << " <-- Current";

            cout << "\n";
            q = q->next;
        }
    }

    // 4. Display Playlist in Reverse
    void displayReverse() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* q = head;
        int count = 1;

        while (q->next != nullptr) {
            q = q->next;
            count++;
        }

        cout << "\n--- Playlist (Reverse) ---\n";

        while (q != nullptr) {
            cout << count-- << ". " << q->title
                 << " - " << q->artist;

            if (q == current)
                cout << " <-- Current";

            cout << "\n";
            q = q->prev;
        }
    }

    // 5. Play Current Song
    void playCurrent() {
        if (current == nullptr) {
            cout << "No song to play. Playlist is empty.\n";
            return;
        }

        cout << "Now Playing: " << current->title
             << " - " << current->artist << "\n";
    }

    // 6. Play Next Song
    void playNext() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        if (current->next == nullptr) {
            cout << "This is the last song. "
                 << "No next song available.\n";
            return;
        }

        current = current->next;
        playCurrent();
    }

    // 7. Play Previous Song
    void playPrevious() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        if (current->prev == nullptr) {
            cout << "This is the first song. "
                 << "No previous song available.\n";
            return;
        }

        current = current->prev;
        playCurrent();
    }

    // 8. Play Complete Playlist
    void playComplete() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* q = current;

        cout << "\n--- Playing Playlist ---\n";

        while (q != nullptr) {
            current = q;
            playCurrent();
            q = q->next;
        }

        cout << "End of playlist.\n";
    }

    // 9. Repeat All Songs
    void repeatAll(int times) {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        for (int r = 1; r <= times; r++) {
            cout << "\n=== Repeat Round " << r
                 << " of " << times << " ===\n";

            Node* q = head;

            while (q != nullptr) {
                current = q;
                playCurrent();
                q = q->next;
            }
        }
    }

    // 10. Show Current Song
    void showCurrent() {
        if (current == nullptr) {
            cout << "No current song. Playlist is empty.\n";
            return;
        }

        cout << "Current Song: " << current->title
             << " - " << current->artist << "\n";

        cout << "Previous: ";

        if (current->prev != nullptr)
            cout << current->prev->title;
        else
            cout << "NULL (First Song)";

        cout << "\nNext: ";

        if (current->next != nullptr)
            cout << current->next->title;
        else
            cout << "NULL (Last Song)";

        cout << "\n";
    }
};

// Main Function
int main() {
    MusicPlaylist list;
    int choice = 0;

    do {
        cout << "\n===== MUSIC PLAYLIST MANAGER =====\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Display Playlist in Reverse\n";
        cout << "5. Play Current Song\n";
        cout << "6. Play Next Song\n";
        cout << "7. Play Previous Song\n";
        cout << "8. Play Complete Playlist\n";
        cout << "9. Repeat All\n";
        cout << "10. Show Current Song\n";
        cout << "11. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            if (cin.eof())
                break;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Enter a number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string title, artist;
        int n;

        switch (choice) {
        case 1:
            cout << "Song Title: ";
            getline(cin, title);

            cout << "Artist Name: ";
            getline(cin, artist);

            list.addSong(title, artist);
            break;

        case 2:
            cout << "Title to delete: ";
            getline(cin, title);

            list.deleteSong(title);
            break;

        case 3:
            list.displayPlaylist();
            break;

        case 4:
            list.displayReverse();
            break;

        case 5:
            list.playCurrent();
            break;

        case 6:
            list.playNext();
            break;

        case 7:
            list.playPrevious();
            break;

        case 8:
            list.playComplete();
            break;

        case 9:
            cout << "Number of repetitions: ";

            if (cin >> n && n > 0) {
                list.repeatAll(n);
            } else {
                cout << "Invalid number.\n";
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;

        case 10:
            list.showCurrent();
            break;

        case 11:
            cout << "Exiting Music Playlist Manager. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 11);

    return 0;
}/* C:\Users\student> cd "c:\Users\student\" ; if ($?) { g++ musicplayer.cpp -o musicplayer } ; if ($?) { .\musicplayer }

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter choice: 1
Song Title: senorita
Artist Name: suba
Added: "senorita" by suba

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter choice: 3

--- Playlist (Forward) ---
1. senorita - suba <-- Current

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter choice: */