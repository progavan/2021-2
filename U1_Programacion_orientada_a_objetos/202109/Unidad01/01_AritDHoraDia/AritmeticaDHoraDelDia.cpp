/** AritmeticaDHoraDelDia.cpp */
#include <cmath>
#include "../include/AritmeticaDHoraDelDia.h"

AritDHoraDia :: AritDHoraDia() {/** deliberadamente vac\'io */}
AritDHoraDia :: AritDHoraDia(short int hour,
                             short int Minute,
                             short int seconds)
:hora(hour),min(Minute),sec(seconds){
 TotalSeconds = 60*60*hora + 60*min + sec;
}
AritDHoraDia :: AritDHoraDia(int totalSec)
:TotalSeconds(abs(totalSec)){
 int resto;
 hora = TotalSeconds / (60*60);
 resto = TotalSeconds % (60*60);
 min = resto / 60;
 sec = resto % 60;
}
AritDHoraDia AritDHoraDia :: operator+(AritDHoraDia rhs){
 AritDHoraDia Result(TotalSeconds + rhs.TotalSeconds);
 return Result;
}
AritDHoraDia AritDHoraDia :: operator-(AritDHoraDia rhs){
 AritDHoraDia Result(TotalSeconds - rhs.TotalSeconds);
 return Result;
}

bool test_num(short int N){
 if(N < 10)
   return true;
 return false;
}
std::ostream& operator<<(std::ostream& out,AritDHoraDia& rhs){
 if(test_num(rhs.hora))
   out << "0";
 out << rhs.hora << ":";
 if(test_num(rhs.min))
   out << "0";
 out << rhs.min << ":";
 if(test_num(rhs.sec))
   out << "0";
 out << rhs.sec;
 return out;
}




