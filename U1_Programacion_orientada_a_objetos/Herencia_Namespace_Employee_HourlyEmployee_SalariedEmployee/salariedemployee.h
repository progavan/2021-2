#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "employee.h"

using std::string;

namespace SavitchEmployees
{
    class SalariedEmployee : public Employee {
    private:
        double salary; // weekly
    public:
        SalariedEmployee();
        SalariedEmployee(
            string theName, string theSsn,
            double theWeeklySalary);
        double get_salary() const;
        void set_salary(double newSalary);
        void print_check();
    };
}// SavitchEmployees

#endif // SALARIEDEMPLOYEE_H
