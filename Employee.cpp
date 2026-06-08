#include "Employee.h"

int Employee::employeeCount = 0;

Employee::Employee() {
    id = 0;
    name = "Unknown";
    salary = 0;
    employeeCount++;
}

Employee::Employee(int id, string name, double salary) {
    this->id = id;
    this->name = name;
    this->salary = salary;
    employeeCount++;
}

Employee::~Employee() {
}

int Employee::getId() const {
    return id;
}

string Employee::getName() const {
    return name;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setName(string name) {
    this->name = name;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

int Employee::getEmployeeCount() {
    return employeeCount;
}