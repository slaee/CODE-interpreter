#ifndef _CODE_CORE_TOKEN_H_
#define _CODE_CORE_TOKEN_H_

enum TokenType {
    TOKEN_EOF,          // 0
    TOKEN_NEWLINE,

    // operators
    TOKEN_PLUS,         // 1
    TOKEN_MINUS,        // 2
    TOKEN_STAR,         // 3
    TOKEN_SLASH,        // 4
    TOKEN_PERCENT,      // 5
    TOKEN_DOLLAR,       // 6
    TOKEN_AMPERSAND,    // 7
    TOKEN_COLON,        // 8
    TOKEN_COMMA,        // 9
    TOKEN_LPAREN,       // 10
    TOKEN_RPAREN,       // 11
    TOKEN_LBRACKET,     // 12
    TOKEN_RBRACKET,     // 13
    TOKEN_GREATERTHAN,  // 14
    TOKEN_LESSTHAN,     // 15
    TOKEN_EQUAL,
    TOKEN_EQEQUAL,      // 16
    TOKEN_LESSEQUAL,    // 17
    TOKEN_GREATEREQUAL, // 18
    TOKEN_NOTEQUAL,     // 19
    TOKEN_PLUSPLUS,     // 20
    TOKEN_MINUSMINUS,   // 21
    TOKEN_PLUSEQUAL,    // 22
    TOKEN_MINUSEQUAL,   // 23
    TOKEN_STAREQUAL,    // 24
    TOKEN_SLASHEQUAL,   // 25

    // logical operators
    TOKEN_OR,           // 26
    TOKEN_AND,          // 27
    TOKEN_NOT,          // 28
    
    // Reserved words
    TOKEN_BEGIN,        // 29
    TOKEN_CODE,         // 30
    TOKEN_END,          // 31
    TOKEN_SCAN,         // 35
    TOKEN_DISPLAY,      // 36
    TOKEN_IF,           // 37
    TOKEN_ELSE,         // 38
    TOKEN_WHILE,        // 39
    TOKEN_DO,
    TOKEN_FOR,
    TOKEN_SWITCH,
    TOKEN_CASE,
    TOKEN_CONTINUE,
    TOKEN_FUNC,
    TOKEN_RETURN,

    TOKEN_TYPE,
    TOKEN_IDENTIFIER,   // 40
    TOKEN_NUMBER,       // 42
    TOKEN_FNUMBER,
    TOKEN_STRING,       // 44
    TOKEN_BOOLEAN,      // 45
    TOKEN_CHARACTER,    // 46
    TOKEN_COMMENT,      // 47
};

typedef struct token {
    enum TokenType type;
    char* value;
} Token;
#endif