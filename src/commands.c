#include "commands.h" 
#include "allocate.h"
/* I haven't figured out getting comannd line input
 * to be of variable size. Right now, I need the entries
 * in the command table to all be the same length for 
 * my approach to indexing into the table and picking
 * out the correct command to work */

static const char cmdTableStrings[] =
   "allocate free open";


uint8_t maxOffset = sizeof( cmdTableStrings ) / sizeof( char* );
fp_function_t cmdTable[] =
{
   allocate
};

uint32_t getCmd( const char* p_input, uint64_t in1, uint64_t in2 )
{
   char* p_cmd;
   uint32_t cmdOffset = 0;

   p_cmd = strstr( cmdTableStrings, p_input );

   printf( "   p_cmd points to address    %p\n\r", p_cmd );
   printf( "   cmdTableStrings at address %p\n\r", cmdTableStrings );
   fflush( stdout );

   if( NULL != p_cmd )
   {
      /* p_cmd points to a valid command found in
       * command table of strings. Compute offset
       * to get entry of command in the table of
       * function pinters */
      cmdOffset = ( p_cmd - cmdTableStrings ) / 6; /* This is a magic number...
                                                    * I'm not sure how to calculate
                                                    * it reliably */
      printf( "   cmdOffset = %u\n\r", cmdOffset );
      if( maxOffset < cmdOffset )
      {
         printf( "Offset into command table is too large!\n\rOffset equals %u",
                  cmdOffset );
         fflush( stdout );
         return 0;
      }
      else
      {
         return cmdTable[ cmdOffset ]( in1, in2 );
      }
   }
      printf( "Illegal command!\n\r" );
      fflush( stdout );
      return 0;
}

