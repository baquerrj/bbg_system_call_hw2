#include "read.h"

void read( file_t* p_file, char* p_action, char* p_input )
{
   if( NULL == p_file->file || (0 != strcmp(p_file->name, p_input)) )
   {
      fprintf( stderr, "Error reading file \"%s\": No such file or directory.\n",
               p_input );
      return;      
   }
   else if( 0 != strcmp("read", p_action))
   {
      printf( "Invalid action!" );
      return;
   }
   if( READ != p_file->mode )
   {
      fprintf( stderr, "Error reading file \"%s\": Permission denied.\n",
            p_file->name );
      return;
   }
   char str[MAX_INPUT_LENGTH];
   while( NULL != fgets( str, MAX_INPUT_LENGTH, p_file->file ) )
   {
      puts( str );
   }
   rewind( p_file->file );
   return;
}
