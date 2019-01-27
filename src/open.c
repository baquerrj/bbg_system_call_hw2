
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
      if( NULL != (p_file->p_file = fopen( p_input, "a+" ) ) )
      {
         p_file->mode = APPNDU;
         strcpy( p_file->name, p_input );
         printf( "Opened file \"%s\" in append+ mode...\n", p_file->name );
      }
      else
      {
         perror( "ERROR" ); 
      }
      return;
   }
   else
   {
      printf( "Invalid action type!\n" );
   }
   return;
}