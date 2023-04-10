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

void* parser_expect_token(Parser* parser, enum TokenType type);

AST* parse_code(Parser* parser);

AST* code_parse_statements(Parser* parser);

AST* code_parse_statement(Parser* parser);

AST* code_parse_expression(Parser* parser);

AST* code_parse_factor(Parser* parser);

AST* code_parse_term(Parser* parser);

AST* code_parse_function_call(Parser* parser);

AST* code_parse_variable_def(Parser* parser);

AST* code_parse_variable(Parser* parser);

AST* code_parse_boolean(Parser* parser);

AST* code_parse_string(Parser* parser);

AST* code_parse_identifier(Parser* parser);

#endif