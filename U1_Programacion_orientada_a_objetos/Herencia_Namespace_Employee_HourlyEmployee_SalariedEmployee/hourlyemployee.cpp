// hourlyemployee.cpp
#include <string>
#include <cstdlib>
#include <iostream>
#include "hourlyemployee.h"
using std::string;
using std::cout;
using std::endl;

namespace SavitchEmployees
{
    HourlyEmployee::HourlyEmployee() : Employee(), wageRate(0), hours(0)
    {
        // deliberatelly empty
    }

    HourlyEmployee::HourlyEmployee(
          string theName, string theSsn,
          double theWageRate, double theHours) :
    Employee(theName, theSsn),
    wageRate(theWageRate),hours(theHours)
    {
        // deliberatelly empty
    }

    void HourlyEmployee::set_rate(
                         double newWageRate)
    {
        wageRate = newWageRate;
    }

    double HourlyEmployee::get_rate() const
    {
        return wageRate;
    }

    void HourlyEmployee::set_hours(
                         double hoursWorked)
    {
        hours = hoursWorked;
    }

    double HourlyEmployee::get_hours() const
    {
        return hours;
    }

    void HourlyEmployee::print_check()
    {
        set_netPay(hours * wageRate);
        cout << "\n_________________________________________________________\n";
        cout << "Pay to the order of " << get_name() << endl;
        cout << "The sum of " << get_netPay() << " Dollars\n";
        cout << "_________________________________________________________\n";
        cout << "Check Stub: NOT NEGOTIABLE\n";
        cout << "Employee Number: " << get_ssn() << endl;
        cout << "Hourly Employee. \nHours worked: " << hours
             << " Rate: " << wageRate << " Pay: " << get_netPay() << endl;
        cout << "_________________________________________________________\n";
    }

}// SavitchEmployees

