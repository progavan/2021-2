#ifndef COMMANDLINEMAILINGLISTENTRY_H_INCLUDED
#define COMMANDLINEMAILINGLISTENTRY_H_INCLUDED
#include "BaseMailingListEntry.h"

class CommandLineMailingListEntry : public BaseMailingListEntry
{
private:
bool GetALine( const char *prompt, char *szBuffer )
{
 puts(prompt);
 #if 0 //LMC 2021.12.25
  gets(szBuffer);
 #else
  char line[MAXLINE];
  fflush(stdin);
  KnR_getline(line,MAXLINE);
  strcpy(szBuffer,line);
 #endif
 // Remove trailing carriage return
 szBuffer[strlen(szBuffer)-1] = 0;
 if ( strlen(szBuffer) )
   return true;
 return false;
}
bool GetAnEntry()
{
 char szBuffer[ 80 ];
 if ( GetALine( "Enter the last name of the person: ",
      szBuffer ) != true )
 return false;
 setLastName( szBuffer );
 GetALine("Enter the first name of the person: ",szBuffer );
 setFirstName( szBuffer );
 GetALine("Enter the first address line: ", szBuffer );
 setAddress1(szBuffer);
 GetALine("Enter the second address line: ", szBuffer );
 setAddress2(szBuffer);
 GetALine("Enter the city: ", szBuffer );
 setCity(szBuffer);
 GetALine("Enter the state: ", szBuffer);
 setState(szBuffer);
 GetALine("Enter the zip code: ", szBuffer );
 setZipCode( szBuffer);
 return true;
}
public:
 CommandLineMailingListEntry() { }
 virtual bool First(void)
 {
  printf("Enter the first name for the mailing list:\n");
  return GetAnEntry();
 }
 virtual bool Next(void)
 {
  printf("Enter the next name for the mailing list:\n");
  return GetAnEntry();
 }
};/*end class CommandLineMailingListEntry */


#endif // COMMANDLINEMAILINGLISTENTRY_H_INCLUDED
