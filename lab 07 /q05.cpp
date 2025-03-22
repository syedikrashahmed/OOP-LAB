#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title, id, publisher, publicationDate;

public:
    Media(string title, string id, string publisher, string publicationDate) : title(title), id(id), publisher(publisher), publicationDate(publicationDate) {}

    Media() : title(""), id(""), publisher(""), publicationDate("") {}

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "ID: " << id << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Publication Date: " << publicationDate << endl;
    }

    string getId() { return id; }
    string getTitle() { return title; }
    string getPublisher() { return publisher; }
    string getPublicationDate() { return publicationDate; }

    virtual void checkOut() {
        cout << "Item checked out" << endl;
    }

    virtual void returnItem() {
        cout << "Item returned" << endl;
    }
};

class Book : public Media {
    string author, ISBN;
    int numberOfPages;

public:
    Book(string title, string id, string publisher, string publicationDate, string author, string ISBN, int numberOfPages) : Media(title, id, publisher, publicationDate), author(author), ISBN(ISBN), numberOfPages(numberOfPages) {}

    Book() : Media(), author(""), ISBN(""), numberOfPages(0) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
    string director;
    int duration, rating;

public:
    DVD(string title, string id, string publisher, string publicationDate, string director, int duration, int rating) : Media(title, id, publisher, publicationDate), director(director), duration(duration), rating(rating) {}
    
    DVD() : Media(), director(""), duration(0), rating(0) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << endl;
        cout << "Rating: " << rating << endl;
    }
};

class CD : public Media {
    string artist, genre;
    int numberOfTracks;

public:
    CD(string title, string id, string publisher, string publicationDate, string artist, string genre, int numberOfTracks) : Media(title, id, publisher, publicationDate), artist(artist), genre(genre), numberOfTracks(numberOfTracks) {}
    
    CD() : Media(), artist(""), genre(""), numberOfTracks(0) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Genre: " << genre << endl;
        cout << "Number of Tracks: " << numberOfTracks << endl;
    }  
};

class Magazine : public Media {
    string issueDate;
    int numberOfPages;

public:
    Magazine(string title, string id, string publisher, string publicationDate, string issueDate, int numberOfPages) : Media(title, id, publisher, publicationDate), issueDate(issueDate), numberOfPages(numberOfPages) {}

    Magazine() : Media(), issueDate(""), numberOfPages(0) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Issue Date: " << issueDate << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
    }
};

class System {
    Media** media;
    int numMedia;

public:
    System() : media(nullptr), numMedia(0) {}

    void addMedia(Media* m) {
        Media** newMedia = new Media*[numMedia + 1];    
        for (int i = 0; i < numMedia; i++) {
            newMedia[i] = media[i];
        }
        newMedia[numMedia] = m;
        delete[] media;
        media = newMedia;
        numMedia++;
    }

    bool searchMedia(string id) {
        for (int i = 0; i < numMedia; i++) {
            if (media[i]->getId() == id) {
                return true;
            }
        }
        return false;
    }

    bool searchMedia(string id, string title) {
        for (int i = 0; i < numMedia; i++) {
            if (media[i]->getId() == id || media[i]->getTitle() == title) {
                return true;
            }
        }
        return false;
    }

    bool searchMedia(string id, string title, string publisher) {
        for (int i = 0; i < numMedia; i++) {
            if (media[i]->getId() == id || media[i]->getTitle() == title || media[i]->getPublisher() == publisher) {
                return true;
            }
        }
        return false;
    }

    bool searchMedia(string id, string title, string publisher, string date) {
        for (int i = 0; i < numMedia; i++) {
            if (media[i]->getId() == id || media[i]->getTitle() == title || media[i]->getPublisher() == publisher || media[i]->getPublicationDate() == date) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    System sys;
    Book book("Book Theif", "B", "Penguins", "2003", "Mark Zusak", "9780743273565", 180);
    DVD dvd("ZNMD", "D", "Warner Bros.", "2011", "Zoya Akhtar", 148, 8);
    CD cd("31", "C", "Some Records", "2013", "Sikander Ka Mandir", "Rock", 9);
    Magazine magazine("National Geographic", "M", "National Geographic", "2001", "2001", 100);

    sys.addMedia(&book);
    sys.addMedia(&dvd);
    sys.addMedia(&cd);
    sys.addMedia(&magazine);
     
    book.checkOut();
    dvd.returnItem();
    
    if (sys.searchMedia("B")) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    if (sys.searchMedia("D", "ZNMD")) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    if (sys.searchMedia("C", "31", "Some Records")) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    if (sys.searchMedia("M", "National Geographic", "National Geographic", "2001")) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }
}
