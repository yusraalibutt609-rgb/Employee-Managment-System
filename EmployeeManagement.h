#ifndef EMPLOYEEMANAGEMENT_H
#define EMPLOYEEMANAGEMENT_H

#include <vector>
#include <fstream>
#include "Developer.h"
#include "Manager.h"
#include "Utilities.h"

class EmployeeManagement {
private:
    vector<Employee*> employees;

public:
    EmployeeManagement();
    ~EmployeeManagement();

    void addDeveloper();
    void addManager();
    void displayEmployees() const;
    void saveToFile() const;
    void loadFromFile();
    void searchEmployee() const;
    void removeEmployee();
    void run();
};

#endif