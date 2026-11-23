#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "Employee.h"

class ProductionWorker : public Employee {
private:
    int shift;
    double hourlyRate;

    static int checkedShift(int value);
    static double checkedRate(double value);

public:
    ProductionWorker(const std::string& empName, const std::string& empNumber,
        const std::string& empHireDate, int workerShift, double rate);

    int getShift() const;
    double getHourlyRate() const;

    void setShift(int workerShift);
    void setHourlyRate(double rate);

    void print(bool showRole = true) const;
};

#endif