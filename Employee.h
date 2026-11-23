#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

// Class Invariant:
// name, employeeNumber, and hireDate must be nonblank strings
// (not empty and not whitespace-only).
class Employee {
private:
    std::string name;
    std::string employeeNumber;
    std::string hireDate;

    static std::string checkedNonBlank(const std::string& value, const std::string& fieldName);

public:
    Employee(const std::string& empName, const std::string& empNumber, const std::string& empHireDate);

    std::string getName() const;
    std::string getEmployeeNumber() const;
    std::string getHireDate() const;

    void setName(const std::string& empName);
    void setEmployeeNumber(const std::string& empNumber);
    void setHireDate(const std::string& empHireDate);

    void print(bool showRole = true) const;
};

#endif