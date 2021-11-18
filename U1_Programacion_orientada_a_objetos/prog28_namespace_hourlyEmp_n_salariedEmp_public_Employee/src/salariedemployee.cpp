// salariedemployee.cpp
#include <iostream>
#include <string>
#include "salariedemployee.h"
using std::string;
using std::cout;
using std::endl;

namespace SavitchEmployees
{
    SalariedEmployee::SalariedEmployee() :
    Employee(), salary(0)
    {
        // deliberatelly empty
    }

    SalariedEmployee::SalariedEmployee(
        string theName, string theNumber,
        double theWeeklyPay):
    Employee(theName, theNumber),
    salary(theWeeklyPay)
    {
        // deliberatelly empty
    }

    double SalariedEmployee::get_salary() const
    {
        return salary;
    }

    void SalariedEmployee::set_salary(double newSalary)
    {
        salary = newSalary;
    }

    void SalariedEmployee::print_check()
    {
        set_netPay(salary);
        cout <<"\n_________________________________________________________\n";
        cout <<"Pay to the order of " << get_name() << endl;
        cout <<"The sum of " << get_netPay() << " Dollars\n";
        cout <<"_________________________________________________________\n";
        cout <<"Check Stub: NOT NEGOTIABLE\n";
        cout <<"Employee Number: " << get_ssn() << endl;
        cout <<"Salaried Employee. Regular Pay: "
             << salary << endl;
        cout <<"_________________________________________________________\n";
    }
} // SavitchEmployees
