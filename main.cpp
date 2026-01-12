/* Project: Library Management System
 * Description: Console-based application to manage book inventory.
 * Features: Add Books, List All, and Search by ID.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//represents a single book entity with details
struct Book {
    int id;
    string title;
    string author;
    string isbn;
};
//dynamic array to store books in memory during runtime
vector<Book> library;

void displayMenu();
void addBook();
void listBooks();
void searchBook(); //new function

int main() {
    int choice;
    
    do {
        displayMenu();
        // Keeps looping until user enters the right number
        while (true) {
            cout << "Enter your choice: ";
            if (cin >> choice) {
                if (choice >= 1 && choice <= 4) {
                    break;
                } else {
                    cout << "Invalid option. Please choose: \n1. Add New Book \n2. List All Books \n3. Search for book \n4. Exit" << endl;
                }
            } else {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();//reset the error flag on cin             
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
                searchBook(); // new case
                break;
            case 4: 
                cout << "Exiting the system." << endl; 
                break;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    cout << "Library Management System" << endl;
    cout << "1. Add New Book" << endl;
    cout << "2. List All Books" << endl;
    cout << "3. Search Book by ID" << endl;
    cout << "4. Exit" << endl;
}

void addBook() {
    Book newBook;
    cout << "\nEnter Book ID: ";
    
    while (!(cin >> newBook.id)) {
        cout << "Invalid ID. Please enter a number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    
    cin.ignore(); //clearing buffer

    cout << "Enter Book Title: ";
    getline(cin, newBook.title);

    cout << "Enter Author Name: ";
    getline(cin, newBook.author);

    cout << "Enter ISBN: ";
    getline(cin, newBook.isbn);

    library.push_back(newBook);
    cout << "Book is added successfully to the library!\n" << endl;
}

void listBooks() {
    if (library.empty()) {
        cout << "\nLibrary is empty. Add a book first!" << endl;
        return;
    }

    cout << "\nCurrent Inventory:\n " << endl;
    for (int i = 0; i < library.size(); i++) {
    cout << "Book ID: " << library[i].id 
        << " | title: " << library[i].title 
        << " | Author: " << library[i].author 
        << " | ISBN: " << library[i].isbn <<endl;
    cout << endl;
    }
}
// Performs a linear search to find a specific book by its ID
void searchBook() {
    int searchID;
    cout << "\nEnter Book ID to search: ";
    cin >> searchID;

    bool found = false;
    //loop to traverse the library vector efficiently
    for (const auto& book : library) {
        if (book.id == searchID) {
            cout << "Book Found!" << endl;
            cout << "ID: " << book.id << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "ISBN: " << book.isbn << endl;
            cout << "-------------------------" << endl;
            found = true;
            break; //Exit loop immediately once found to save processing time
        }
    }
    //handle the edge case where the ID does not exist
    if (!found) {
        cout << "Book with ID " << searchID << " not found.\n" << endl;
    }
}