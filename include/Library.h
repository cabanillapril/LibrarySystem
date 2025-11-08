#pragma once
#include <vector>
#include "PrintedBook.h"
#include "Member.h"

class Library {
private:
    std::vector<PrintedBook*> books;
    std::vector<Member> members;

    void loadBooks();
    void saveBooks();

    // Add these declarations for members
    void loadMembers();
    void saveMembers();

public:
    Library();
    ~Library();

    void addBook();
    void addMember();
    void borrowBook();
    void returnBook();
    void viewBooks() const;
    void viewMembers() const;
    void run();
};
