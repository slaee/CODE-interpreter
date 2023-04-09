#ifndef _RFILE_H_
#define _RFILE_H_

#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

char* buffer = NULL;

#define READ_FILE(path)                                 \
    {                                                   \
        buffer = (char*)malloc(BUFFER_SIZE);            \
        FILE *fp = fopen(path, "rb");                   \
        if (fp == NULL) {                               \
            printf("Error opening file\n");             \
            exit(1);                                    \
        }                                               \
        fseek(fp, 0, SEEK_END);                         \
        long file_size = ftell(fp);                     \
        fseek(fp, 0, SEEK_SET);                         \
        if(file_size > BUFFER_SIZE)                     \
            buffer = (char*)realloc(buffer, file_size); \
        if (buffer == NULL) {                           \
            printf("Error allocating memory\n");        \
            exit(1);                                    \
        }                                               \
        fread(buffer, 1, file_size, fp);                \
        fclose(fp);                                     \
    }

#define FREE_BUFFER()                                   \
    {                                                   \
        free(buffer);                                   \
    }

#endif