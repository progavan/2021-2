#ifndef ARITMETICADHORADELDIA_H_INCLUDED
#define ARITMETICADHORADELDIA_H_INCLUDED
#include <iostream>

class AritDHoraDia {
public:
 short int hora;
 short int min;
 short int sec;
 int TotalSeconds;
 AritDHoraDia();
 AritDHoraDia(short int hour,short int Minute,short int seconds);
 AritDHoraDia(int totalSec);
 AritDHoraDia operator+(AritDHoraDia rhs);
 AritDHoraDia operator-(AritDHoraDia rhs);
friend std::ostream& operator<<(std::ostream&,AritDHoraDia&);
};/*end class AritDHoraDia */

#endif // ARITMETICADHORADELDIA_H_INCLUDED
