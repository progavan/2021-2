/** ch1_1.cpp */
#include <iostream>
#include "../include/StringCoding.h"

int main(int argc, char **argv)
{
if ( argc < 2 )
{
printf("Usage: ch1_1 inputstring1 [inputstring2...]\n");
exit(1);
}
StringCoding key("XXX");
for ( int i=1; i<argc; ++i )
{
std::string sEncode = key.Encode( argv[i] );
printf("Input String : [%s]\n", argv[i] );
printf("Encoded String: [%s]\n", sEncode.c_str() );
std::string sDecode = key.Decode( sEncode.c_str() );
printf("Decoded String: [%s]\n", sDecode.c_str() );
}
printf("%d strings encoded\n", argc-1);
return 0;
}/*end main()*/

