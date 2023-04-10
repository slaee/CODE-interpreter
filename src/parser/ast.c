#include "ast.h"

AST* init_code_ast(enum AST_Type type) {
    AST* ast = (AST*) malloc(sizeof(AST)); 
    ast->type = type;

    ast->variable_def_name = (void*)0;
    ast->variable_def_value = (void*)0;

    ast->variable_name = (void*)0;

    ast->func_call_name = (void*)0;
    ast->func_call_args = (void*)0;
    ast->func_call_args_size = 0;

    ast->string_value = (void*)0;

    ast->compound_value = (void*) 0;
    ast->compound_size = 0;
    return ast;
}