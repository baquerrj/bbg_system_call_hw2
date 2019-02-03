
#include "write.h"

void write( file_t* p_file, char* p_action, char* p_input )
{
   if( NULL  == p_file->p_file )
   {
      fprintf( stderr, "Error writing to file: No such file or directory.\n" );
      return;
   }
   if( READ == p_file->mode )
   {
      fprintf( stderr, "Error writing to file \"%s\": Permission denied.\n",
               p_file->name );
      return;
   }
   if( 0 == strcmp( "write", p_action ) )
   {
      int num = 0;
      if( 0 > ( num = fprintf( p_file->p_file, "%s\n", p_input ) ) )
      {
         perror( "ERROR" );
         return;
      }
      fprintf( stdout, "Wrote %u characters to file \"%s\".\n",
               num, p_file->name );
   }
   else
   {
      printf( "Invalid action type!\n" );
   }
   return;
}
