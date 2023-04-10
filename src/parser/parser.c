#include <stdio.h>
#include <string.h>
#include "parser.h"

Parser* init_code_parser(Lexer* lexer) {
    Parser* parser = (Parser*) malloc(sizeof(Parser));
    parser->lexer = lexer;
    parser->current_token = lex_next_token(lexer);
    parser->previous_token = parser->current_token;
    
    return parser;
}

void* parser_expect_token(Parser* parser, enum TokenType type) {
    extern char* tokentype_str_value[];
    if(parser->current_token->type == type) {
        parser->previous_token = parser->current_token;
        parser->current_token = lex_next_token(parser->lexer);
    } else {
        printf(
            "Unexpected token: %s with type %s at line %d, col %d\n", 
            parser->current_token->value,
            tokentype_str_value[parser->current_token->type],
            parser->lexer->line, 
            parser->lexer->col
        );
        exit(1);
    }
}

void* parser_skip_newlines(Parser* parser) {
    while(parser->current_token->type == TOKEN_NEWLINE) {
        parser_expect_token(parser, TOKEN_NEWLINE);
    }
}

/*
    program: NEWLINE* BEGIN CODE NEWLINE* statements END CODE NEWLINE*
*/
AST* parse_code(Parser* parser) {
    AST* ast = NULL;
    parser_skip_newlines(parser);
    parser_expect_token(parser, TOKEN_BEGIN);
    parser_expect_token(parser, TOKEN_CODE);
    parser_expect_token(parser, TOKEN_NEWLINE);
    ast = code_parse_statements(parser);
    parser_expect_token(parser, TOKEN_END);
    parser_expect_token(parser, TOKEN_CODE);
    parser_skip_newlines(parser);
    return ast;
}

AST* code_parse_statements(Parser* parser) {
    AST* compound = init_code_ast(AST_COMPOUND);
    compound->compound_value = (AST**) malloc(sizeof(AST*));

    AST* statement = code_parse_statement(parser);
    compound->compound_value[0] = statement;
    compound->compound_size += 1;

    while(parser->current_token->type == TOKEN_NEWLINE) {
        parser_expect_token(parser, TOKEN_NEWLINE);
        AST* statement = code_parse_statement(parser);
        if (statement) {
            compound->compound_value = (AST**) realloc(
            compound->compound_value, 
                sizeof(AST*) * (compound->compound_size + 1)
            );
            compound->compound_value[compound->compound_size] = statement;
            compound->compound_size += 1;
        }
    }

    return compound;
}

AST* code_parse_statement(Parser* parser) {
    switch(parser->current_token->type) {
        case TOKEN_TYPE: return code_parse_identifier(parser);
        case TOKEN_IDENTIFIER: return code_parse_identifier(parser);
    }

    return init_code_ast(AST_NOOP);
}

AST* code_parse_expression(Parser* parser) {
    switch(parser->current_token->type) {
        case TOKEN_BOOLEAN: return code_parse_boolean(parser);
        case TOKEN_IDENTIFIER: return code_parse_identifier(parser);
    }

    return init_code_ast(AST_NOOP);
}

AST* code_parse_factor(Parser* parser) {

}

AST* code_parse_term(Parser* parser) {

}

AST* code_parse_function_call(Parser* parser) {
    AST* func_call = init_code_ast(AST_FUNCTION_CALL);
    func_call->func_call_name = parser->previous_token->value;
    parser_expect_token(parser, TOKEN_COLON);
    func_call->func_call_args = (AST**) malloc(sizeof(AST*));

    AST* expr = code_parse_expression(parser);
    func_call->func_call_args[0] = expr;
    func_call->func_call_args_size += 1;

    while(parser->current_token->type == TOKEN_COMMA) {
        parser_expect_token(parser, TOKEN_COMMA);
        AST* expr = code_parse_expression(parser);
        func_call->func_call_args = (AST**) realloc(
            func_call->func_call_args, 
            sizeof(AST*) * (func_call->func_call_args_size + 1)
        );
        func_call->func_call_args[func_call->func_call_args_size] = expr;
        func_call->func_call_args_size += 1;
    }

    return func_call;
}

AST* code_parse_boolean(Parser* parser) {
    char* token_value = parser->current_token->value;
    parser_expect_token(parser, TOKEN_BOOLEAN);
   
    AST* boolean = init_code_ast(AST_BOOLEAN);
    boolean->boolean_value = token_value;
    return boolean;
}

AST* code_parse_string(Parser* parser) {
    char* token_value = parser->current_token->value;
    parser_expect_token(parser, TOKEN_STRING);

    AST* string = init_code_ast(AST_STRING);
    string->string_value = token_value;
    return string;
}


AST* code_parse_variable(Parser* parser) {
    char* token_value = parser->current_token->value;
    parser_expect_token(parser, TOKEN_IDENTIFIER); // variable name or function call name
    if(parser->current_token->type == TOKEN_COLON) {
        return code_parse_function_call(parser);
    }
        
    AST* variable = init_code_ast(AST_VARIABLE);
    variable->variable_name = token_value;

    return variable;
}

AST* code_parse_variable_def(Parser* parser) {
    parser_expect_token(parser, TOKEN_TYPE); // type: INT, FLOAT, BOOL, CHAR
    char* type = parser->current_token->value;
    parser_expect_token(parser, TOKEN_IDENTIFIER); // INT a
    parser_expect_token(parser, TOKEN_EQUAL);
    AST* variable_value = code_parse_expression(parser);

    AST* variable_def = init_code_ast(AST_VARIABLE_DEFINITION);
    variable_def->variable_def_name = type;
    variable_def->variable_def_value = variable_value;

    return variable_def;
}

AST* code_parse_identifier(Parser* parser) {
    if(parser->current_token->type == TOKEN_TYPE) {
        return code_parse_variable_def(parser);
    }
    
    return code_parse_variable(parser);
}
