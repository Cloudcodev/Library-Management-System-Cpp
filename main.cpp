/*Description: Console-based application to manage book inventory.
 Uses C++ vectors for dynamic storage and basic input validation.*/

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

vector<Book> library;//dynamic array to store books in memory during runtime

void displayMenu();
void addBook();
void listBooks();

int main() {
    int choice;
    
    do {
        displayMenu();
        // Keeps looping until user enters 1, 2, or 3.
        while (true) {
            cout << "Enter your choice: ";
            if (cin >> choice) {
                if (choice >= 1 && choice <= 3) {
                    break;
                } else {
                    cout << "Invalid option. Please choose: \n1. Add New Book \n2. List All Books \n3. Exit" << endl;
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
                cout << "Exiting system..." << endl; 
                break;
        }
    } while (choice != 3);

    return 0;
}

void displayMenu() {
    cout << "Library Management System" << endl;
    cout << "1. Add New Book" << endl;
    cout << "2. List All Books" << endl;
    cout << "3. Exit" << endl;
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
    cout << "\nThe book '" << newBook.title << "' is added successfully to the library!" << endl;
}

void listBooks() {
    if (library.empty()) {
        cout << "\nLibrary is empty. Add a book first!" << endl;
        return;
    }

    cout << "\nCurrent Inventory:\n " << endl;
    for (int i = 0; i < library.size(); i++) {
    cout << "Book ID: " << library[i].id << endl;
    cout << "Book title: " << library[i].title << endl;
    cout << "Author: " << library[i].author << endl;
    cout << "ISBN: " << library[i].isbn <<endl;
    cout << endl;
    }
}
