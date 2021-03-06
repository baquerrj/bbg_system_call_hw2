#include "read_one.h"

void read_one( file_t* p_file, char* p_action, char* p_input )
{
   if( NULL == p_file->file || (0 != strcmp(p_file->name, p_input)) )
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
   if( !feof( p_file->file ) )
   {
      c = fgetc( p_file->file );
      if( ferror( p_file->file ) )
      {
         fprintf( stderr, "Error reading file \"%s\".\n",
                  p_file->name );
         perror( "ERROR" );
         clearerr( p_file->file );
         rewind( p_file->file );
         return;
      }
      printf( "%c\n", c );
   }
   rewind( p_file->file );
   return;
}
