#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <assert.h>
#include "assertne.h"
#include "color.h"
#include "io.h"
#include "../src/parser/lexer.h"

int main() {
    // test 1
    int number_of_tests = 1;
    extern char* buffer;
    Lexer* lex;

    int test;
    for(test = 0; test < number_of_tests; ++test) {
        switch(test) {
            case 0:
                printf("========= Test 1:");
                READ_FILE("test/test1.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_1)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                END_TEST(LEXER_TEST_1)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;
        }
    }   
}