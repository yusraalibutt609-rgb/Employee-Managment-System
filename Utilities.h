#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
using namespace std;

class Utilities {
public:
    static void line();

    // Static Polymorphism (Function Overloading)
    static void print(int value);
    static void print(double value);
    static void print(string value);
};

#endif