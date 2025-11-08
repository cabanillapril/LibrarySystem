#include "../include/Member.h"
#include <sstream>
using namespace std;

// Constructor
Member::Member(string name, int id) : name(name), id(id) {}

// Display member info
void Member::display() const {
    cout << "Member Name: " << name << ", ID: " << id << "\n";
}

// Getters
int Member::getId() const { return id; }
string Member::getName() const { return name; }

// Serialize to string for file saving
string Member::serialize() const {
    stringstream ss;
    ss << name << "," << id;
    return ss.str();
}

// Deserialize from string from file
void Member::deserialize(const string& data) {
    stringstream ss(data);
    string idStr;
    getline(ss, name, ',');
    getline(ss, idStr, ',');

    id = 0;
    for (char c : idStr) id = id * 10 + (c - '0');
}
