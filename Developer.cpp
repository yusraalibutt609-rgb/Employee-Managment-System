#include "Developer.h"

Developer::Developer() : Employee() {
    programmingLanguage = "None";
}

Developer::Developer(int id, string name, double salary, string language)
        : Employee(id, name, salary) {
    programmingLanguage = language;
}

void Developer::display() const {
    cout << "\nDeveloper Details\n";
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Salary: " << salary << endl;
    cout << "Programming Language: " << programmingLanguage << endl;
}

string Developer::getRole() const {
    return "Developer";
}

string Developer::getProgrammingLanguage() const {
    return programmingLanguage;
}