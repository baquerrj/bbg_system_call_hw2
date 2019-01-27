
#include "write.h"


void write( file_t* p_file, char* p_action, char* p_input )
{
   if( NULL == p_file->p_file )
   {
      printf( "No file open...\n" );
      return;
   }
   else if( READ == p_file->mode )
   {
      printf( "File is read-only...\n" );
      return;
   }
   if( 0 == strcmp( "write", p_action ) )
   {
      if( 0 > fprintf( p_file->p_file, "%s\n", p_input ) )
      {
         perror( "ERROR" );
         return;
      }
      printf( "Write to %s successful!\n", p_file->name );
   }
   else
   {
      printf( "Invalid action type!\n" );
   }
   return;
}
