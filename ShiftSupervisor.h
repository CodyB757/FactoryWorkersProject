#ifndef SHIFTSUPERVISOR_H
#define SHIFTSUPERVISOR_H

#include "Employee.h"

class ShiftSupervisor : public Employee {
private:
    double annualSalary;
    double annualBonus;

    static double checkedNonNegative(double value, const std::string& fieldName);

public:
    ShiftSupervisor(const std::string& empName, const std::string& empNumber,
        const std::string& empHireDate, double salary, double bonus);

    double getAnnualSalary() const;
    double getAnnualBonus() const;

    void setAnnualSalary(double salary);
    void setAnnualBonus(double bonus);

    void print(bool showRole = true) const;
};

#endif