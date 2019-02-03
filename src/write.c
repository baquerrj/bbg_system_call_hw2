
#include "write.h"

void write( file_t* p_file, char* p_action, char* p_input )
{
   if( NULL  == p_file->file )
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
      if( 0 > fprintf( p_file->file, "%s\n", p_input ) )
      {
         perror( "ERROR" );
         return;
      }
   }
   else
   {
      printf( "Invalid action type!\n" );
   }
   return;
}
