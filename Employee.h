#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int id;
    string name;
    double salary;

    static int employeeCount;

public:
    Employee();
    Employee(int id, string name, double salary);

    virtual ~Employee();

    virtual void display() const = 0;
    virtual string getRole() const = 0;

    int getId() const;
    string getName() const;
    double getSalary() const;

    void setName(string name);
    void setSalary(double salary);

    static int getEmployeeCount();
};

#endif