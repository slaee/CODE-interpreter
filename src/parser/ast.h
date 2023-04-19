#ifndef _AST_H_
#define _AST_H_

#include "types.h"

enum AST_Type {
    AST_DEFINITIONS,
    AST_VARIABLE_DECLS,
    AST_FUNCTION_DECLS,
    AST_VARIABLE,
    AST_ASSIGNMENT,
    AST_CONCAT_EXPRESSION,
    AST_ARITHMETIC_EXPRESSION,
    AST_BOOLEAN_EXPRESSION,
    AST_UNARY_EXPRESSION,
    AST_PAREN_EXPRESSION,
    AST_NUMBER,
    AST_INT,
    AST_FLOAT,
    AST_CHAR,
    AST_STRING,
    AST_BOOLEAN,
    AST_CHARACTER,
    AST_IF_ELSE_STATEMENT,
    AST_WHILE_STATEMENT,
    AST_FUNCTION_CALL,
    AST_ARGS,
    AST_COMPOUND,
    AST_NOOP,
};

typedef struct ast{
    enum AST_Type type;

     // variable declarations
    DataType data_type;
    char* name;
    
    // operators
    int operator;

    // literals
    int int_value;
    float float_value;
    char* string_value;
    char* boolean_value;
    char character_value;

    struct ast* value;
    struct ast* left;
    struct ast* right;

    struct ast** children;
    size_t children_size;
} AST;

AST* init_code_ast(enum AST_Type type);

AST** init_children(size_t size);

void ast_add_child(AST* parent, AST* child);

void ast_add_sibling(AST* parent, AST* child);

#endif