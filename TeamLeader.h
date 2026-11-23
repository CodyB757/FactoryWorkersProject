#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include "ProductionWorker.h"

class TeamLeader : public ProductionWorker {
private:
    double monthlyBonus;
    double requiredHours;
    double attendedHours;

    static double checkedNonNegative(double value, const std::string& fieldName);

public:
    TeamLeader(const std::string& empName, const std::string& empNumber,
        const std::string& empHireDate, int workerShift, double rate,
        double bonus, double reqHours, double attHours);

    double getMonthlyBonus() const;
    double getRequiredHours() const;
    double getAttendedHours() const;

    void setMonthlyBonus(double bonus);
    void setRequiredHours(double reqHours);
    void setAttendedHours(double attHours);

    void print(bool showRole = true) const;
};

#endif