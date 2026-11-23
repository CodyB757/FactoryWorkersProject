#include "TeamLeader.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>

double TeamLeader::checkedNonNegative(double value, const std::string& fieldName) {
    if (!std::isfinite(value) || value < 0.0) {
        throw std::invalid_argument(fieldName + " must be finite and nonnegative.");
    }
    return value;
}

TeamLeader::TeamLeader(const std::string& empName, const std::string& empNumber,
    const std::string& empHireDate, int workerShift, double rate,
    double bonus, double reqHours, double attHours)
    : ProductionWorker(empName, empNumber, empHireDate, workerShift, rate),
    monthlyBonus(checkedNonNegative(bonus, "Monthly bonus")),
    requiredHours(checkedNonNegative(reqHours, "Required training hours")),
    attendedHours(checkedNonNegative(attHours, "Attended training hours")) {
}

double TeamLeader::getMonthlyBonus() const { return monthlyBonus; }
double TeamLeader::getRequiredHours() const { return requiredHours; }
double TeamLeader::getAttendedHours() const { return attendedHours; }

void TeamLeader::setMonthlyBonus(double bonus) {
    monthlyBonus = checkedNonNegative(bonus, "Monthly bonus");
}

void TeamLeader::setRequiredHours(double reqHours) {
    requiredHours = checkedNonNegative(reqHours, "Required training hours");
}

void TeamLeader::setAttendedHours(double attHours) {
    attendedHours = checkedNonNegative(attHours, "Attended training hours");
}

void TeamLeader::print(bool showRole) const {
    ProductionWorker::print(false);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Monthly bonus: $" << monthlyBonus << '\n';
    std::cout << "Required training: " << requiredHours << " hours\n";
    std::cout << "Attended training: " << attendedHours << " hours\n';
        if (showRole) {
            std::cout << "Role: Team Leader\n";
        }
}