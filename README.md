# Employee Management System
### A C++ OOP Project

So I built this Employee Management System in C++ as part of my OOP course. The idea is pretty straightforward — you can add employees (either Developers or Managers), view them, search by ID, remove them, and the data gets saved automatically so nothing is lost when you close the program.

It's a console app, nothing fancy on the outside, but under the hood it covers all the core OOP concepts: inheritance, polymorphism, encapsulation, abstraction, and file I/O.

---

## Table of Contents

- [What It Does](#what-it-does)
- [OOP Concepts Covered](#oop-concepts-covered)
- [Project Structure](#project-structure)
- [The Classes Explained](#the-classes-explained)
- [How to Build and Run](#how-to-build-and-run)
- [Using the Menu](#using-the-menu)
- [How Data is Saved](#how-data-is-saved)
- [Things I Know Could Be Better](#things-i-know-could-be-better)

---

## What It Does

At its core, this program lets you manage a list of employees through a simple numbered menu. You can:

- Add a **Developer** (with their programming language)
- Add a **Manager** (with their team size)
- View all employees with their details
- Search for a specific employee by ID
- Remove an employee from the list
- Manually save data at any point

When you start the program, it automatically loads any previously saved employees. When you exit, it saves everything back to the file. So it feels persistent, like a real little system.

---

## OOP Concepts Covered

This project was built specifically to practice OOP, so here's where each concept actually shows up:

| Concept | Where It's Used |
|---|---|
| **Abstraction** | `Employee` is an abstract class — you can never create a plain `Employee`, only a `Manager` or `Developer`. It forces the right design. |
| **Inheritance** | Both `Manager` and `Developer` extend `Employee` and get all its base functionality for free |
| **Runtime Polymorphism** | The system stores everything as `Employee*` pointers. When you call `display()`, C++ figures out at runtime whether to show Manager or Developer details |
| **Compile-time Polymorphism** | `Utilities::print()` is overloaded three times — for `int`, `double`, and `string` |
| **Encapsulation** | All data is private/protected, accessed only through getters and setters |
| **Static Members** | `employeeCount` keeps a running total of how many Employee objects exist across the whole program |
| **Dynamic Memory** | Employees are heap-allocated with `new` and properly cleaned up in the destructor |
| **File I/O** | `ofstream` writes to `employees.txt`, `ifstream` reads it back on startup |

---

## Project Structure

```
OOP Project/
│
├── main.cpp                       # Just 5 lines — creates the system and calls run()
│
├── Employee.h / Employee.cpp      # The abstract base class everything inherits from
├── Manager.h / Manager.cpp        # Represents a manager (has a team size)
├── Developer.h / Developer.cpp    # Represents a developer (has a programming language)
│
├── EmployeeManagement.h / .cpp    # The brain of the system — handles the menu and all operations
├── Utilities.h / Utilities.cpp    # Small helper class for printing and separators
│
└── CMakeLists.txt                 # Build configuration for CMake
```

---

## The Classes Explained

### `Employee` — The Blueprint
This is the abstract base class. It holds the three things every employee has: an `id`, a `name`, and a `salary`. Since it has pure virtual functions (`display()` and `getRole()`), you can't instantiate it directly — which is the whole point. It also tracks the total number of employees via a static variable `employeeCount`.

### `Manager` — extends `Employee`
Adds one thing on top of the base: `teamSize`. It overrides `display()` to show manager-specific info and `getRole()` to return `"Manager"`.

### `Developer` — extends `Employee`
Same idea but adds `programmingLanguage` instead. Overrides `display()` and `getRole()` to return `"Developer"`.

### `EmployeeManagement` — The Controller
This is where everything happens. It holds a `vector<Employee*>` which is the master list of all employees. The constructor loads from file on startup, and the destructor saves to file and cleans up memory when the program exits. It handles the full menu loop and every operation: add, display, search, remove, save.

### `Utilities` — The Helper
A simple utility class with a static `line()` method that prints a separator, and three overloaded `print()` functions for integers, doubles, and strings (demonstrating compile-time polymorphism).

---

## How to Build and Run

**Requirements:**
- C++11 or later
- CMake 3.x
- Any C++ compiler — GCC, MinGW, MSVC, or Clang

**Steps:**

```bash
# Navigate to the project folder, then:
mkdir cmake-build-debug
cd cmake-build-debug
cmake ..
cmake --build .

# Run it:
./OOP_Project        # on Linux or Mac
OOP_Project.exe      # on Windows
```

If you're using **CLion**, just open the project and hit Run — it handles the CMake setup automatically.

---

## Using the Menu

When you run it, you'll see:

```
========================================
EMPLOYEE MANAGEMENT SYSTEM
========================================
1. Add Developer
2. Add Manager
3. Display Employees
4. Search Employee
5. Remove Employee
6. Save Data
0. Exit
```

Just type a number and press Enter. Pretty self-explanatory. Option `6` manually saves, but data also saves automatically when you exit with `0`.

---

## How Data is Saved

Everything gets written to `employees.txt` inside the build directory. The format looks like this:

```
Developer 101 Ali 75000
Manager 201 Sara 90000
```

It saves automatically on exit and loads automatically on startup, so your data sticks around between sessions.

---

## Things I Know Could Be Better

Being honest about the rough edges:

- **Programming language and team size don't survive a save/load** — when loading from file, Developers always get `"C++"` and Managers always get `teamSize = 5`, regardless of what was originally entered. The file doesn't store those fields.
- **Names with spaces will break file loading** — `file >> name` only reads one word, so `Ali Raza` would load incorrectly.
- **Employee count doesn't go down on removal** — the static counter increments when an employee is created but never decrements when one is deleted.
- **No duplicate ID check** — you can add two employees with the same ID and the system won't complain.

These are things I'd fix in a next version.

---

## About

Built as part of an OOP course using C++ in CLion with CMake.
