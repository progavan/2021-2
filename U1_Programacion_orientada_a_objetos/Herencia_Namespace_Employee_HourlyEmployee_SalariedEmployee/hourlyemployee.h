// hourlyemployee.h
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include "employee.h"

using std::string;

namespace SavitchEmployees
{
    class HourlyEmployee : public Employee {
    private:
        double wageRate;
        double hours;
    public:
        HourlyEmployee();
        HourlyEmployee(string theName, string theSsn,
                   double theWageRate, double theHur);
        void set_rate(double newWageRate);
        double get_rate() const;
        void set_hours(double hoursWorked);
        double get_hours() const;
        void print_check();
        // You only list the declaration of an
        // inherited member function if you
        // want to change the definition of the
        // function.
    };
}// SavitchEmployees

#endif // HOURLYEMPLOYEE_H

