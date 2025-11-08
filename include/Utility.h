#pragma once
#include <iostream>
using namespace std;

template<typename T>
void printVector(const T& vec) {
    for (const auto& item : vec) {
        cout << item << endl;
    }
}
