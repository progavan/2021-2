// employee.cpp
#include <string>
#include <cstdlib>
#include <iostream>
#include "employee.h"
using std::string;
using std::cout;
using std::exit;

namespace SavitchEmployees
{
    Employee::Employee() :
    name("No name yet"), ssn("No number yet"),
    netPay(0)
    {
        // deliberatelly empty
    }

    Employee::Employee(
    string theName, string theSsn) :
    name(theName), ssn(theSsn), netPay(0)
    {
        // deliberatelly empty
    }

    string Employee::get_name() const
    {
        return name;
    }

    string Employee::get_ssn() const
    {
        return ssn;
    }

    double Employee::get_netPay() const
    {
        return netPay;
    }

    void Employee::set_name(string newName)
    {
        name = newName;
    }

    void Employee::set_ssn(string newSsn)
    {
        ssn = newSsn;
    }

    void Employee::set_netPay(double newNetPay)
    {
        netPay = newNetPay;
    }

    void Employee::print_check() const
    {
        cout << "\nEmployee::print_check";
        cout <<"\n_________________________________________________________\n";
        cout <<"\nERROR: print_check FUNCTION CALLED FOR AN \n"
             <<"UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
             <<"Check with the author of the program about this bug.\n";
        cout <<"\n_________________________________________________________\n";
        exit(1);
    }

}// SavitchEmployees
