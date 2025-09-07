#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <stdio.h>
using namespace std;

// --- Book type ---
struct Book {
    int id;
    int category;           // [0..15]
    bool isBorrowed = false;
    
    // Constructor
    Book(int i, int c) : id(i), category(c), isBorrowed(false) {}
};

// --- Library class ---
class Library {
private:
    // --- Data members ---
    unordered_map<int, Book> booksById; // id -> Book
    unordered_set<int> borrowedIds;     // borrowed ids
    array<int,16> countPerCat{};        // books per category
    int totalBooks = 0;
    int validCats  = 0;

    // --- Helpers ---
    double avgPerValidCat() const {
        if (validCats == 0){
            cout << "No books in shelfes, so no valid categories. \n";
            return 0;
        }
        return totalBooks/validCats;
    }

    void incCategory(int c) {
        //If box is empty, increment valid category by 1 (So box is now valid).
        if (countPerCat[c] == 0){
            validCats++;
        }
        //Add book to box
        countPerCat[c]++;
    }

    void warnIfUnbalanced(int category) {
        if (2 * avgPerValidCat() >= countBooksInCategory(category)){
            cout<<"Warning, too many books on one shelf, so unbalanced library detected!. \n";
        }
    }

    Book* findBook(int id) {
        auto it = booksById.find(id);
        if (it == booksById.end()) {
            return nullptr;
        }
        return &it->second;  // return pointer to the Book
    }



public:
    void addBook(int id, int category) {
        // Validate category logic
        if (category < 0 || category > 15) {
            cout<<"Invalid category, please select a category between 0 and 15. \n";
            return;
        }
            
        if (booksById.find(id) == booksById.end()){
            cout<<"Book is not found, inserting book. \n";
            Book b{ id, category};    // Create book object
            booksById.insert({id,b}); // Add book to the map with all unique books.
            incCategory(category); // Update how many books we have in library shelves and valid categories if not initialised.
            warnIfUnbalanced(category); // Make sure the library is balanced. 
        } 
        else {
            cout<<"The book is already in the library. \n";
        }
    }

    bool borrowBook(int id) {

        Book *b = findBook(id);  // Iterator to the book object

        if (!b) {
            cout << "Book is not available. \n";
            return false; 
        } 


        if (b->isBorrowed) {                           // If book is already borrowed, return false 
            cout << "Book is already borrowed. \n";
            return false; 
        } 
        
        else {
            b->isBorrowed = true;               // Flip the borrowed flag            
            borrowedIds.insert(id);             // Remember it's borrowed
            cout << "Book: "<< id<< " is now borrowed. \n";   // Print to terminal
            return true;
        }
    return false;
    }

    bool returnBook(int id) {
        Book *b = findBook(id);  // Iterator to the book object

        if (!b) {
            cout << "Book is not available. \n";
            return false; 
        } 

        if (b->isBorrowed) {                           // If book is borrowed, return it 
            cout << "Book was succesfully return, have a nice day. \n";
            b->isBorrowed = false;            // Flip the borrowed flag to false    

            return false; 
        } 
        return false;
    }

   
    // --- Displays ---
    void displayAllBooks() const {
        // TODO: iterate over booksById and print all
        cout << "All books: " << endl;
        for (auto i = booksById.begin(); i != booksById.end(); i++)
            cout << "Key: "<< i->first << "       " << "id: "<< i->second.id << " Category: "<< i->second.category << " Borrow status:" << i->second.isBorrowed << "\n"<<endl;

        }

    void displayAvailableBooks() const {
        cout << " All books: " << endl;
        for (auto i = booksById.begin(); i != booksById.end(); i++){
            if (i->second.isBorrowed == false) {
                cout << "Displaying available books: \n";
                cout << "Key: "<< i->first << "       " << "id: "<< i->second.id << " Category: "<< i->second.category << " Borrow status:" << i->second.isBorrowed << "\n"<<endl;
            }
        }       
    }

    void displayBorrowedBooks() const {
        cout << "Displaying borrowed books: \n" << endl;
        for (auto i = booksById.begin(); i != booksById.end(); i++){
            if (i->second.isBorrowed) {
                cout << "Key: "<< i->first << "       " << "id: "<< i->second.id << " Category: "<< i->second.category << " Borrow status:" << i->second.isBorrowed << "\n"<<endl;
            }
        }     
    }

    // --- Stats ---
    int countBooksInCategory(int category) const {
        return countPerCat[category];
    }
};

// --- Main test driver (outline) ---
int main() {
    Library myLibrary; // Initialise library.
    
    // Adding books to the library (mirrors the starter main in the image)
    myLibrary.addBook(1, 3);   // Book ID: 1, Category: 3
    myLibrary.addBook(2, 7);   // Book ID: 2, Category: 7
    myLibrary.addBook(3, 3);   // Book ID: 3, Category: 3
    myLibrary.addBook(4, 15);  // Book ID: 4, Category: 15
    myLibrary.addBook(5, 3);   // Book ID: 5, Category: 3  (Warning should trigger here)
    myLibrary.addBook(6, 0);   // Book ID: 6, Category: 0

    cout<< "\nAll books in the library (available first):\n";
    cout<< "Available books:\n";
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
