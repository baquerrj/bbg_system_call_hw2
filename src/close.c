
#include "close.h"


void close( file_t* p_file, char* p_action, char* p_input )
{
   if( (NULL == p_file->file) || (0 != strcmp(p_file->name, p_input)) )
   {
      fprintf( stderr, "Error closing file \"%s\": No such file or directory.\n",
               p_input );
      return;
   }
   if( 0 == strcmp( "close", p_action ) )
   {
      if( 0 == fclose( p_file->file ) )
      {
         printf( "Closing file \"%s\".\n",  p_input );
         
         p_file->mode = NONE;
         p_file->file = NULL;
      }
      else
      {
         fprintf( stderr, "Error closing file \"%s\": %s.\n", p_input, strerror( errno ));
      }
      return;
   }
   else
   {
      fprintf( stderr, "Invalid action type!\n" );
   }
   return;
}
