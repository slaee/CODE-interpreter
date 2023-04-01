#ifndef _CODECORE_TOKENIZER_H_
#define _CODECORE_TOKENIZER_H_

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

void error(char* message);
int is_identifier_char(char c);
void advance(Interpreter* interp);
void skip_whitespace(Interpreter* interp);
void read_identifier(Interpreter* interp);
void next_token(Interpreter* interp);
void read_number(Interpreter* interp);

#endif