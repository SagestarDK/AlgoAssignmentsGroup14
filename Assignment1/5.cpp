#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

// ----- Book -----
struct Book {
    int id;
    int category;
    bool borrowed;
    Book(int id, int category) : id(id), category(category), borrowed(false) {}
};

// ----- Library -----
class Library {
private:
    vector<Book> books;          // the only container
    int findIndexById(int id) const;  // returns index or -1

public:
    bool addBook(int id, int category);
    bool borrowBook(int id);
    bool returnBook(int id);
    void displayAvailableBooks() const;
    void displayBorrowedBooks() const;
    int  countBooksInCategory(int category) const;
};

// ----- Skeleton definitions (TODO: implement logic) -----
int Library::findIndexById(int id) const {
    // TODO: linear scan over 'books'; return index if books[i].id==id, else -1
     for (size_t i = 0; i < books.size(); ++i) {
        if (books[i].id == id) {
            return static_cast<int>(i);
        }
    }
    return -1; // not found
}

bool Library::addBook(int id, int category) {
    // TODO: if id not present (findIndexById==-1) -> books.push_back({id,category}); return true
    // else return false
    return false;
}

bool Library::borrowBook(int id) {
    // TODO: if found and not borrowed -> set borrowed=true; return true; else false
    return false;
}

bool Library::returnBook(int id) {
    // TODO: if found and borrowed -> set borrowed=false; return true; else false
    return false;
}

void Library::displayAvailableBooks() const {
    // TODO: iterate 'books' and print those with borrowed==false
}

void Library::displayBorrowedBooks() const {
    // TODO: iterate 'books' and print those with borrowed==true
}

int Library::countBooksInCategory(int category) const {
    // TODO: iterate 'books' and count where b.category==category; return count
    return 0;
}


int main() {
    Library myLibrary;

    // Adding books to the library (mirrors the starter main in the image)
    myLibrary.addBook(1, 3);   // Book ID: 1, Category: 3
    myLibrary.addBook(2, 7);   // Book ID: 2, Category: 7
    myLibrary.addBook(3, 3);   // Book ID: 3, Category: 3
    myLibrary.addBook(4, 15);  // Book ID: 4, Category: 15
    myLibrary.addBook(5, 3);   // Book ID: 5, Category: 3  (Warning should trigger here)
    myLibrary.addBook(6, 0);   // Book ID: 6, Category: 0

    cout << "\nAll books in the library (available first):\n";
    cout << "Available books:\n";
    myLibrary.displayAvailableBooks();

    // Borrow a book by ID
    cout << "\nAttempting to borrow Book ID 2:\n";
    if (myLibrary.borrowBook(2)) {
        cout << "Book_ID_2_borrowed_successfully.\n";
    } else {
        cout << "Failed_to_borrow_Book_ID_2.\n";
    }

    // Attempt to borrow the same book again
    cout << "\nAttempting to borrow Book ID 2 again:\n";
    if (myLibrary.borrowBook(2)) {
        cout << "Book_ID_2_borrowed_successfully.\n";
    } else {
        cout << "Failed_to_borrow_Book_ID_2.\n";
    }

    // Display borrowed books
    cout << "\nBorrowed books in the library:\n";
    myLibrary.displayBorrowedBooks();

    // Return a borrowed book by ID
    cout << "\nReturning Book ID 2:\n";
    if (myLibrary.returnBook(2)) {
        cout << "Book_ID_2_returned_successfully.\n";
    } else {
        cout << "Failed_to_return_Book_ID_2.\n";
    }

    // Display available books after returning
    cout << "\nAvailable books after returning Book ID 2:\n";
    myLibrary.displayAvailableBooks();

    // Count the number of books in a specific category
    int categoryToCheck = 3;
    cout << "\nNumber_of_books_in_category_" << categoryToCheck << ": "
         << myLibrary.countBooksInCategory(categoryToCheck) << '\n';

    return 0;
}