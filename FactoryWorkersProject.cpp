#include <iostream>
#include <stdexcept>
#include "Employee.h"
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"

using namespace std;

int main() {
    cout << "=== 1. OBJECT CREATION & PRINT CHAINING ===\n\n";

    Employee emp("Maya Chen", "E101", "2024-04-15");
    emp.print();
    cout << '\n';

    ProductionWorker dayWorker("Arun Patel", "E102", "2023-09-02", 1, 22.50);
    dayWorker.print();
    cout << '\n';

    ProductionWorker nightWorker("Luis Rivera", "E103", "2022-08-10", 2, 25.75);
    nightWorker.print();
    cout << '\n';

    ShiftSupervisor supervisor("Kai Brooks", "E104", "2020-01-05", 61000.00, 3500.00);
    supervisor.print();
    cout << '\n';

    TeamLeader leader("Nia Lewis", "E105", "2021-03-18", 1, 28.00, 450.00, 20.0, 14.0);
    leader.print();
    cout << '\n';

    cout << "=== 2. FUNCTION HIDING DEMONSTRATION ===\n\n";
    cout << "--- dayWorker.print() ---\n";
    dayWorker.print();
    cout << "\n--- dayWorker.Employee::print() ---\n";
    dayWorker.Employee::print();

    cout << "\n--- leader.print() ---\n";
    leader.print();
    cout << "\n--- leader.ProductionWorker::print() ---\n";
    leader.ProductionWorker::print();
    cout << '\n';

    cout << "=== 3. VALID MUTATORS & BOUNDARY VALUES ===\n\n";
    emp.setHireDate("2024-05-01");
    cout << "Updated Employee Hire Date: " << emp.getHireDate() << '\n';

    dayWorker.setHourlyRate(0.0); 
    cout << "Boundary Worker Rate (0 allowed): $" << dayWorker.getHourlyRate() << '\n';

    supervisor.setAnnualBonus(0.0); 
    cout << "Boundary Supervisor Bonus (0 allowed): $" << supervisor.getAnnualBonus() << '\n';

    leader.setAttendedHours(25.0); 
    leader.setMonthlyBonus(0.0);
    cout << "Updated Leader Attended Hours (25 > 20): " << leader.getAttendedHours() << '\n';
    cout << "Boundary Leader Bonus (0 allowed): $" << leader.getMonthlyBonus() << "\n\n";

    cout << "=== 4. INVALID INPUT & INVARIANT PROTECTION ===\n\n";

  
    try {
        Employee badEmp("   ", "E999", "2024-01-01");
    }
    catch (const invalid_argument& e) {
        cout << "Caught invalid Employee name: " << e.what() << '\n';
    }

    try {
        dayWorker.setShift(3);
    }
    catch (const invalid_argument& e) {
        cout << "Caught invalid Worker shift: " << e.what()
            << " | Shift stayed: " << dayWorker.getShift() << '\n';
    }

    try {
        supervisor.setAnnualBonus(-500.0);
    }
    catch (const invalid_argument& e) {
        cout << "Caught invalid Supervisor bonus: " << e.what()
            << " | Bonus stayed: $" << supervisor.getAnnualBonus() << '\n';
    }

    try {
        leader.setRequiredHours(-5.0);
    }
    catch (const invalid_argument& e) {
        cout << "Caught invalid Leader hours: " << e.what()
            << " | Required hours stayed: " << leader.getRequiredHours() << '\n';
    }

    return 0;
}