#pragma once
#include <string>
#include <iostream>
using namespace std;

class Book {
protected:
    string title;
    string author;
    string isbn;
    bool isBorrowed;

public:
    Book(string title = "", string author = "", string isbn = "");
    virtual ~Book() = default;

    virtual void display() const;
    virtual string getType() const = 0; // pure virtual for subclass type

    string getTitle() const;
    string getISBN() const;
    bool getStatus() const;

    void borrowBook();
    void returnBook();

    virtual string serialize() const;   // save to file
    virtual void deserialize(const string& data); // load from file
};
