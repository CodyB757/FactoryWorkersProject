#include "ProductionWorker.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>

int ProductionWorker::checkedShift(int value) {
    if (value != 1 && value != 2) {
        throw std::invalid_argument("Shift must be 1 (day) or 2 (night).");
    }
    return value;
}

double ProductionWorker::checkedRate(double value) {
    if (!std::isfinite(value) || value < 0.0) {
        throw std::invalid_argument("Hourly rate must be finite and nonnegative.");
    }
    return value;
}

ProductionWorker::ProductionWorker(const std::string& empName, const std::string& empNumber,
    const std::string& empHireDate, int workerShift, double rate)
    : Employee(empName, empNumber, empHireDate),
    shift(checkedShift(workerShift)),
    hourlyRate(checkedRate(rate)) {
}

int ProductionWorker::getShift() const { return shift; }
double ProductionWorker::getHourlyRate() const { return hourlyRate; }

void ProductionWorker::setShift(int workerShift) {
    shift = checkedShift(workerShift);
}

void ProductionWorker::setHourlyRate(double rate) {
    hourlyRate = checkedRate(rate);
}

void ProductionWorker::print(bool showRole) const {
    Employee::print(false);
    std::cout << "Shift: " << shift << (shift == 1 ? " (Day)" : " (Night)") << '\n';
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Hourly rate: $" << hourlyRate << '\n';
    if (showRole) {
        std::cout << "Role: Production Worker\n";
    }
}