#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef uint32_t (*fp_function_t)( uint64_t, uint64_t );

uint32_t getCmd( const char* p_input, uint64_t in1, uint64_t in2 );


#endif /* COMMANDS_H */
