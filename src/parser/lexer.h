#ifndef _LEXER_H_
#define _LEXER_H_

#include "code_core_token.h"

typedef struct lexer {
    char* source;
    int len;
    int pos;
    int line;
    int col;
    int next_char;
} lexer;

lexer* Lexer(char* source, int len);
void lexer_free(lexer* lexer);

int peek(lexer* lexer);
int advance(lexer* lexer);
TokenStream* tokenize(lexer* lexer);
Token* scan(lexer* lexer);

void error(const char* msg, int line, int col);

#endif