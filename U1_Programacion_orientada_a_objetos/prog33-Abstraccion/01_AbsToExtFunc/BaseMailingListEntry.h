#ifndef BASEMAILINGLISTENTRY_H_INCLUDED
#define BASEMAILINGLISTENTRY_H_INCLUDED
#include <string>
#include <iostream>
#include <stdio.h>
class BaseMailingListEntry
{
private:
std::string sFirstName;
std::string sLastName;
std::string sAddressLine1;
std::string sAddressLine2;
std::string sCity;
std::string sState;
std::string sZipCode;
public:
BaseMailingListEntry(void)
{
}
BaseMailingListEntry( const BaseMailingListEntry& aCopy )
{
sFirstName = aCopy.sFirstName;
sLastName = aCopy.sLastName;
sAddressLine1 = aCopy.sAddressLine1;
sAddressLine2 = aCopy.sAddressLine2;
sCity = aCopy.sCity;
sState = aCopy.sState;
sZipCode = aCopy.sZipCode;
}
virtual bool First(void) = 0; // A pure virtual function
virtual bool Next(void) = 0; // Another pure virtual function
// Accessors
std::string getFirstName() { return sFirstName; };
std::string getLastName() { return sLastName; };
std::string getAddress1() { return sAddressLine1; };
std::string getAddress2() { return sAddressLine2; };
std::string getCity()
{ return sCity; };
std::string getState()
{ return sState; };
std::string getZipCode()
{ return sZipCode; };
void setFirstName(const char *strFirstName)
{ sFirstName = strFirstName; };
void setLastName(const char *strLastName)
{ sLastName = strLastName; };
void setAddress1( const char *strAddress1)
{ sAddressLine1 = strAddress1; };
void setAddress2( const char *strAddress2)
{ sAddressLine2 = strAddress2; };
void setCity(const char *strCity)
{ sCity = strCity; };
void setState(const char *strState)
{ sState = strState; };
void setZipCode( const char *strZipCode )
{ sZipCode = strZipCode; };
};//end class BaseMailingListEntry



#endif // BASEMAILINGLISTENTRY_H_INCLUDED
