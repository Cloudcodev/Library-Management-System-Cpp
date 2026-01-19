/*Project: Library Management System
 * Description: Console-based application to manage book inventory.
 * Features:
 * - Add, List, Search, Delete Books.
 * - File persistence: Saves data to "library_data.txt" automatically.
 * Concepts: File I/O (fstream), Vectors, Structs, and Standard Loops.
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream> // adding header for file handling

using namespace std;

// represents a single book entity with details
struct Book {
    int id;
    string title;
    string author;
    string isbn;
};

// dynamic array to store books in memory during runtime
vector<Book> library;
const string FILENAME = "library_data.txt"; // the file where data lives

void displayMenu();
void addBook();
void listBooks();
void searchBook();
void deleteBook(); 
void saveToFile();  
void loadFromFile(); 

int main() {
    loadFromFile(); //loading existing data immediately when program starts
    int choice;
    
    do {
        displayMenu();
        // keeps looping until user enters the right number.
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
                cin.clear(); // reset the error flag on cin
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
                deleteBook(); 
                break;       
            case 5:
                saveToFile(); //saving data before exiting
                cout << "Exiting system.\n" << endl;
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
    cout << "5. Save & Exit" << endl; //updated line
}

void addBook() {
    Book newBook;
    cout << "\nEnter Book ID: ";
    
    while (!(cin >> newBook.id)) {
        cout << "Invalid ID. Please enter a number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    
    cin.ignore(); // clearing buffer

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
    // loop to traverse the library vector efficiently
    for (int i = 0; i < library.size(); i++) {
        if (library[i].id == searchID) {
            cout << "\nBook Found:\n";
            cout << "ID: " << library[i].id << " | Title: " << library[i].title << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book with ID " << searchID << " not found.\n" << endl;
    }
}

void deleteBook() {
    int deleteID;
    cout << "\nEnter Book ID to delete: ";
    cin >> deleteID;
    
    bool found = false;
    
    for (int i = 0; i < library.size(); i++) {
        if (library[i].id == deleteID) {
            library.erase(library.begin() + i); // deleting the book at position i
            cout << "Book with ID '" << deleteID << "' has been deleted.\n" << endl;
            found = true;
            break; // stopping the loop when found and deleted
        }
    }
    if (!found) {
        cout << "Book with ID " << deleteID << " not found." << endl;
    }
}

// saves all books to a text file
void saveToFile() {
    ofstream outFile(FILENAME); // opens file for writing
    
    if (outFile.is_open()) {
        for (int i = 0; i < library.size(); i++) {
            //writing each property using the index
            outFile << library[i].id << endl;
            outFile << library[i].title << endl;
            outFile << library[i].author << endl;
            outFile << library[i].isbn << endl;
        }
        outFile.close();
        cout << "Data saved successfully to " << FILENAME << endl;
    } else {
        cout << "Error: Could not save data!" << endl;
    }
}

// loads books from the text file into memory
void loadFromFile() {
    ifstream inFile(FILENAME); // opens file for reading
    if (!inFile) {
        return; // if file doesn't exist, return
    }

    Book book;
    // Keep reading as long as we find a Book ID
    while (inFile >> book.id) {
        inFile.ignore(); // skip the newline character after the ID
        getline(inFile, book.title);
        getline(inFile, book.author);
        getline(inFile, book.isbn);
        library.push_back(book); // adding the loaded book to our list
    }
    inFile.close();
    cout << "Data loaded from file. " << library.size() << " books found.\n";
}