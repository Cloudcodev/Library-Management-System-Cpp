/* Project: Library Management System
 * Description: A console-based application to manage book inventory.
 * Features:
 * - Add new books (ID, Title, Author, ISBN)
 * - List all books in the database
 * - Search for a book by unique ID
 * - Delete a book record by ID
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Represents a single book entity with details
struct Book {
    int id;
    string title;
    string author;
    string isbn;
};

// Dynamic array to store books in memory during runtime
vector<Book> library;

void displayMenu();
void addBook();
void listBooks();
void searchBook();
void deleteBook(); // Adding delete function

int main() {
    int choice;
    
    do {
        displayMenu();
        // Keeps looping until user enters the right number.
        while (true) {
            cout << "Enter your choice: ";
            if (cin >> choice) {
                if (choice >= 1 && choice <= 5) {
                    break;
                } else {
                    cout << "Invalid option. Please choose 1-5." << endl;
                }
            } else {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear(); // Reset the error flag on cin
                cin.ignore(10000, '\n');  
            }
        }

        switch (choice) {
            case 1: 
                addBook();
                break;
            case 2: 
                listBooks();
                break;
            case 3: 
                searchBook(); 
                break;
            case 4:
                deleteBook(); // New case
                break;       
            case 5:
                cout << "Exiting system...\n" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\nLibrary Management System " << endl;
    cout << "1. Add New Book" << endl;
    cout << "2. List All Books" << endl;
    cout << "3. Search Book by ID" << endl;
    cout << "4. Delete Book" << endl; 
    cout << "5. Exit" << endl;
}

void addBook() {
    Book newBook;
    cout << "\nEnter Book ID: ";
    
    while (!(cin >> newBook.id)) {
        cout << "Invalid ID. Please enter a number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    
    cin.ignore(); // Clearing buffer

    cout << "Enter Book Title: ";
    getline(cin, newBook.title);

    cout << "Enter Author Name: ";
    getline(cin, newBook.author);

    cout << "Enter ISBN: ";
    getline(cin, newBook.isbn);

    library.push_back(newBook);
    cout << "\nThe book '" << newBook.title << "' is added successfully to the library!" << endl;
}

void listBooks() {
    if (library.empty()) {
        cout << "\nLibrary is empty. Add a book first!" << endl;
        return;
    }

    cout << "\nCurrent Inventory:\n " << endl;
    for (int i = 0; i < library.size(); i++) {
        cout << "Book ID: " << library[i].id 
             << " | Title: " << library[i].title 
             << " | Author: " << library[i].author 
             << " | ISBN: " << library[i].isbn << endl;
    }
}

void searchBook() {
    int searchID;
    cout << "\nEnter Book ID to search: ";
    cin >> searchID;
    
    bool found = false;
    // Loop to traverse the library vector efficiently
    for (const auto& book : library) {
        if (book.id == searchID) {
            cout << "\nBook found!" << endl;
            cout << "ID: " << book.id << endl;
            cout << "Title: " << book.title << endl;
            cout << "ISBN: " << book.isbn << endl;
            cout << "-------------------------" << endl;
            found = true;
            break; // Exit loop immediately once found
        }
    }
    if (!found) {
        cout << "Book with ID " << searchID << " not found.\n" << endl;
    }
}

// Added new function
void deleteBook() {
    int deleteID;
    cout << "\nEnter Book ID to delete: ";
    cin >> deleteID;
    
    bool found = false;
    
    for (int i = 0; i < library.size(); i++) {
        if (library[i].id == deleteID) {
            library.erase(library.begin() + i); // Deleting the book at position i
            cout << "Book with ID '" << deleteID << "' has been deleted.\n" << endl;
            found = true;
            break; // Stopping the loop when found and deleted
        }
    }
    if (!found) {
        cout << "Book with ID " << deleteID << " not found.\n" << endl;
    }
}