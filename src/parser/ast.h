#ifndef _AST_H_
#define _AST_H_

#include <stdlib.h>

enum AST_Type {
    AST_VARIABLE_DECLARATIONS,
    AST_ASSIGNMENT,
    AST_ARITHMETIC_EXPRESSION,
    AST_STRING_VAL_EXPRESSION,
    AST_BOOLEAN_EXPRESSION,
    AST_IF_STATEMENT,
    AST_WHILE_STATEMENT,
    AST_VARIABLE,
    AST_FUNCTION_CALL,
    AST_COMPOUND,
    AST_NOOP,
};

typedef struct ast{
    enum AST_Type type;

    // ast variable definition
    char* variable_declaration_type;
    struct ast** variable_declaration_names;

    // ast variable
    char* variable_name;

    // ast function call
    char* func_call_name;
    struct ast** func_call_args;
    size_t func_call_args_size;

    // ast string
    char* string_value;

    char* boolean_value;

    struct ast** compound_statements;
    size_t compound_size;
} AST;

AST* init_code_ast(enum AST_Type type);

#endif