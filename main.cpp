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

vector<Book> library; //dynamic array to store books in memory during runtime

void displayMenu();
void addBook();
void listBooks();

int main() {
    int choice;
    cout <<"Library System Initialized..." << endl; 
    
    //loop keeps program running until user exits
    do {
        displayMenu();
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number: " << endl;
            cin.clear(); //reset the error flag on cin
            cin.ignore(10000,'\n'); 
            continue;
        }

        switch (choice) {
            case 1: 
                addBook();
                break;
            case 2: 
                listBooks();
                break;
            case 3: cout << "Exiting system." << endl; 
                break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}

//displays the main menu options to the console
void displayMenu() {
    cout << "\nLibrary Management System" << endl;
    cout << "1. Add New Book" << endl;
    cout << "2. List All Books" << endl;
    cout << "3. Exit" << endl;
}

//placeholder for adding books
void addBook() {
    cout << "\nAdd Book functionality coming soon." << endl;
}

//placeholder for listing books
void listBooks() {
    cout << "\nList Books functionality coming soon." << endl;
}