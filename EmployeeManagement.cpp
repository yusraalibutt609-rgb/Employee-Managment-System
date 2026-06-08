#include "EmployeeManagement.h"

EmployeeManagement::EmployeeManagement() {
    loadFromFile();
}

EmployeeManagement::~EmployeeManagement() {
    saveToFile();

    for (Employee* employee : employees) {
        delete employee;
    }
}

void EmployeeManagement::addDeveloper() {
    int id;
    string name;
    double salary;
    string language;

    cout << "Enter Developer ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Salary: ";
    cin >> salary;

    cin.ignore();

    cout << "Enter Programming Language: ";
    getline(cin, language);

    employees.push_back(new Developer(id, name, salary, language));

    cout << "Developer Added Successfully!\n";
}

void EmployeeManagement::addManager() {
    int id;
    string name;
    double salary;
    int teamSize;

    cout << "Enter Manager ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Salary: ";
    cin >> salary;

    cout << "Enter Team Size: ";
    cin >> teamSize;

    employees.push_back(new Manager(id, name, salary, teamSize));

    cout << "Manager Added Successfully!\n";
}

void EmployeeManagement::displayEmployees() const {
    if (employees.empty()) {
        cout << "No Employees Found!\n";
        return;
    }

    Utilities::line();

    for (Employee* employee : employees) {
        employee->display();
        Utilities::line();
    }

    cout << "Total Employees: "
         << Employee::getEmployeeCount() << endl;
}

void EmployeeManagement::saveToFile() const {
    ofstream file("employees.txt");

    for (Employee* employee : employees) {
        file << employee->getRole() << " "
             << employee->getId() << " "
             << employee->getName() << " "
             << employee->getSalary() << endl;
    }

    file.close();
}

void EmployeeManagement::loadFromFile() {
    ifstream file("employees.txt");

    if (!file) {
        return;
    }

    string role;
    int id;
    string name;
    double salary;

    while (file >> role >> id >> name >> salary) {
        if (role == "Developer") {
            employees.push_back(
                    new Developer(id, name, salary, "C++")
            );
        }
        else if (role == "Manager") {
            employees.push_back(
                    new Manager(id, name, salary, 5)
            );
        }
    }

    file.close();
}

void EmployeeManagement::searchEmployee() const {
    int searchId;

    cout << "Enter Employee ID to Search: ";
    cin >> searchId;

    for (Employee* employee : employees) {
        if (employee->getId() == searchId) {
            employee->display();
            return;
        }
    }

    cout << "Employee Not Found!\n";
}

void EmployeeManagement::removeEmployee() {
    int removeId;

    cout << "Enter Employee ID to Remove: ";
    cin >> removeId;

    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if ((*it)->getId() == removeId) {
            delete *it;
            employees.erase(it);

            cout << "Employee Removed Successfully!\n";
            return;
        }
    }

    cout << "Employee Not Found!\n";
}

void EmployeeManagement::run() {
    int choice;

    do {
        Utilities::line();
        cout << "EMPLOYEE MANAGEMENT SYSTEM\n";
        Utilities::line();

        cout << "1. Add Developer\n";
        cout << "2. Add Manager\n";
        cout << "3. Display Employees\n";
        cout << "4. Search Employee\n";
        cout << "5. Remove Employee\n";
        cout << "6. Save Data\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addDeveloper();
                break;

            case 2:
                addManager();
                break;

            case 3:
                displayEmployees();
                break;

            case 4:
                searchEmployee();
                break;

            case 5:
                removeEmployee();
                break;

            case 6:
                saveToFile();
                cout << "Data Saved Successfully!\n";
                break;

            case 0:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 0);
}