#ifndef _CODECORE_TOKEN_H_
#define _CODECORE_TOKEN_H_

// Enumeration of all the possible token types
enum TokenType {
    // Special tokens
    TOKEN_INVALID,
    TOKEN_EOF,
    TOKEN_NEWLINE,

    // Operators
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_ASTERISK,
    TOKEN_SLASH,
    TOKEN_PERCENT,
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_LEFT_BRACKET,
    TOKEN_RIGHT_BRACKET,
    TOKEN_LESS,
    TOKEN_GREATER,
    TOKEN_EQUAL,
    TOKEN_DOLLAR,
    TOKEN_AMPERSAND,
    TOKEN_COMMA,
    TOKEN_COLON,

    TOKEN_EQUAL_EQUAL,
    TOKEN_NOT_EQUAL,
    TOKEN_GREATER_EQUAL,
    TOKEN_LESS_EQUAL,

    TOKEN_AND,
    TOKEN_OR,
    TOKEN_NOT,

    // Keywords
    TOKEN_BEGIN,
    TOKEN_END,
    TOKEN_INT,
    TOKEN_CHAR,
    TOKEN_BOOL,
    TOKEN_FLOAT,
    TOKEN_TRUE,
    TOKEN_FALSE,
    TOKEN_DISPLAY,

    // Literals
    TOKEN_IDENTIFIER,
    TOKEN_INTEGER,
    TOKEN_CHARACTER,
    TOKEN_STRING,
    TOKEN_FLOATING_POINT,
};

// Special definitions for the token types

#define ISTERMINAL(x)       (x >= TOKEN_BEGIN && x <= TOKEN_DISPLAY)
#define ISNONTERMINAL(x)    (x >= TOKEN_IDENTIFIER && x <= TOKEN_FLOATING_POINT)
#define ISEOF(x)            (x == TOKEN_EOF)
#define ISWHITESPACE(x)     (x == TOKEN_NEWLINE)

//

int CodeToken_OneChar(int);
int CodeToken_TwoChars(int, int);

#endif