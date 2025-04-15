#include <iostream>
#include <string>
using namespace std;

#ifndef BOOK_HPP
#define BOOK_HPP


class Book {
    protected:
    string title;
    string author;
    string ISBN;

    public:
    Book(string t, string a, string isbn) : title(t), author(a), ISBN(isbn) {}

    Book() : title(""), author(""), ISBN("") {}
    
    string getTitle() {
        return title;
    }
    
    string getAuthor() {
        return author;
    }
    
    string getISBN() {
        return ISBN;
    }
};
#endif