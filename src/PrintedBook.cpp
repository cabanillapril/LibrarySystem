#include "../include/PrintedBook.h"
#include <sstream>
#include <iostream>
using namespace std;

PrintedBook::PrintedBook(string title, string author, string isbn, int pages)
    : Book(title, author, isbn), pages(pages), borrowedByMemberId(-1) {}

void PrintedBook::display() const {
    cout << "[PRINTED BOOK]\n";
    Book::display();
    cout << "Pages: " << pages << "\n";
    if (borrowedByMemberId != -1)
        cout << "Borrowed by Member ID: " << borrowedByMemberId << "\n";
}

string PrintedBook::serialize() const {
    stringstream ss;
    ss << getType() << "," << title << "," << author << "," << isbn << ","
       << (isBorrowed ? "1" : "0") << "," << pages << "," 
       << (borrowedByMemberId != -1 ? borrowedByMemberId : 0);
    return ss.str();
}

void PrintedBook::deserialize(const string& data) {
    string type, statusStr, pagesStr, borrowerStr;

    stringstream ss(data);
    getline(ss, type, ',');
    getline(ss, title, ',');
    getline(ss, author, ',');
    getline(ss, isbn, ',');
    getline(ss, statusStr, ',');
    getline(ss, pagesStr, ',');
    getline(ss, borrowerStr, ',');

    isBorrowed = (statusStr == "1");

    pages = stoi(pagesStr);

    int id = stoi(borrowerStr);
    borrowedByMemberId = (id == 0) ? -1 : id;
}

void PrintedBook::borrowBook(int memberId) {
    if (!isBorrowed) {
        isBorrowed = true;
        borrowedByMemberId = memberId;
    }
}

void PrintedBook::returnBook() {
    isBorrowed = false;
    borrowedByMemberId = -1;
}

int PrintedBook::getBorrowerId() const {
    return borrowedByMemberId;
}
