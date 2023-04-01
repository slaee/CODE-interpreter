#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/parser/lexer.h"

#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_YELLOW  "\x1b[33m"
#define ANSI_BLUE    "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN    "\x1b[36m"
#define ANSI_RESET   "\x1b[0m"

void read_file(char* path, char* buffer) {
    // read file
    FILE *fp = fopen("test/test1.code", "r");

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
                printf("---- Test 1: \n");
                read_file("test/test1.code", buffer);
                lex = Lexer(buffer, strlen(buffer));
                stream = tokenize(lex);

                // while (peek_ts(stream) != TOKEN_EOF) {
                //     Token* token = advance_ts(stream);
                //     print_token(token);
                // }
                
                // 29
                assert(peek_ts(stream) == TOKEN_BEGIN);
                assert(advance_ts(stream)->type == TOKEN_BEGIN);
                // 30
                assert(peek_ts(stream) == TOKEN_CODE);
                assert(advance_ts(stream)->type == TOKEN_CODE);
                // 32
                assert(peek_ts(stream) == TOKEN_INT);
                assert(advance_ts(stream)->type == TOKEN_INT);
                // 40
                assert(peek_ts(stream) == TOKEN_IDENTIFIER);
                assert(advance_ts(stream)->type == TOKEN_IDENTIFIER);
                // 9
                assert(peek_ts(stream) == TOKEN_COMMA);
                assert(advance_ts(stream)->type == TOKEN_COMMA);
                // 40
                assert(peek_ts(stream) == TOKEN_IDENTIFIER);
                assert(advance_ts(stream)->type == TOKEN_IDENTIFIER);
                // 41
                assert(peek_ts(stream) == TOKEN_ASSIGN);
                assert(advance_ts(stream)->type == TOKEN_ASSIGN);
                // 42
                assert(peek_ts(stream) == TOKEN_NUMBER);
                assert(advance_ts(stream)->type == TOKEN_NUMBER);
                // 40
                assert(peek_ts(stream) == TOKEN_IDENTIFIER);
                assert(advance_ts(stream)->type == TOKEN_IDENTIFIER);
                // 41
                assert(peek_ts(stream) == TOKEN_ASSIGN);
                assert(advance_ts(stream)->type == TOKEN_ASSIGN);
                // 10
                assert(peek_ts(stream) == TOKEN_LPAREN);
                assert(advance_ts(stream)->type == TOKEN_LPAREN);
                // 10
                assert(peek_ts(stream) == TOKEN_LPAREN);
                assert(advance_ts(stream)->type == TOKEN_LPAREN);
                // 40
                assert(peek_ts(stream) == TOKEN_IDENTIFIER);
                assert(advance_ts(stream)->type == TOKEN_IDENTIFIER);
                // 3
                assert(peek_ts(stream) == TOKEN_STAR);
                assert(advance_ts(stream)->type == TOKEN_STAR);
                // 42
                assert(peek_ts(stream) == TOKEN_NUMBER);
                assert(advance_ts(stream)->type == TOKEN_NUMBER);
                // 11
                assert(peek_ts(stream) == TOKEN_RPAREN);
                assert(advance_ts(stream)->type == TOKEN_RPAREN);
                // 4
                assert(peek_ts(stream) == TOKEN_SLASH);
                assert(advance_ts(stream)->type == TOKEN_SLASH);
                // 42
                assert(peek_ts(stream) == TOKEN_NUMBER);
                assert(advance_ts(stream)->type == TOKEN_NUMBER);
                // 1
                assert(peek_ts(stream) == TOKEN_PLUS);
                assert(advance_ts(stream)->type == TOKEN_PLUS);
                // 42
                assert(peek_ts(stream) == TOKEN_NUMBER);
                assert(advance_ts(stream)->type == TOKEN_NUMBER);
                // 11
                assert(peek_ts(stream) == TOKEN_RPAREN);
                assert(advance_ts(stream)->type == TOKEN_RPAREN);
                // 3
                assert(peek_ts(stream) == TOKEN_STAR);
                assert(advance_ts(stream)->type == TOKEN_STAR);
                // 2
                assert(peek_ts(stream) == TOKEN_MINUS);
                assert(advance_ts(stream)->type == TOKEN_MINUS);
                // 42
                assert(peek_ts(stream) == TOKEN_NUMBER);
                assert(advance_ts(stream)->type == TOKEN_NUMBER);
                // 36
                assert(peek_ts(stream) == TOKEN_DISPLAY);
                assert(advance_ts(stream)->type == TOKEN_DISPLAY);
                // 8 
                assert(peek_ts(stream) == TOKEN_COLON);
                assert(advance_ts(stream)->type == TOKEN_COLON);
                // 12
                assert(peek_ts(stream) == TOKEN_LBRACKET);
                assert(advance_ts(stream)->type == TOKEN_LBRACKET);
                // 12
                assert(peek_ts(stream) == TOKEN_LBRACKET);
                assert(advance_ts(stream)->type == TOKEN_LBRACKET);
                // 13
                assert(peek_ts(stream) == TOKEN_RBRACKET);
                assert(advance_ts(stream)->type == TOKEN_RBRACKET);
                // 7 
                assert(peek_ts(stream) == TOKEN_AMPERSAND);
                assert(advance_ts(stream)->type == TOKEN_AMPERSAND);
                // 40
                assert(peek_ts(stream) == TOKEN_IDENTIFIER);
                assert(advance_ts(stream)->type == TOKEN_IDENTIFIER);
                // 7 
                assert(peek_ts(stream) == TOKEN_AMPERSAND);
                assert(advance_ts(stream)->type == TOKEN_AMPERSAND);
                 // 12
                assert(peek_ts(stream) == TOKEN_LBRACKET);
                assert(advance_ts(stream)->type == TOKEN_LBRACKET);
                // 13
                assert(peek_ts(stream) == TOKEN_RBRACKET);
                assert(advance_ts(stream)->type == TOKEN_RBRACKET);
                // 13
                assert(peek_ts(stream) == TOKEN_RBRACKET);
                assert(advance_ts(stream)->type == TOKEN_RBRACKET);
                // 31
                assert(peek_ts(stream) == TOKEN_END);
                assert(advance_ts(stream)->type == TOKEN_END);
                // 30
                assert(peek_ts(stream) == TOKEN_CODE);
                assert(advance_ts(stream)->type == TOKEN_CODE);

                printf("-- LEXER TEST ... [" ANSI_GREEN "PASSED" ANSI_RESET "]\n");

                printf("-- PARSER TEST ... [" ANSI_YELLOW "NO TEST CASES" ANSI_RESET "]\n");

                printf("-- AST TEST ... [" ANSI_YELLOW "NO TEST CASES" ANSI_RESET "]\n");

                printf("-- EVALUATION TEST ... [" ANSI_YELLOW "NO TEST CASES" ANSI_RESET "]\n");
                free(buffer);
                break;
            
            case 1: 
                printf("---- Test 2: \n");
                read_file("test/test2.code", buffer);
                lex = Lexer(buffer, strlen(buffer));
                stream = tokenize(lex);

                while (peek_ts(stream) != TOKEN_EOF) {
                    Token* token = advance_ts(stream);
                    print_token(token);
                }

                break;
        }
    }   
}