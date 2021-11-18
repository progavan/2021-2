/** StringCoding.cpp */
#include <iostream>
#include <string.h>
#include "../include/StringCoding.h"

std::string StringCoding::Xor( const char *strIn )
{
 std::string sOut = "";
#if 0 //LMC 2021.11.16
 int nIndex = 0;
#else
 unsigned int nIndex = 0;
#endif
 for ( int i=0; i<(int)strlen(strIn); ++i )
 {
   char c = (strIn[i] ^ sKey[nIndex]);
   sOut += c;
   nIndex ++;
   if ( nIndex == sKey.length() )
     nIndex = 0;
 }
 return sOut;
}
// For XOR encoding, the encode and decode methods are
// the same.
std::string StringCoding::Encode( const char *strIn )
{
return Xor( strIn );
}
std::string StringCoding::Decode( const char *strIn )
{
return Xor( strIn );
}

