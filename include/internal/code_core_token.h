#ifndef _CODE_CORE_TOKEN_H_
#define _CODE_CORE_TOKEN_H_

enum TokenType {
    TOKEN_EOF,          // 0

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
    TOKEN_INT,          // 32
    TOKEN_CHAR,         // 33
    TOKEN_BOOL,         // 34
    TOKEN_SCAN,         // 35
    TOKEN_DISPLAY,      // 36
    TOKEN_IF,           // 37
    TOKEN_ELSE,         // 38
    TOKEN_WHILE,        // 39

    // literals
    TOKEN_IDENTIFIER,   // 40
    TOKEN_ASSIGN,       // 41
    TOKEN_NUMBER,       // 42
    TOKEN_FLOATNUMBER,  // 43
    TOKEN_STRING,       // 44
    TOKEN_BOOLEAN,      // 45
    TOKEN_CHARACTER,    // 46
    TOKEN_COMMENT,      // 47
};

typedef struct token {
    enum TokenType type;
    char* lexeme;
} Token;

typedef struct token_stream {
    Token* next;
    int length;
    int current;
} TokenStream;

int peek_ts(TokenStream* ts);
Token* advance_ts(TokenStream* ts);
int CodeOne_Char(char c1);
int CodeTwo_Chars(char c1, char c2);
void print_token(Token* token);

#endif