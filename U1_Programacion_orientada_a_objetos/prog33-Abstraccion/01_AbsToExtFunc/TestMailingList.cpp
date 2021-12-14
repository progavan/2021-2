/** TestMailingList.cpp */
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
int main(int argc, char **argv)
{
 int choice = 0;
 printf(“Enter 1 to use a file-based mailing list\n”);
 printf(“Enter 2 to enter data from the command line\n”);
 scanf(“%d”, &choice );
 if ( choice == 1 )
 {
   char szBuffer[ 256 ];
   printf(“Enter the file name: “);
   gets(szBuffer);
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
   printf(“Invalid option\n”);
 return 0;
}
