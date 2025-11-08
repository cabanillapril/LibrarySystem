#pragma once
#include <string>
#include <iostream>
using namespace std;

class Member {
private:
    string name;
    int id;

public:
    Member(string name = "", int id = 0);

    void display() const;
    int getId() const;
    string getName() const;

    // Serialization for saving to file
    string serialize() const;

    // Deserialization for loading from file
    void deserialize(const string& data);
};
