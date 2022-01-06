/** 02_ch_abstraction.cpp
 * REF.:
 * Technique 2: Using Abstraction to Extend Functionality,
 * page 13 from (For dummies) Matthew Telles -
 * C++ Timesaving Techniques For Dummies-Wiley (2005).pdf
 */
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000    /* maximum input line length */
int KnR_getline(char line[], int maxline);

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
 { /** empty */ }
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
 std::string getCity() { return sCity; };
 std::string getState() { return sState; };
 std::string getZipCode() { return sZipCode; };
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
};/*end class BaseMailingListEntry */

/**
 * We do no error-checking in any
 * of this code (that’s to avoid making it any larger).
 */
class FileMailingListEntry : public BaseMailingListEntry
{
 FILE *fpIn;
public:
 FileMailingListEntry( const char *strFileName )
 {
  fpIn = fopen(strFileName, "r");
 }
 virtual bool ReadEntry(void)
 {
  char szBuffer[ 256 ];
  fread( szBuffer, sizeof(char), 255, fpIn );
  if ( feof(fpIn) )
    return false;
  setLastName( szBuffer );
 #if 1 //LMC 2021.12.29
  printf("\n%s\n",szBuffer);
 #endif
  fread( szBuffer, sizeof(char), 255, fpIn );
  setFirstName( szBuffer );
  fread( szBuffer, sizeof(char), 255, fpIn );
  setAddress1( szBuffer );
  fread( szBuffer, sizeof(char), 255, fpIn );
  setAddress2( szBuffer );
  fread( szBuffer, sizeof(char), 255, fpIn );
  setCity( szBuffer );
  fread( szBuffer, sizeof(char), 255, fpIn );
  setState( szBuffer );
  fread( szBuffer, sizeof(char), 255, fpIn );
  setZipCode( szBuffer );
  return true;
 }

 virtual bool First(void)
 {
  // Move to the beginning of the file, read in the pieces
  fseek( fpIn, 0L, SEEK_SET );
  return ReadEntry();
 }

 virtual bool Next(void)
 {
  // Just get the next one in the file
  return ReadEntry();
 }
};/* end class FileMailingListEntry */

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
  //fgets(szBuffer,32,stdin);
  //getline(&line,&len,stdin);
  //strcpy(szBuffer,line);
  //scanf("%s",szBuffer);
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
 #if 0 //LMC 2021.12.26
  char szBuffer[ 80 ];
 #else
  char szBuffer[ 80 ] = { 0 };
 #endif
  if ( GetALine( "Enter the last name of the person: ", szBuffer ) != true )
    return false;
  setLastName( szBuffer );
  GetALine("Enter the first name of the person: ", szBuffer );
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
 CommandLineMailingListEntry() { /** empty */}
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

void ProcessEntries( BaseMailingListEntry *pEntry )
{
 bool not_done = pEntry->First();
 while ( not_done )
 {
   // Do something with the entry here.
   // Get the next one
   not_done = pEntry->Next();
 }
}

/** REF.: Brian W. Kernighan, Dennis M. Ritchie, The ANSI C Programming Language,
 * page 30. Brian W. Kernighan, Dennis M. Ritchie -
 * The ANSI C Programming Language-Prentice Hall (1988).pdf
 * getline: read a line into s, return length.
 */
int KnR_getline(char s[],int lim)
{
 int c, i;
 for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
   s[i] = c;
 if (c == '\n') {
   s[i] = c;
  ++i;
 }
 s[i] = '\0';
 return i;
}


int main(int argc, char **argv)
{
 int choice = 0;
#if 1 // LMC 2021.12.26
 char linea[MAXLINE];
#endif
 printf("Enter 1 to use a file-based mailing list\n");
 printf("Enter 2 to enter data from the command line\n");
#if 0 // LMC 2021.12.26
 scanf("%d", &choice );
#else
 scanf("%d%*c", &choice );
#endif
 if ( choice == 1 )
 {
   char szBuffer[ 256 ];
   printf("Enter the file name: ");
  #if 0 //LMC 2021.12.25
   gets(szBuffer);
  #else
   //fgets(szBuffer,sizeof(szBuffer)/sizeof(szBuffer[0]),stdin);
   KnR_getline(linea,MAXLINE);
   strcpy(szBuffer,linea);
   // Remove trailing carriage return
   szBuffer[strlen(szBuffer)-1] = 0;
  #endif
   FileMailingListEntry fmle(szBuffer);
   ProcessEntries( &fmle );
 }
 else
 if ( choice == 2 )
 {
   CommandLineMailingListEntry cmle;
   ProcessEntries( &cmle );
 }
 else
   printf("Invalid option\n");
 return 0;
}/*end main()*/






