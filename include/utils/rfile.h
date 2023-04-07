#ifndef _RFILE_H_
#define _RFILE_H_

#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

char* buffer = NULL;

#define READ_FILE(path, size)                           \
    {                                                   \
        buffer = (char*)malloc(size);                   \
        FILE *fp = fopen(path, "r");                    \
        if (fp == NULL) {                               \
            printf("Error opening file\n");             \
            exit(1);                                    \
        }                                               \
        fseek(fp, 0, SEEK_END);                         \
        long file_size = ftell(fp);                     \
        fseek(fp, 0, SEEK_SET);                         \
        if(file_size > size)                            \
            buffer = (char*)realloc(buffer, file_size); \
        if (buffer == NULL) {                           \
            printf("Error allocating memory\n");        \
            exit(1);                                    \
        }                                               \
        fread(buffer, file_size, 1, fp);                \
        buffer[file_size] = EOF;                        \
    }

#define FREE_BUFFER()                                   \
    {                                                   \
        free(buffer);                                   \
    }

#endif