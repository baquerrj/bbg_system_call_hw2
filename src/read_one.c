#include "read_one.h"

void read_one( file_t* p_file, char* p_action, char* p_input )
{
   if( NULL == p_file->p_file || (0 != strcmp(p_file->name, p_input)) )
   {
      fprintf( stderr, "Error reading file \"%s\"\n: No such file or directory\n",
               p_input );
      return;      
   }
   else if( 0 != strcmp("read_one", p_action))
   {
      printf( "Invalid action!" );
      return;
   }
   if( READ != p_file->mode )
   {
      fprintf( stderr, "Error reading file \"%s\": Permssion denied.\n",
                  p_file->name );
         p_file->mode = NONE;
         return;
   }
   char c;
   if( !feof( p_file->p_file ) )
   {
      c = fgetc( p_file->p_file );
      printf( "%c\n", c );
   }
   return;
}
