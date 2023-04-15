#ifndef _PARSER_H_
#define _PARSER_H_

#include "lexer.h"
#include "ast.h"

typedef struct parser{
    Lexer* lexer;
    Token* current_token;
    Token* previous_token;
} Parser;

Parser* init_code_parser(Lexer* lexer);

void parser_expect_token(Parser* parser, enum TokenType type);

// AST* parse_code(Parser* parser);

// AST* code_parse_statements(Parser* parser);

// AST* code_parse_statement(Parser* parser);

// AST* code_parse_expression(Parser* parser);

// AST* code_parse_factor(Parser* parser);

// AST* code_parse_term(Parser* parser);

// AST* code_parse_function_call(Parser* parser);

// AST* code_parse_variable_def(Parser* parser);
// AST* code_parse_variable(Parser* parser);

// AST* code_parse_boolean(Parser* parser);

// AST* code_parse_string(Parser* parser);

// AST* code_parse_identifier(Parser* parser);

AST* parse_code(Parser* parser);

AST* code_parse_statements(Parser* parser);

AST* code_parse_statement(Parser* parser);

AST* code_parse_variable_declaration(Parser* parser);

AST* code_parse_variable_declaration_prime(Parser* parser);

AST* code_parse_assignment(Parser* parser);

AST* code_parse_expression(Parser* parser);

AST* code_parse_arithmetic_expression(Parser* parser);

AST* code_parse_arithmetic_expression_prime(Parser* parser);

AST* code_parse_term(Parser* parser);

AST* code_parse_term_prime(Parser* parser);

AST* code_parse_factor(Parser* parser);

AST* code_parse_paren(Parser* parser);

AST* code_parse_function_call(Parser* parser);

AST* code_parse_args(Parser* parser);

AST* code_parse_args_prime(Parser* parser);

AST* code_parse_arg(Parser* parser);

AST* code_parse_string_val_expression(Parser* parser);

AST* code_parse_string_val_expression_prime(Parser* parser);

AST* code_parse_constants(Parser* parser);

AST* code_parse_string(Parser* parser);

AST* code_parse_function_declaration(Parser* parser);

AST* code_parse_function_params(Parser* parser);

AST* code_parse_function_params_prime(Parser* parser);

AST* code_parse_function_definition(Parser* parser);

AST* code_parse_function_return_statement(Parser* parser);

AST* code_parse_switch_case(Parser* parser);

AST* code_parse_boolean_expression(Parser* parser);

AST* code_parse_boolean_expression_prime(Parser* parser);

AST* code_parse_boolean_factor(Parser* parser);

AST* code_parse_case_statements(Parser* parser);

AST* code_parse_case_statement(Parser* parser);

AST* code_parse_case(Parser* parser);

AST* code_parse_default(Parser* parser);

AST* code_parse_case_factor(Parser* parser);

AST* code_parse_if_statement(Parser* parser);

AST* code_parse_if_else_statements(Parser* parser);

AST* code_parse_else_statement(Parser* parser);

AST* code_parse_while_loop(Parser* parser);

AST* code_parse_for_loop(Parser* parser);

AST* code_parse_do_while_loop(Parser* parser);

AST* code_parse_break_statement(Parser* parser);

AST* code_parse_continue_statement(Parser* parser);

#endif