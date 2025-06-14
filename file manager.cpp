#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>   // for remove()

using namespace std;

void createFile() {
    string filename;
    cout << "Enter file name to create: ";
    cin >> filename;

    ofstream file(filename.c_str());
    if (file) {
        cout << "File '" << filename << "' created successfully.\n";
    } else {
        cout << "Failed to create file.\n";
    }
    file.close();
}

void readFile() {
    string filename, line;
    cout << "Enter file name to read: ";
    cin >> filename;

    ifstream file(filename.c_str());
    if (file) {
        cout << "\n--- File Content ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
    } else {
        cout << "File not found.\n";
    }
    file.close();
}

void updateFile() {
    string filename, data;
    cout << "Enter file name to update (append): ";
    cin >> filename;
    cin.ignore();  // clear newline from input buffer

    ofstream file(filename.c_str(), ios::app);
    if (file) {
        cout << "Enter data to append: ";
        getline(cin, data);
        file << data << endl;
        cout << "Data appended successfully.\n";
    } else {
        cout << "File not found.\n";
    }
    file.close();
}

void deleteFile() {
    string filename;
    cout << "Enter file name to delete: ";
    cin >> filename;

    if (remove(filename.c_str()) == 0) {
        cout << "File '" << filename << "' deleted successfully.\n";
    } else {
        cout << "File not found or unable to delete.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n=== File Management Tool ===\n";
        cout << "1. Create File\n";
        cout << "2. Read File\n";
        cout << "3. Update File (Append)\n";
        cout << "4. Delete File\n";
        cout << "5. Exit\n";
        cout << "Choose an option (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: createFile(); break;
            case 2: readFile(); break;
            case 3: updateFile(); break;
            case 4: deleteFile(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
