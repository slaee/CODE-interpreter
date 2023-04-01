#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

#define BLANK ' '
#define TAB '\t'
#define NEWLINE '\n'
#define COMMENT '#'
#define ZERO 0
#define UNKNOWN -2

const char* STR_TOKEN_VALUES[] = {
    [TOKEN_BEGIN]       = "BEGIN",
    [TOKEN_CODE]        = "CODE",
    [TOKEN_END]         = "END",
    [TOKEN_INT]         = "INT",
    [TOKEN_CHAR]        = "CHAR",
    [TOKEN_BOOL]        = "BOOL",
    [TOKEN_SCAN]        = "SCAN",
    [TOKEN_DISPLAY]     = "DISPLAY",
    [TOKEN_IF]          = "IF",
    [TOKEN_ELSE]        = "ELSE",
    [TOKEN_WHILE]       = "WHILE",
    [TOKEN_OR]          = "OR",
    [TOKEN_AND]         = "AND",
    [TOKEN_NOT]         = "NOT",
    [TOKEN_EOF]         = "EOF",
    [TOKEN_NUMBER]      = "NUMBER",
    [TOKEN_FLOATNUMBER] = "FLOATNUMBER",
    [TOKEN_STRING]      = "STRING",
    [TOKEN_CHAR]        = "CHAR",
    [TOKEN_IDENTIFIER]  = "IDENTIFIER",
};

const char CH_TOKEN_VALUES[] = {
    [TOKEN_PLUS]        = '+',
    [TOKEN_MINUS]       = '-',
    [TOKEN_STAR]        = '*',
    [TOKEN_SLASH]       = '/',
    [TOKEN_PERCENT]     = '%',
    [TOKEN_DOLLAR]      = '$',
    [TOKEN_AMPERSAND]   = '&',
    [TOKEN_COLON]       = ':',
    [TOKEN_COMMA]       = ',',
    [TOKEN_LPAREN]      = '(',
    [TOKEN_RPAREN]      = ')',
    [TOKEN_LBRACKET]    = '[',
    [TOKEN_RBRACKET]    = ']',
    [TOKEN_ASSIGN]      = '=',
};

// this method will print an error message during the lexing process and exits the program
void error(const char* msg, int line, int col) {
    printf("Error: %s at line %d, col %d", msg, line, col);
    exit(1);
}

// this method will create a new lexer
lexer* Lexer(char* source, int len) {
    lexer* lex = (lexer*) malloc(sizeof(lexer));
    lex->source = source;
    lex->len = len;
    lex->pos = 0;
    lex->line = 1;
    lex->col = 1;
    lex->next_char = 0;
    return lex;
}

// this method will free the memory allocated for the lexer
void lexer_free(lexer* lexer) {
    free(lexer);
}

// this method will peek the next character from the lexer
// returns the next character
int peek(lexer* lexer) {
    return lexer->next_char;
}

// this method will advance the lexer to the next character as the peek will depend
// on this method to what character to be peeked next
// returns the next character
int advance(lexer* lexer) {
    char c = lexer->next_char;
    if(c == EOF) {
        c = EOF;
        lexer->next_char = 0;
    } else {
        lexer->next_char = lexer->source[lexer->pos];
    }
    lexer->pos++;
    lexer->col++;
    return c;
}

// this the same as peek but for the token stream
int peek_ts(TokenStream* ts) {
    return ts->next[ts->current].type;
}

// this the same as advance but for the token stream
Token* advance_ts(TokenStream* ts) {
    return &ts->next[ts->current++];
}

int is_identifier_char(char c) {
    return isalnum(c) || c == '_';
}

void skip_whitespace(lexer* lexer) {
    while(peek(lexer) == BLANK || peek(lexer) == ZERO || peek(lexer) == TAB || peek(lexer) == NEWLINE) {
        advance(lexer);
    }
}

int CodeOne_Char(char c1) {
    switch(c1) {
        case '+': return TOKEN_PLUS;
        case '-': return TOKEN_MINUS;
        case '/': return TOKEN_SLASH;
        case '*': return TOKEN_STAR;
        case '%': return TOKEN_PERCENT;
        case '&': return TOKEN_AMPERSAND;
        case '$': return TOKEN_DOLLAR;
        case ':': return TOKEN_COLON;
        case ',': return TOKEN_COMMA;
        case '=': return TOKEN_ASSIGN;
        case '(': return TOKEN_LPAREN;
        case ')': return TOKEN_RPAREN;
        case '[': return TOKEN_LBRACKET;
        case ']': return TOKEN_RBRACKET;
    }
}

int CodeTwo_Chars(char c1, char c2) {
    switch(c1) {
        case '=':
            if(c2 == '=') return TOKEN_EQEQUAL;
            break;
        case '>':
            if(c2 == '=') return TOKEN_GREATEREQUAL;
            break;
        case '<':
            if(c2 == '=') return TOKEN_LESSEQUAL;
            if(c2 == '>') return TOKEN_NOTEQUAL; 
            break;
        case '+':
            if(c2 == '=') return TOKEN_PLUSEQUAL;
            if(c2 == '+') return TOKEN_PLUSPLUS;
            break;
        case '-':
            if(c2 == '=') return TOKEN_MINUSEQUAL;
            if(c2 == '-') return TOKEN_MINUSMINUS;
            break;
        case '*':
            if(c2 == '=') return TOKEN_STAREQUAL;
            break;
        case '/':
            if(c2 == '=') return TOKEN_SLASHEQUAL;
            break;
    }
}


Token* scan_digits (lexer* lexer) {
    Token* token = (Token*) malloc(sizeof(Token));
    
    // TODO: implement scanning of digits here
    // NOTE: if the next character is a dot, then it is a float number

    return token;
}

// scans symbols to tokenize it
// should return a token
Token* scan_symbols(lexer* lexer) {
    Token* token = (Token*) malloc(sizeof(Token));
    
    // TODO: implement scanning of symbols here

    return token;
}

// scans identifiers to tokenize it
// should return a token
Token* scan_identifier(lexer* lexer) {
    Token* token = (Token*) malloc(sizeof(Token));
    
    // TODO: implement scanning of identifiers here and check if it is a keyword
    // NOTE: you can use is_identifier_char() to check if a character is valid for an identifier

    return token;
}

// this method will create a token with the given type and lexeme
// returns a pointer token
Token* create_token(int type, char* lexeme) {
    Token* token = (Token*) malloc(sizeof(Token));
    token->type = type;
    token->lexeme = malloc(sizeof(char) * (strlen(lexeme) + 1));
    strcpy(token->lexeme, lexeme);

    return token;
}

// scans lexemes to tokenize it
// should return a token
Token* scan(lexer* lexer) {
    Token* token = (Token*) malloc(sizeof(Token));

    // TODO: implement scanning of tokens here
    // NOTE: you can use the functions peek(), advance(), skip_whitespace() and create_token() to help you
    // eliminate whitespace and comments

    return token;
}

TokenStream* tokenize(lexer* lexer) {
    TokenStream* ts = (TokenStream*) malloc(sizeof(TokenStream));
    ts->length = 0;
    ts->current = 0;
    ts->next = (Token*) malloc(sizeof(Token)*2);

    Token* token;
    while(1) {
        // retrieve the next token
        token = scan(lexer);

        // add the token to the token stream
        ts->next = realloc(ts->next, sizeof(Token) * (ts->length + 2));
        ts->next[ts->length] = *token;
        ts->length++;

        // check if the token is EOF (end of file) and break if it is
        if(token->type == TOKEN_EOF) {
            break;
        }
    }

    return ts;
}


void print_token(Token* token) {
    printf("TOKEN: \n");
    printf("type: %d\n" , token->type);
    printf("lexeme: %s\n" , token->lexeme);
    printf("\n");
}

