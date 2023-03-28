#ifndef _CODECORE_H_
#define _CODECORE_H_

#undef EOF

#include <stdlib.h>
#include <regex.h>

#define INVALID -1

// Enumeration of all the possible token types
enum TokenType {
    // Special tokens
    EOF,
    NEWLINE,

    // Operators
    PLUS,
    MINUS,
    ASTERISK,
    SLASH,
    PERCENT,
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    LESS,
    GREATER,
    EQUAL,
    DOLLAR,
    AMPERSAND,
    COMMA,
    COLON,

    EQUAL_EQUAL,
    NOT_EQUAL,
    GREATER_EQUAL,
    LESS_EQUAL,

    AND,
    OR,
    NOT,

    // Keywords
    BEGIN,
    END,
    INT,
    CHAR,
    BOOL,
    FLOAT,
    TRUE,
    FALSE,
    DISPLAY,

    // Literals
    IDENTIFIER,
    INTEGER,
    CHARACTER,
    STRING,
    FLOATING_POINT,
};

// Special definitions for the token types

#define ISTERMINAL(x)       (x >= BEGIN && x <= DISPLAY)
#define ISNONTERMINAL(x)    (x >= IDENTIFIER && x <= FLOATING_POINT)
#define ISEOF(x)            (x == EOF)
#define ISWHITESPACE(x)     (x == NEWLINE)

//

int CodeOneChar(int);
int CodeTwoChars(int, int);

#endif