#include "ShiftSupervisor.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>

double ShiftSupervisor::checkedNonNegative(double value, const std::string& fieldName) {
    if (!std::isfinite(value) || value < 0.0) {
        throw std::invalid_argument(fieldName + " must be finite and nonnegative.");
    }
    return value;
}

ShiftSupervisor::ShiftSupervisor(const std::string& empName, const std::string& empNumber,
    const std::string& empHireDate, double salary, double bonus)
    : Employee(empName, empNumber, empHireDate),
    annualSalary(checkedNonNegative(salary, "Annual salary")),
    annualBonus(checkedNonNegative(bonus, "Annual bonus")) {
}

double ShiftSupervisor::getAnnualSalary() const { return annualSalary; }
double ShiftSupervisor::getAnnualBonus() const { return annualBonus; }

void ShiftSupervisor::setAnnualSalary(double salary) {
    annualSalary = checkedNonNegative(salary, "Annual salary");
}

void ShiftSupervisor::setAnnualBonus(double bonus) {
    annualBonus = checkedNonNegative(bonus, "Annual bonus");
}

void ShiftSupervisor::print(bool showRole) const {
    Employee::print(false);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Annual salary: $" << annualSalary << '\n';
    std::cout << "Annual production bonus: $" << annualBonus << '\n';
    if (showRole) {
        std::cout << "Role: Shift Supervisor\n";
    }
}