#ifndef _ASSERTNE_H_
#define _ASSERTNE_H_

#include <stdio.h>
#include <stdlib.h>
#include "color.h"

int pass_count = 0;
int fail_count = 0;

#define assert_ne(condition) \
    do { \
        if (condition) { \
            printf("test_(" ANSI_CYAN "%s" ANSI_RESET ") ... [" ANSI_GREEN "PASSED" ANSI_RESET "]\n", #condition); \
            pass_count++; \
        } else { \
            printf("test_(" ANSI_RED "%s" ANSI_RESET ") ... [" ANSI_RED "FAILED" ANSI_RESET "]\n", #condition); \
            fail_count++; \
        } \
    } while(0) 


#define BEGIN_TEST(title) \
    void test_##title() { \
        printf("\n----- %s TEST BEGIN \n\n", #title); \
        int pass_count = 0; \
        int fail_count = 0; 

#define END_TEST(title) \
        printf("\n----- %s TEST RESULT: %d passed, %d failed\n\n", #title, pass_count, fail_count); \
    } \
    test_##title();

#endif