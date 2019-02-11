
#include "write.h"


void open( file_t* p_file, char* p_action, char* p_input )
{
   if( NONE != p_file->mode )
   {
      printf( "File: \"%s\" already open...\n", p_input );
      return;
   }
   if( 0 == strcmp( "open", p_action ) )
   {
      if( NULL != (p_file->file = fopen( p_input, "a" ) ) )
      {
         p_file->mode = APPEND;
         strcpy( p_file->name, p_input );
         printf( "Opened file \"%s\" in append mode...\n", p_file->name );
      }
      else if( ferror( p_file->file ) )
      {
         fprintf( stderr, "Error opening file \"%s\".\n",
                  p_file->name );
         perror( "ERROR" );
         clearerr( p_file->file );
      }
      return;
   }
   else
   {
      printf( "Invalid action type!\n" );
   }
   return;
}
