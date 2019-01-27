#ifndef FILE_ACTIONS_H
#define FILE_ACTIONS_H

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "types.h"

//typedef void (*fp_file)( FILE*, char*, char* );

void file_action( file_t* p_file, char* p_action, char* p_input );

#endif /* FILE_ACTIONS_H */
