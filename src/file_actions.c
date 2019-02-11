#include "file_actions.h" 
#include "write.h"
#include "open.h"
#include "close.h"
#include "change_mode.h"
#include "read.h"
#include "read_one.h"

static const char action_strings[] =
   "open  close  change  write  read  read_one";


fp_file actionTable[] =
{
   open,
   close,
   change_mode,
   write,
   read,
   read_one
};

uint8_t maxOffset = (sizeof( actionTable ) / sizeof( char* )) - 1;

void file_action( file_t* p_file, char* p_action, char* p_input )
{
   char* p_cmd;
   uint32_t cmd_offset = 0;
   p_cmd = strstr( action_strings, p_action );

   if( NULL != p_cmd )
   {
      /* p_cmd points to a valid command found in
       * command table of strings. Compute offset
       * to get entry of command in the table of
       * function pinters */
      cmd_offset = ( p_cmd - action_strings ) / 6;  
                                                    
      if( maxOffset < cmd_offset )
      {
         printf( "Offset into command table is too large!\n\rOffset equals %u\n",
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

