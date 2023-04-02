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
#include "../src/parser/lexer.h"

void read_file(char* path, char* buffer) {
    // read file
    FILE *fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // // Get the size of the file
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    // Allocate a buffer for the file contents
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    // Read the file contents into the buffer
    fread(buffer, file_size, 1, fp);
    buffer[file_size] = EOF; 
}

int main() {
    // test 1
    int number_of_tests = 2;
    char* buffer = malloc(1024);
    lexer* lex;
    TokenStream* stream;

    int test;
    for(test = 0; test < number_of_tests; ++test) {
        switch(test) {
            case 0:
                    printf("========= Test 1:");
                    read_file("test/test1.code", buffer);
                    lex = Lexer(buffer, strlen(buffer));
                    stream = tokenize(lex);

                    // while (peek_ts(stream) != TOKEN_EOF) {
                    //     Token* token = advance_ts(stream);
                    //     print_token(token);
                    // }
                    BEGIN_TEST(LEXER)
                        // 29
                        assert_ne(peek_ts(stream) == TOKEN_BEGIN);
                        assert_ne(advance_ts(stream)->type == TOKEN_BEGIN);
                        // 30
                        assert_ne(peek_ts(stream) == TOKEN_CODE);
                        assert_ne(advance_ts(stream)->type == TOKEN_CODE);
                        // 32
                        assert_ne(peek_ts(stream) == TOKEN_INT);
                        assert_ne(advance_ts(stream)->type == TOKEN_INT);
                        // 40
                        assert_ne(peek_ts(stream) == TOKEN_IDENTIFIER);
                        assert_ne(advance_ts(stream)->type == TOKEN_IDENTIFIER);
                        // 9
                        assert_ne(peek_ts(stream) == TOKEN_COMMA);
                        assert_ne(advance_ts(stream)->type == TOKEN_COMMA);
                        // 40
                        assert_ne(peek_ts(stream) == TOKEN_IDENTIFIER);
                        assert_ne(advance_ts(stream)->type == TOKEN_IDENTIFIER);
                        // 41
                        assert_ne(peek_ts(stream) == TOKEN_ASSIGN);
                        assert_ne(advance_ts(stream)->type == TOKEN_ASSIGN);
                        // 42
                        assert_ne(peek_ts(stream) == TOKEN_NUMBER);
                        assert_ne(advance_ts(stream)->type == TOKEN_NUMBER);
                        // 40
                        assert_ne(peek_ts(stream) == TOKEN_IDENTIFIER);
                        assert_ne(advance_ts(stream)->type == TOKEN_IDENTIFIER);
                        // 41
                        assert_ne(peek_ts(stream) == TOKEN_ASSIGN);
                        assert_ne(advance_ts(stream)->type == TOKEN_ASSIGN);
                        // 10
                        assert_ne(peek_ts(stream) == TOKEN_LPAREN);
                        assert_ne(advance_ts(stream)->type == TOKEN_LPAREN);
                        // 10
                        assert_ne(peek_ts(stream) == TOKEN_LPAREN);
                        assert_ne(advance_ts(stream)->type == TOKEN_LPAREN);
                        // 40
                        assert_ne(peek_ts(stream) == TOKEN_IDENTIFIER);
                        assert_ne(advance_ts(stream)->type == TOKEN_IDENTIFIER);
                        // 3
                        assert_ne(peek_ts(stream) == TOKEN_STAR);
                        assert_ne(advance_ts(stream)->type == TOKEN_STAR);
                        // 42
                        assert_ne(peek_ts(stream) == TOKEN_NUMBER);
                        assert_ne(advance_ts(stream)->type == TOKEN_NUMBER);
                        // 11
                        assert_ne(peek_ts(stream) == TOKEN_RPAREN);
                        assert_ne(advance_ts(stream)->type == TOKEN_RPAREN);
                        // 4
                        assert_ne(peek_ts(stream) == TOKEN_SLASH);
                        assert_ne(advance_ts(stream)->type == TOKEN_SLASH);
                        // 42
                        assert_ne(peek_ts(stream) == TOKEN_NUMBER);
                        assert_ne(advance_ts(stream)->type == TOKEN_NUMBER);
                        // 1
                        assert_ne(peek_ts(stream) == TOKEN_PLUS);
                        assert_ne(advance_ts(stream)->type == TOKEN_PLUS);
                        // 42
                        assert_ne(peek_ts(stream) == TOKEN_NUMBER);
                        assert_ne(advance_ts(stream)->type == TOKEN_NUMBER);
                        // 11
                        assert_ne(peek_ts(stream) == TOKEN_RPAREN);
                        assert_ne(advance_ts(stream)->type == TOKEN_RPAREN);
                        // 3
                        assert_ne(peek_ts(stream) == TOKEN_STAR);
                        assert_ne(advance_ts(stream)->type == TOKEN_STAR);
                        // 2
                        assert_ne(peek_ts(stream) == TOKEN_MINUS);
                        assert_ne(advance_ts(stream)->type == TOKEN_MINUS);
                        // 42
                        assert_ne(peek_ts(stream) == TOKEN_NUMBER);
                        assert_ne(advance_ts(stream)->type == TOKEN_NUMBER);
                        // 36
                        assert_ne(peek_ts(stream) == TOKEN_DISPLAY);
                        assert_ne(advance_ts(stream)->type == TOKEN_DISPLAY);
                        // 8 
                        assert_ne(peek_ts(stream) == TOKEN_COLON);
                        assert_ne(advance_ts(stream)->type == TOKEN_COLON);
                        // 12
                        assert_ne(peek_ts(stream) == TOKEN_LBRACKET);
                        assert_ne(advance_ts(stream)->type == TOKEN_LBRACKET);
                        // 12
                        assert_ne(peek_ts(stream) == TOKEN_LBRACKET);
                        assert_ne(advance_ts(stream)->type == TOKEN_LBRACKET);
                        // 13
                        assert_ne(peek_ts(stream) == TOKEN_RBRACKET);
                        assert_ne(advance_ts(stream)->type == TOKEN_RBRACKET);
                        // 7 
                        assert_ne(peek_ts(stream) == TOKEN_AMPERSAND);
                        assert_ne(advance_ts(stream)->type == TOKEN_AMPERSAND);
                        // 40
                        assert_ne(peek_ts(stream) == TOKEN_IDENTIFIER);
                        assert_ne(advance_ts(stream)->type == TOKEN_IDENTIFIER);
                        // 7 
                        assert_ne(peek_ts(stream) == TOKEN_AMPERSAND);
                        assert_ne(advance_ts(stream)->type == TOKEN_AMPERSAND);
                        // 12
                        assert_ne(peek_ts(stream) == TOKEN_LBRACKET);
                        assert_ne(advance_ts(stream)->type == TOKEN_LBRACKET);
                        // 13
                        assert_ne(peek_ts(stream) == TOKEN_RBRACKET);
                        assert_ne(advance_ts(stream)->type == TOKEN_RBRACKET);
                        // 13
                        assert_ne(peek_ts(stream) == TOKEN_RBRACKET);
                        assert_ne(advance_ts(stream)->type == TOKEN_RBRACKET);
                        // 31
                        assert_ne(peek_ts(stream) == TOKEN_END);
                        assert_ne(advance_ts(stream)->type == TOKEN_END);
                        // 30
                        assert_ne(peek_ts(stream) == TOKEN_CODE);
                        assert_ne(advance_ts(stream)->type == TOKEN_CODE);
                    END_TEST(LEXER)

                    // sample for PARSER test
                    /**
                    BEGIN_TEST(PARSER)
                        ... do assertions here calling assert_ne() ...
                    END_TEST(PARSER)
                    */
                break;

            case 1: 
                printf("========= Test 2:");
                read_file("test/test2.code", buffer);
                lex = Lexer(buffer, strlen(buffer));
                stream = tokenize(lex);

                // while (peek_ts(stream) != TOKEN_EOF) {
                //     Token* token = advance_ts(stream);
                //     print_token(token);
                // }

                // sample for LEXER test
                /**
                    BEGIN_TEST(LEXER)
                        ... do assertions here calling assert_ne() ...
                    END_TEST(LEXER)
                */

                // format BEGIN_TEST(your_test_name) and END_TEST(your_test_name)
                break;
        }
    }   
}