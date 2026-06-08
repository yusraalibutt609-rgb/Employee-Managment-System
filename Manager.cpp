#include "Manager.h"

Manager::Manager() : Employee() {
    teamSize = 0;
}

Manager::Manager(int id, string name, double salary, int teamSize)
        : Employee(id, name, salary) {
    this->teamSize = teamSize;
}

void Manager::display() const {
    cout << "\nManager Details\n";
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Salary: " << salary << endl;
    cout << "Team Size: " << teamSize << endl;
}

string Manager::getRole() const {
    return "Manager";
}

int Manager::getTeamSize() const {
    return teamSize;
}