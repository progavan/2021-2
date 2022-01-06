#ifndef FILEMAILINGLISTENTRY_H_INCLUDED
#define FILEMAILINGLISTENTRY_H_INCLUDED
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
fread( szBuffer, sizeof(char),255, fpIn );
if ( feof(fpIn) )
  return false;
setFirstName( szBuffer );
 #if 1 //LMC 2021.12.29
  printf("\n%s\n",szBuffer);
 #endif
fread( szBuffer, sizeof(char),255, fpIn );
setFirstName( szBuffer );
fread( szBuffer, sizeof(char),255, fpIn );
setAddress1( szBuffer );
fread( szBuffer, sizeof(char),255, fpIn );
setAddress2( szBuffer );
fread( szBuffer, sizeof(char),255, fpIn );
setCity( szBuffer );
fread( szBuffer, sizeof(char),255, fpIn );
setState( szBuffer );
fread( szBuffer, sizeof(char),255, fpIn );
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
};


#endif // FILEMAILINGLISTENTRY_H_INCLUDED
