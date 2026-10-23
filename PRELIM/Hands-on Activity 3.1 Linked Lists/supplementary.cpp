#include <iostream>
#include <string>

struct SongNode {
    std::string title;
    SongNode* next;
    SongNode* prev;

    SongNode(std::string name) {
        title = name;
        next = NULL;
        prev = NULL;
    }
};

class Playlist {
private:
    SongNode* head;
    SongNode* current;

public:
    Playlist() {
        head = NULL;
        current = NULL;
    }

    void addSong(std::string title) {
        SongNode* newSong = new SongNode(title);

        if (head == NULL) {
            head = newSong;
            head->next = head;
            head->prev = head;
            current = head;
            std::cout << "\"" << title << "\" added as the first song.\n";
            return;
        }

        SongNode* tail = head->prev;

        tail->next = newSong;
        newSong->prev = tail;
        newSong->next = head;
        head->prev = newSong;

        std::cout << "\"" << title << "\" added to the playlist.\n";
    }

    void removeSong(std::string title) {
        if (head == NULL) {
            std::cout << "Playlist is empty! Cannot remove.\n";
            return;
        }

        SongNode* temp = head;
        bool found = false;

        do {
            if (temp->title == title) {
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != head);

        if (!found) {
            std::cout << "Song \"" << title << "\" not found in playlist.\n";
            return;
        }

        if (temp->next == temp) {
            delete temp;
            head = NULL;
            current = NULL;
            std::cout << "Removed \"" << title << "\". Playlist is now empty.\n";
            return;
        }

        if (temp == head) {
            head = head->next;
        }

        if (temp == current) {
            current = current->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        std::cout << "Successfully removed \"" << title << "\".\n";
    }

    void playNext() {
        if (current == NULL) {
            std::cout << "Playlist is empty.\n";
            return;
        }
        current = current->next;
        std::cout << "Now Playing: " << current->title << "\n";
    }

    void playPrev() {
        if (current == NULL) {
            std::cout << "Playlist is empty.\n";
            return;
        }
        current = current->prev;
        std::cout << "Now Playing: " << current->title << "\n";
    }

    void playAll() {
        if (head == NULL) {
            std::cout << "Playlist is empty.\n";
            return;
        }

        std::cout << "\n--- Playlist Songs ---\n";
        SongNode* temp = head;
        int trackNum = 1;

        do {
            std::cout << trackNum << ". " << temp->title;
            if (temp == current) {
                std::cout << "  <-- [Currently Selected]";
            }
            std::cout << "\n";
            temp = temp->next;
            trackNum++;
        } while (temp != head);
        
        std::cout << "-----------------------\n";
    }
};

int main() {
    Playlist myPlaylist;
    int choice;
    std::string songTitle;

    myPlaylist.addSong("Take it to the Limit");
    myPlaylist.addSong("Open Arms");
    myPlaylist.addSong("Don't Stop Belivin'");

    while (true) {
        std::cout << "\n===============================\n";
        std::cout << "   VibeCheck  \n";
        std::cout << "===============================\n";
        std::cout << "1. Add Song\n";
        std::cout << "2. Remove Song\n";
        std::cout << "3. Next Song\n";
        std::cout << "4. Previous Song\n";
        std::cout << "5. Display All Songs\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
            case 1:
                std::cout << "Enter song title: ";
                std::getline(std::cin, songTitle);
                myPlaylist.addSong(songTitle);
                break;
            case 2:
                std::cout << "Enter song title to remove: ";
                std::getline(std::cin, songTitle);
                myPlaylist.removeSong(songTitle);
                break;
            case 3:
                myPlaylist.playNext();
                break;
            case 4:
                myPlaylist.playPrev();
                break;
            case 5:
                myPlaylist.playAll();
                break;
            case 6:
                std::cout << "Exiting music player...\n";
                return 0;
            default:
                std::cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}