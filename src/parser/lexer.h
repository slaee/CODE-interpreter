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
} Lexer;

Lexer* init_code_lexer(char* source, int len);
int lex_peek(Lexer* lexer);
int lex_advance(Lexer* lexer);
Token* lex_next_token(Lexer* lexer);

void lex_error(const char* msg, int line, int col);
void lexer_free(Lexer* lexer);

void print_token(Token* token);

#endif