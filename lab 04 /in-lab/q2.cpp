/*TASK # 02
Scenario: A library system allows users to borrow and return books. The system should:
    1. Add new books to the collection.
    2. Borrow books (check availability).
    3. Return books.
    4. Display all available books.
Requirements:
 Implement a Book class with attributes: ID, title, author, availability.
 Implement a Library class with:
    1. Method to add a book (with unique ID).
    2. Method to borrow a book (updates availability).
    3. Method to return a book (marks it available).
    4. Method to display all available books.
 Store book records dynamically using pointers and DMA.
 Use constructor overloading to initialize books with or without availability status.*/

#include <iostream>
#include <string>
using namespace std;

class Book {
    int id;
    string title;
    string author;
    bool availability;

public:
    Book() {
        id = 0;
        title = "";
        author = "";
        availability = true;
    }

    Book(int id, string title, string author, bool availability) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->availability = availability;
    }

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        availability = true;
    }

    int getId() {
        return id;
    }
    string getTitle() {
        return title;
    }
    string getAuthor() {
        return author;
    }
    bool isAvailable() {
        return availability;
    }

    void setId(int id) {
        this->id = id;
    }
    void setTitle(string title) {
        this->title = title;
    }
    void setAuthor(string author) {
        this->author = author;
    }
    void setAvailability(bool availability) {
        this->availability = availability;
    }
};

class Library {
    Book* collection; 
    int size; 

public:
    Library() {
        collection = nullptr;
        size = 0;
    }

    void addBook(int id) {
        string title, author;
        bool flag = false;
        for (int i = 0; i < size; i++) {
            if (collection[i].getId() == id) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            Book* bookArr = new Book[size + 1];
            for (int i = 0; i < size; i++) {
                bookArr[i] = collection[i]; 
            }

            bookArr[size].setId(id);
            cout << "Enter Book title: ";
            getline(cin, title); 
            bookArr[size].setTitle(title);
            cout << "Enter Book author: ";
            getline(cin, author);
            bookArr[size].setAuthor(author);

            delete[] collection;
            collection = bookArr;
            size++;
        }
        else {
            cout << "Book ID already exists!" << endl;
        }
    }

    void borrowBook(int id) {
        bool flag = false;
        for (int i = 0; i < size; i++) {
            if (collection[i].getId() == id) {
                flag = true;
                if (collection[i].isAvailable()) {
                    collection[i].setAvailability(false);
                    cout << "Book borrowed successfully" << endl;
                    return;
                }
                else {
                    cout << "Book already borrowed" << endl;
                    return;
                }
            }
        }

        if (!flag) {
            cout << "Book ID inaccurate!" << endl;
        }
    }

    void returnBook(int id) {
        bool flag = false;
        for (int i = 0; i < size; i++) {
            if (collection[i].getId() == id) {
                flag = true;
                if (!collection[i].isAvailable()) {
                    collection[i].setAvailability(true);
                    cout << "Book returned successfully" << endl;
                    return;
                }
                else {
                    cout << "Book already available" << endl;
                    return;
                }
            }
        }

        if (!flag) {
            cout << "Book ID inaccurate!" << endl;
        }
    }

    void displayAll() {
        if (size == 0) {
            cout << "No books in the library!" << endl;
            return;
        }

        cout << "Displaying All Available books:" << endl;
        cout << "ID \t Title \t Author" << endl;
        for (int i = 0; i < size; i++) {
            if (collection[i].isAvailable()) {
                cout << collection[i].getId() << "\t" << collection[i].getTitle() << "\t" << collection[i].getAuthor() << endl;
            }
        }
        cout << endl;
    }

    ~Library() {
        delete[] collection;
    }
};

int main() {
    Library library;
    library.addBook(1);
    library.addBook(2);
    library.addBook(3);
    library.displayAll();
    library.borrowBook(2);
    library.borrowBook(3);
    library.displayAll();
    library.returnBook(2);
    library.displayAll();
}
