#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <errno.h>

#define MAX_INPUT_LENGTH 100

#define READ   0x0001   /* Ready-Only */
#define WRITE  0x0002   /* Write-Only */
#define APPEND 0x0005   /* Append */
#define NONE   0xdead   /* Unitialized */ 

typedef struct file_s {
    int   mode;
    char  name[50];
    FILE* file;
} file_t;

typedef void (*fp_file)( file_t*, char*, char* );

int errno;

#endif /* TYPES_H */
