#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager();
    Manager(int id, string name, double salary, int teamSize);

    void display() const override;
    string getRole() const override;

    int getTeamSize() const;
};

#endif