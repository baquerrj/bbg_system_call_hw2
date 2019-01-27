#include "file_actions.h" 
#include "write.h"
#include "open.h"
#include "close.h"
#include "change_mode.h"

static const char action_strings[] =
   "open close change write";


uint8_t maxOffset = sizeof( action_strings ) / sizeof( char* );
fp_file actionTable[] =
{
   open,
   close,
   change_mode,
   write 
};

void file_action( file_t* p_file, char* p_action, char* p_input )
{
   //printf( "Attempting to decode action..\n" );
   printf( "New action is %s\n", p_action );
   char* p_cmd;
   uint32_t cmd_offset = 0;
   
   p_cmd = strstr( action_strings, p_action );
   
   //printf( "   maxOffset = %u\n", maxOffset );
   //fflush( stdout );

   if( NULL != p_cmd )
   {
      /* p_cmd points to a valid command found in
       * command table of strings. Compute offset
       * to get entry of command in the table of
       * function pinters */
      cmd_offset = ( p_cmd - action_strings ) / 5; /* nThis is a magic number...
                                                    * I'm not sure how to calculate
                                                    * it reliably */
      //printf( "   cmd_offset = %u\n\r", cmd_offset );
      if( maxOffset < cmd_offset )
      {
         printf( "Offset into command table is too large!\n\rOffset equals %u",
                  cmd_offset );
         fflush( stdout );
         return;
      }
      else
      {
         actionTable[ cmd_offset ]( p_file, p_action, p_input );
         return;
      }
   }
      printf( "Illegal command!\n\r" );
      fflush( stdout );
      return;
}

