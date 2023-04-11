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
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_SLASH);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_MINUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_1)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 1:
                printf("========= Test 2:");
                READ_FILE("test/test2.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_2)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_2)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 2:
                printf("========= Test 3:");
                READ_FILE("test/test3.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_1)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_3)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 3:
                printf("========= Test 4:");
                READ_FILE("test/test4.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_1)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FNUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_4)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 4:
                printf("========= Test 5:");
                READ_FILE("test/test5.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_1)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FNUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_5)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 5:
                printf("========= Test 6:");
                READ_FILE("test/test6.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_6)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_6)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 6:
                printf("========= Test 7:");
                READ_FILE("test/test7.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_7)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_7)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 7:
                printf("========= Test 8:");
                READ_FILE("test/test8.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_8)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_GREATERTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_8)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 8:
                printf("========= Test 9:");
                READ_FILE("test/test9.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_9)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_GREATERTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_9)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 9:
                printf("========= Test 10:");
                READ_FILE("test/test10.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_10)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_GREATERTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_10)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 10:
                printf("========= Test 11:");
                READ_FILE("test/test11.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_11)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_GREATERTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_11)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 11:
                printf("========= Test 12:");
                READ_FILE("test/test12.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_12)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_12)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 12:
                printf("========= Test 13:");
                READ_FILE("test/test13.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_13)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_13)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 13:
                printf("========= Test 14:");
                READ_FILE("test/test14.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_14)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_14)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 14:
                printf("========= Test 15:");
                READ_FILE("test/test15.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_15)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_15)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 15:
                printf("========= Test 16:");
                READ_FILE("test/test16.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_16)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_16)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 16:
                printf("========= Test 17:");
                READ_FILE("test/test17.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_17)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_17)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 17:
                printf("========= Test 18:");
                READ_FILE("test/test18.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_18)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_GREATERTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_18)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 10:
                printf("========= Test 11:");
                READ_FILE("test/test11.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_11)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_19)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 19:
                printf("========= Test 20:");
                READ_FILE("test/test20.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_20)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_20)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 20:
                printf("========= Test 21:");
                READ_FILE("test/test21.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_21)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_21)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 21:
                printf("========= Test 22:");
                READ_FILE("test/test22.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_22)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_22)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 22:
                printf("========= Test 23:");
                READ_FILE("test/test23.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_23)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_23)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 23:
                printf("========= Test 24:");
                READ_FILE("test/test24.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_24)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_ELSE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_24)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 24:
                printf("========= Test 25:");
                READ_FILE("test/test25.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_25)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_ELSE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_ELSE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_25)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 25:
                printf("========= Test 26:");
                READ_FILE("test/test26.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_26)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_ELSE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_ELSE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_26)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 26:
                printf("========= Test 27:");
                READ_FILE("test/test27.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_27)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_ELSE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_ELSE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_27)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 27:
                printf("========= Test 28:");
                READ_FILE("test/test28.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_28)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_DOLLAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_ELSE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_ELSE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_28)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 28:
                printf("========= Test 29:");
                READ_FILE("test/test29.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_29)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PERCENT);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_29)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 29:
                printf("========= Test 30:");
                READ_FILE("test/test30.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_30)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PERCENT);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_30)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 30:
                printf("========= Test 31:");
                READ_FILE("test/test31.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_31)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PERCENT);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_31)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 31:
                printf("========= Test 32:");
                READ_FILE("test/test32.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_32)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PERCENT);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_GREATERTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_32)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 32:
                printf("========= Test 33:");
                READ_FILE("test/test33.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_33)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_33)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 33:
                printf("========= Test 34:");
                READ_FILE("test/test34.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_34)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_DOLLAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_34)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 35:
                printf("========= Test 36:");
                READ_FILE("test/test36.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_36)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PERCENT);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_DOLLAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_36)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 34:
                printf("========= Test 35:");
                READ_FILE("test/test35.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_35)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_DOLLAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_DOLLAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_35)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 36:
                printf("========= Test 37:");
                READ_FILE("test/test37.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_36)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_DOLLAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PERCENT);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_DOLLAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_37)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 37:
                printf("========= Test 38:");
                READ_FILE("test/test38.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_38)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PERCENT);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_DOLLAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_38)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 38:
                printf("========= Test 39:");
                READ_FILE("test/test39.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_39)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PERCENT);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_DOLLAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IF);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_39)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 40:
                printf("========= Test 41:");
                READ_FILE("test/test41.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_41)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSTHAN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN)
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_WHILE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_DOLLAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_40)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 39:
                printf("========= Test 40:");
                READ_FILE("test/test40.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_40)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STRING);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LESSEQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_DOLLAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_FOR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_41)

                // sample for PARSER test
                /**
                BEGIN_TEST(PARSER)
                    ... do assertions here calling assert_ne() ...
                END_TEST(PARSER)
                */
                FREE_BUFFER()
            break;

            case 41:
                printf("========= Test 42:");
                READ_FILE("test/test42.code");
                lex = init_code_lexer(buffer, strlen(buffer));
                BEGIN_TEST(LEXER_TEST_42)
                    assert_ne(lex_next_token(lex)->type == TOKEN_BEGIN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_TYPE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COMMA);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_EQUAL);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_SLASH);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_PLUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RPAREN);
                    assert_ne(lex_next_token(lex)->type == TOKEN_STAR);
                    assert_ne(lex_next_token(lex)->type == TOKEN_MINUS);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NUMBER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_COLON);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_IDENTIFIER);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_LBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_AMPERSAND);
                    assert_ne(lex_next_token(lex)->type == TOKEN_RBRACKET);
                    assert_ne(lex_next_token(lex)->type == TOKEN_NEWLINE);
                    assert_ne(lex_next_token(lex)->type == TOKEN_END);
                    assert_ne(lex_next_token(lex)->type == TOKEN_CODE);
                END_TEST(LEXER_TEST_42)

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