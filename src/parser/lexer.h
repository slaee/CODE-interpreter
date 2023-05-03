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

typedef struct token_stream {
    Token** tokens;
    int size;
    int pos;
} TokenStream;

Lexer* init_code_lexer(char* source, int len);
int lex_peek(Lexer* lexer);
int lex_advance(Lexer* lexer);
Token* lex_next_token(Lexer* lexer);
TokenStream* lex_tokenize(Lexer* lexer);

Token* ts_peek(TokenStream* ts);
Token* ts_advance(TokenStream* ts);
int ts_lookahead(TokenStream* ts, int n);

void lex_error(const char* msg, int line, int col);
void lexer_free(Lexer* lexer);

void print_token(Token* token);

#endif