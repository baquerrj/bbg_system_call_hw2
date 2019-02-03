#include "change_mode.h"

void change_mode( file_t* p_file, char* p_action, char* p_input )
{
   printf( "Attempting to change file mode...\n" );
   if( NULL == p_file->file || NONE == p_file->mode )
   {
      printf(" No file open...\n" );
      return;
   }
   if( 0 == strcmp( "change", p_action ) )
   {
      if( 0 == strcmp( "read", p_input ) )
      {
         p_file->file = freopen( p_file->name, "r", p_file->file );
         p_file->mode = READ;
      }
      else if( 0 == strcmp( "write", p_input ) )
      {
         p_file->file = freopen( p_file->name, "w", p_file->file );
         p_file->mode = WRITE;
      }
      else if( 0 == strcmp( "append", p_input ) )
      {
         p_file->file = freopen( p_file->name, "a", p_file->file );
         p_file->mode = APPEND;
      }

      if( NULL == p_file->file )
      {
         perror( "ERROR" );
         p_file->mode = NONE;
      }
      
      /* Determine if FILE mode changed */
      switch( p_file->mode )
      {
         case READ:
            printf( "Re-opened file \"%s\" in read mode\n", p_file->name );
            break;
         case WRITE:
            printf( "Re-opened file \"%s\" in write mode\n", p_file->name );
            break;
         case APPEND:
            printf( "Re-opened file \"%s\" in append mode\n", p_file->name );
            break;
         default:
            fprintf( stderr, "Error changing permissions\n" );
            break;
      }
   }
   return;
}
