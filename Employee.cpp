#include "Employee.h"
#include <iostream>
#include <stdexcept>
#include <cctype>

std::string Employee::checkedNonBlank(const std::string& value, const std::string& fieldName) {
    bool hasChar = false;
    for (char c : value) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            hasChar = true;
            break;
        }
    }
    if (!hasChar) {
        throw std::invalid_argument(fieldName + " cannot be empty or whitespace.");
    }
    return value;
}

Employee::Employee(const std::string& empName, const std::string& empNumber, const std::string& empHireDate)
    : name(checkedNonBlank(empName, "Name")),
    employeeNumber(checkedNonBlank(empNumber, "Employee number")),
    hireDate(checkedNonBlank(empHireDate, "Hire date")) {
}

std::string Employee::getName() const { return name; }
std::string Employee::getEmployeeNumber() const { return employeeNumber; }
std::string Employee::getHireDate() const { return hireDate; }

void Employee::setName(const std::string& empName) {
    name = checkedNonBlank(empName, "Name");
}

void Employee::setEmployeeNumber(const std::string& empNumber) {
    employeeNumber = checkedNonBlank(empNumber, "Employee number");
}

void Employee::setHireDate(const std::string& empHireDate) {
    hireDate = checkedNonBlank(empHireDate, "Hire date");
}

void Employee::print(bool showRole) const {
    std::cout << "Name: " << name << '\n';
    std::cout << "Employee number: " << employeeNumber << '\n';
    std::cout << "Hire date: " << hireDate << '\n';
    if (showRole) {
        std::cout << "Role: Employee\n";
    }
}