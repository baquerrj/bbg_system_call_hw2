
#include "write.h"


void close( file_t* p_file, char* p_action, char* p_input )
{
   if( NULL == p_file->p_file )
   {
      printf( "No open file...\n" );
      return;
   }
   if( 0 == strcmp( "close", p_action ) )
   {
      if( 0 == fclose( p_file->p_file ) )
      {
         printf( "Closing file \"%s\"\n", p_file->name );
         p_file->mode = NONE;
         p_file->p_file = NULL;
      }
      else
      {
         printf( "Something went wrong! Close unsucessful...\n" );
      }
      return;
   }
   else
   {
      printf( "Invalid action type!\n" );
   }
   return;
}
