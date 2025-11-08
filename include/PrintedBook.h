#pragma once
#include "Book.h"
#include <string>
using namespace std;

class PrintedBook : public Book {
private:
    int pages;
    int borrowedByMemberId = -1; // -1 means not borrowed

public:
    PrintedBook(string title = "", string author = "", string isbn = "", int pages = 0);

    void display() const override;
    string getType() const override { return "PRINTED"; }
    string serialize() const override;
    void deserialize(const string& data) override;

    void borrowBook(int memberId);
    void returnBook();
    int getBorrowerId() const;
};
