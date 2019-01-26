
/* System Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "commands.h"

#define MAX_INPUT_LENGTH 20


int main( void )
{
   /* Initialize pointers */
   FILE* fp = NULL;
   char* p_input = (char*) calloc( MAX_INPUT_LENGTH, sizeof( char* ) );
   char* p_cmd = (char*) calloc( MAX_INPUT_LENGTH, sizeof( char* ) );
   
   /* Initialize input arguments */
   uint64_t in1 = 0;
   uint64_t in2 = 0;
   while( 1 )
   {
      printf( ">  " );
      if( NULL != fgets( p_input, MAX_INPUT_LENGTH, stdin ) )
      {
         if( 0 == strcmp( "quit\n", p_input ) )
         {
            /* Exiting...*/
            return 0;
         }
         else if( 0 == strcmp( "open\n", p_input ) )
         {
            if( NULL == fp )
            {
               printf( "opening a file...\n" );
               fp = fopen( "/tmp/test_file", "w+" );
            }
         }
         else if( 0 == strcmp( "close\n", p_input ) )
         {  
            if( NULL != fp )
            {
               printf( "closing file...\n" );
               fclose( fp );
            }
         }
         else
         {
            sscanf( p_input, "%s %lx %lx", p_cmd, &in1, &in2 );
            getCmd( p_cmd, in1, in2 );
            continue;
         }
         continue;
      }
      continue;

   }

/*
   FILE* p_fi = fopen("/tmp/test_file", "w+");

   fprintf( p_fi, "test writing to file using fprintf... \n");

   fputs( "test writing to file using fputs... \n", fputs);

   fclose( p_fi );
   */
   return 1;
}
