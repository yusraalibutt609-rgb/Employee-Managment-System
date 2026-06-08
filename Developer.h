#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.h"

class Developer : public Employee {
private:
    string programmingLanguage;

public:
    Developer();
    Developer(int id, string name, double salary, string language);

    void display() const override;
    string getRole() const override;

    string getProgrammingLanguage() const;
};

#endif