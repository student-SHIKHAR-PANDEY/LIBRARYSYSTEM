#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "book.h"
#include "user.h"

using namespace std;

// Load books from file
void loadBooks(vector<Book>& library) {
    ifstream infile("books.txt");
    if (!infile) return;

    while (!infile.eof()) {
        Book b;
        b.loadFromFile(infile);
        if (infile) library.push_back(b);
    }

    infile.close();
}

// Save books to file
void saveBooks(const vector<Book>& library) {
    ofstream outfile("books.txt");
    for (const auto& b : library) {
        b.saveToFile(outfile);
    }
    outfile.close();
}

int main() {
    vector<Book> library;
    loadBooks(library);

    // Step 1: Hardcoded users
    User admin("Admin", 1, "admin", "admin", "admin123");
    User user1("User1", 2, "user", "user1", "user123");

    // Step 2: Login
    string username, password;
    cout << "===== Login =====\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    User currentUser;
    bool isLoggedIn = false;

    if (admin.verifyLogin(username, password)) {
        currentUser = admin;
        isLoggedIn = true;
    } else if (user1.verifyLogin(username, password)) {
        currentUser = user1;
        isLoggedIn = true;
    } else {
        cout << "❌ Login failed. Exiting...\n";
        return 0;
    }

    cout << "✅ Logged in as: " << currentUser.getRole() << "\n";

    int choice;
    while (true) {
        cout << "\n===== Library Menu =====\n";
        if (currentUser.getRole() == "admin") {
            cout << "1. Add Book\n";
        }
        cout << "2. View All Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Adjust admin/user menu logic
        if (choice == 1 && currentUser.getRole() == "admin") {
            string title, author, isbn;
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author name: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            getline(cin, isbn);

            Book newBook(title, author, isbn);
            library.push_back(newBook);
            saveBooks(library);
            cout << "✅ Book added successfully.\n";

        } else if (choice == 2 || (choice == 1 && currentUser.getRole() != "admin")) {
            if (choice == 1 && currentUser.getRole() != "admin") {
                cout << "❌ Access denied. Only admins can add books.\n";
                continue;
            }
            if (library.empty()) {
                cout << "⚠️ No books in library.\n";
            } else {
                for (int i = 0; i < library.size(); ++i) {
                    cout << "\nBook " << i + 1 << ":\n";
                    library[i].display();
                }
            }

        } else if (choice == 3) {
            int index;
            cout << "Enter book number to borrow: ";
            cin >> index;
            if (index >= 1 && index <= library.size()) {  
                if (library[index - 1].available()) {
                    library[index - 1].markBorrowed();
                    saveBooks(library);
                    cout << "📕 Book borrowed.\n";
                } else {
                    cout << "🚫 Book already borrowed.\n";
                }
            } else {
                cout << "❌ Invalid book number.\n";
            }

        } else if (choice == 4) {
            int index;
            cout << "Enter book number to return: ";
            cin >> index;
            if (index >= 1 && index <= library.size()) {
                if (!library[index - 1].available()) {
                    library[index - 1].markReturned();
                    saveBooks(library);
                    cout << "📗 Book returned.\n";
                } else {
                    cout << "⚠️ Book was not borrowed.\n";
                }
            } else {
                cout << "❌ Invalid book number.\n";
            }

        } else if (choice == 5) {
            cout << "👋 Exiting...\n";
            break;
        } else {
            cout << "❌ Invalid choice. Try again.\n";
        }
    }

    return 0;
}
