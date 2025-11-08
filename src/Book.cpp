#include "../include/Book.h"
#include <sstream>

Book::Book(string title, string author, string isbn)
    : title(title), author(author), isbn(isbn), isBorrowed(false) {}

void Book::display() const {
    cout << "Title: " << title << "\nAuthor: " << author
         << "\nISBN: " << isbn
         << "\nStatus: " << (isBorrowed ? "Borrowed" : "Available") << "\n";
}

string Book::getTitle() const { return title; }
string Book::getISBN() const { return isbn; }
bool Book::getStatus() const { return isBorrowed; }

void Book::borrowBook() { isBorrowed = true; }
void Book::returnBook() { isBorrowed = false; }

string Book::serialize() const {
    return getType() + "," + title + "," + author + "," + isbn + "," + (isBorrowed ? "1" : "0");
}

void Book::deserialize(const string& data) {
    stringstream ss(data);
    getline(ss, title, ',');
    getline(ss, author, ',');
    getline(ss, isbn, ',');
    string status;
    getline(ss, status, ',');
    isBorrowed = (status == "1");
}
