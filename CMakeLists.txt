cmake_minimum_required(VERSION 4.1)
project(OOP_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP_Project
        main.cpp
        Employee.h
        Developer.h
        Manager.h
        Utilities.h
        EmployeeManagement.h
        Employee.cpp
        Developer.cpp
        Manager.cpp
        Utilities.cpp
        EmployeeManagement.cpp)
