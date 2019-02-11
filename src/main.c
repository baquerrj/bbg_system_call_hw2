
/* System Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "file_actions.h"
#include "types.h"

int main( void )
{
   /* Initialize pointers */
   file_t* p_file = (file_t*) malloc( sizeof( file_t ) );
   p_file->file = NULL;
   p_file->mode   = NONE;

   char* p_input = (char*) calloc( sizeof( char ), MAX_INPUT_LENGTH );
   char* p_arg1  = (char*) calloc( sizeof( char ), MAX_INPUT_LENGTH );
   char* p_arg2  = (char*) calloc( sizeof( char ), MAX_INPUT_LENGTH );
   
   printf( "Hello World!\nWriting interesting string\nInteresting enough?\n" );
   while( 1 )
   {
      printf( "\n>  " );
      if( NULL != fgets( p_input, MAX_INPUT_LENGTH, stdin ) )
      {
         if( 0 == strcmp( "quit\n", p_input ) )
         {
            printf( "Freeing memory.\n" );
            free( p_file );
            free( p_input );
            free( p_arg1 );
            free( p_arg2 );
            printf( "Exiting...\n" );
            /* Exiting...*/
            return 0;
         }
         else
         {
            memset( p_arg1, 0x00, MAX_INPUT_LENGTH - 1);
            memset( p_arg2, 0x00, MAX_INPUT_LENGTH - 1);
            sscanf( p_input, "%s %[^\n]", p_arg1, p_arg2 );
            printf( "\"%s %s\"\n", p_arg1, p_arg2 );
            file_action( p_file, p_arg1, p_arg2 );
            continue;
         }
         continue;
      }
      continue;

   }

   return 1;
}
