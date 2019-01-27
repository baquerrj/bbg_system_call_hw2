#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>

#define READ   0x0001   /* Ready-Only */
#define WRITE  0x0002   /* Write-Only */
#define READU  0x0003   /* Read and Update */
#define WRITEU 0x0004   /* Write and Update */
#define APPEND 0x0005   /* Append */
#define APPNDU 0x0006   /* Append and Update */
#define NONE   0xdead   /* Unitialized */ 

typedef struct file_s {
    int   mode;
    char  name[50];
    FILE* p_file;
} file_t;

typedef void (*fp_file)( file_t*, char*, char* );

#endif /* TYPES_H */
