#include "../include/Library.h"
#include <iostream>
#include <fstream>
using namespace std;

Library::Library() {
    loadBooks();
    loadMembers();
}

Library::~Library() {
    saveBooks();
    saveMembers();
    for (auto b : books) delete b;
}

void Library::loadBooks() {
    ifstream file("C:/Users/lenovo/Desktop/LibrarySystem/data/books.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        auto* printed = new PrintedBook();
        printed->deserialize(line);
        books.push_back(printed);
    }
    file.close();
}

void Library::saveBooks() {
    ofstream file("C:/Users/lenovo/Desktop/LibrarySystem/data/books.txt");
    for (auto* b : books)
        file << b->serialize() << "\n";
    file.close();
}

void Library::loadMembers() {
    ifstream file("C:/Users/lenovo/Desktop/LibrarySystem/data/members.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        Member m;
        m.deserialize(line);
        members.push_back(m);
    }
    file.close();
}

void Library::saveMembers() {
    ofstream file("C:/Users/lenovo/Desktop/LibrarySystem/data/members.txt");
    for (auto& m : members)
        file << m.serialize() << "\n";
    file.close();
}

void Library::addBook() {
    string title, author, isbn;
    int pages;

    cout << "Enter title: "; getline(cin, title);
    cout << "Enter author: "; getline(cin, author);
    cout << "Enter ISBN: "; getline(cin, isbn);
    cout << "Enter number of pages: "; cin >> pages; cin.ignore();

    books.push_back(new PrintedBook(title, author, isbn, pages));
    cout << "✅ Book added!\n";
}

void Library::addMember() {
    string name;
    int id;
    cout << "Enter member name: "; getline(cin, name);
    cout << "Enter member ID: "; cin >> id; cin.ignore();
    members.push_back(Member(name, id));
    cout << "✅ Member added!\n";
}

void Library::borrowBook() {
    int memberId;
    string isbn;

    cout << "Enter your Member ID: "; 
    cin >> memberId; cin.ignore();

    cout << "Enter ISBN to borrow: "; getline(cin, isbn);

    for (auto* b : books) {
        PrintedBook* pb = static_cast<PrintedBook*>(b);
        if (pb->getISBN() == isbn && pb->getBorrowerId() == -1) {
            pb->borrowBook(memberId);
            cout << "📘 Borrowed successfully by Member ID " << memberId << "!\n";
            return;
        }
    }
    cout << "❌ Book not available.\n";
}

void Library::returnBook() {
    int memberId;
    string isbn;

    cout << "Enter your Member ID: ";
    cin >> memberId; cin.ignore();

    cout << "Enter ISBN to return: "; getline(cin, isbn);

    for (auto* b : books) {
        PrintedBook* pb = static_cast<PrintedBook*>(b);
        if (pb->getISBN() == isbn && pb->getBorrowerId() == memberId) {
            pb->returnBook();
            cout << "✅ Returned successfully by Member ID " << memberId << "!\n";
            return;
        }
    }
    cout << "❌ Book not found, not borrowed, or wrong Member ID.\n";
}

void Library::viewBooks() const {
    cout << "\n📚 Book List:\n";
    for (auto* b : books) {
        b->display();   // display already prints borrowedByMemberId
        cout << "-------------------\n";
    }
}


void Library::viewMembers() const {
    cout << "\n👤 Members:\n";
    for (const auto& m : members) m.display();
}

void Library::run() {
    int choice;
    do {
        cout << "\n=== LIBRARY MENU ===\n";
        cout << "1. Add Book\n2. Add Member\n3. Borrow Book\n4. Return Book\n";
        cout << "5. View Books\n6. View Members\n0. Exit\nChoice: ";
        cin >> choice; cin.ignore();

        switch (choice) {
            case 1: addBook(); break;
            case 2: addMember(); break;
            case 3: borrowBook(); break;
            case 4: returnBook(); break;
            case 5: viewBooks(); break;
            case 6: viewMembers(); break;
            case 0: cout << "💾 Saving and exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}
