#ifndef _LEXER_H_
#define _LEXER_H_

#include "code_core_token.h"

typedef struct lexer {
    char* source;
    int len;
    int pos;
    int line;
    int col;
    int current_char;
} lexer;

lexer* init_code_lexer(char* source, int len);
int lex_peek(lexer* lexer);
int lex_advance(lexer* lexer);
Token* lex_next_token(lexer* lexer);

void lex_error(const char* msg, int line, int col);
void lexer_free(lexer* lexer);

void print_token(Token* token);

#endif