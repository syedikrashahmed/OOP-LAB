#include "book.hpp"
#include <iostream>
#include <string>
using namespace std;

class Library {
    protected:
    Book *books;
    int numBooks;

    public:
    Library() : books(nullptr), numBooks(0) {}

    ~Library() {
        delete[] books;
    }

    Library& operator=(const Library& other) {
        if (this != &other) {
            delete[] books;
            numBooks = other.numBooks;
            books = new Book[numBooks];
            for (int i = 0; i < numBooks; ++i) {
                books[i] = other.books[i];
            }
        }
        return *this;
    }

    void addBook(const Book& book) {
        Book* newBooks = new Book[numBooks + 1];
        for (int i = 0; i < numBooks; ++i) {
            newBooks[i] = books[i];
        }
        newBooks[numBooks] = book;
        delete[] books;
        books = newBooks;
        numBooks++;
    }

    bool removeBook(const string& ISBN) {
        for (int i = 0; i < numBooks; ++i) {
            if (books[i].getISBN() == ISBN) {
                Book* newBooks = new Book[numBooks - 1];
                for (int j = 0; j < i; ++j) {
                    newBooks[j] = books[j];
                }
                for (int j = i; j < numBooks - 1; ++j) {
                    newBooks[j] = books[j + 1];
                }
                delete[] books;
                books = newBooks;
                numBooks--;
                return true;
            }
        }
        return false;
    }

    Book* searchBook(string query) {
        for (int i = 0; i < numBooks; ++i) {
            if (books[i].getTitle() == query || books[i].getAuthor() == query || books[i].getISBN() == query) {
                return &books[i];
            }
        }
        return nullptr;
    }

    void displayAllBooks() const {
        cout << "Library Collection (" << numBooks << " books):\n";
        for (int i = 0; i < numBooks; ++i) {
            cout << i+1 << ". " << books[i].getTitle() << " by " << books[i].getAuthor() << " (ISBN: " << books[i].getISBN() << ")\n";
        }
    }
};

int main() {
    Library library;
        library.addBook(Book("1984", "George Orwell", "123"));
    library.addBook(Book("time Mchine", "H.G. Wells", "456"));
    library.addBook(Book("This Side Of paradise", "F. Scott Fitzgerald", "789"));
    library.displayAllBooks();
    cout << "\n";
    Book* found = library.searchBook("Harper Lee");
    if (found) {
        cout << "Found book: " << found->getTitle() << "\n\n";
    }
    library.removeBook("123");
    library.displayAllBooks();
}