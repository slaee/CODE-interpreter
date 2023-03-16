#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/internal/codecore_token.h"

// Struct representing a token in the program
typedef struct {
    enum TokenType type; // Type of the token
    char* lexeme;        // String representation of the token
    int line;            // Line number where the token appears
} Token;


// Struct representing a variable in the program
typedef struct {
    char* name;          // Name of the variable
    enum TokenType type; // Type of the variable
    void* value;         // Value of the variable
} Variable;


// Struct representing the interpreter state
typedef struct {
    Variable* variables; // Array of variables
    int num_vars;        // Number of variables in the array
    char* input;         // Input program string
    int input_size;      // Size of the input program string
    int pos;             // Current position in the input string
    int line;            // Current line number
    Token current_token; // Current token being parsed
} Interpreter;


int CodeToken_OneChar(int c) {
    switch (c) {
        case '+': return TOKEN_PLUS;
        case '-': return TOKEN_MINUS;
        case '*': return TOKEN_ASTERISK;
        case '/': return TOKEN_SLASH;
        case '%': return TOKEN_PERCENT;
        case '(': return TOKEN_LEFT_PAREN;
        case ')': return TOKEN_RIGHT_PAREN;
        case '[': return TOKEN_LEFT_BRACKET;
        case ']': return TOKEN_RIGHT_BRACKET;
        case '<': return TOKEN_LESS;
        case '>': return TOKEN_GREATER;
        case '=': return TOKEN_EQUAL;
        case '$': return TOKEN_DOLLAR;
        case '&': return TOKEN_AMPERSAND;
        case ',': return TOKEN_COMMA;
        case ':': return TOKEN_COLON;
    }
}

int CodeToken_TwoChars(int c1, int c2) {
    switch (c1) {
        case '>':
            if (c2 == '=') return TOKEN_GREATER_EQUAL;
            break;
        case '<':
            if (c2 == '=') return TOKEN_LESS_EQUAL;
            if (c2 == '>') return TOKEN_NOT_EQUAL;
            break; 
        case '=':
            if (c2 == '=') return TOKEN_EQUAL_EQUAL;
            break;
    }
}