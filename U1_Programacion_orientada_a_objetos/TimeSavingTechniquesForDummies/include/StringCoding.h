#ifndef STRINGCODING_H_INCLUDED
#define STRINGCODING_H_INCLUDED

#include <stdio.h>
#include <string>
class StringCoding
{
private:
// The key to use in encrypting the string
std::string sKey;
public:
// The constructor, uses a preset key
StringCoding( void )
{
sKey = "ATest";
}
// Main constructor, allows the user to specify a key
StringCoding( const char *strKey )
{
if ( strKey )
sKey = strKey;
else
sKey = "ATest";
}
// Copy constructor
StringCoding( const StringCoding& aCopy )
{
sKey = aCopy.sKey;
}
public:
// Methods
std::string Encode( const char *strIn );
std::string Decode( const char *strIn );
private:
std::string Xor( const char *strIn );
};

#endif // STRINGCODING_H_INCLUDED
