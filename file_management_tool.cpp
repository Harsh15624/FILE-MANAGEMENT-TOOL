// FILE MANAGEMENT TOOL
// Developed for Internship at CodTech
// Showcases basic file-handling: Read, Write, Append

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to write data (overwrites file)
void writeToFile(const string& filename) {
    ofstream file(filename); // overwrite mode
    if (file.is_open()) {
        string data;
        cout << "Enter data to WRITE to file (end with '~'):\n";
        char ch;
        cin.ignore();
        while (cin.get(ch) && ch != '~') {
            file.put(ch);
        }
        file.close();
        cout << "Data written successfully.\n";
    } else {
        cout << "Error opening file for writing.\n";
    }
}

// Function to append data
void appendToFile(const string& filename) {
    ofstream file(filename, ios::app); // append mode
    if (file.is_open()) {
        string data;
        cout << "Enter data to APPEND to file (end with '~'):\n";
        char ch;
        cin.ignore();
        while (cin.get(ch) && ch != '~') {
            file.put(ch);
        }
        file.close();
        cout << "Data appended successfully.\n";
    } else {
        cout << "Error opening file for appending.\n";
    }
}

// Function to read file
void readFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        cout << "\n--- File Contents ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error opening file for reading.\n";
    }
}

int main() {
    string filename;
    int choice;

    cout << "=== FILE MANAGEMENT TOOL ===\n";
    cout << "Enter file name (with .txt): ";
    cin >> filename;

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Write to File (overwrite)\n";
        cout << "2. Append to File\n";
        cout << "3. Read from File\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: writeToFile(filename); break;
            case 2: appendToFile(filename); break;
            case 3: readFromFile(filename); break;
            case 4: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
