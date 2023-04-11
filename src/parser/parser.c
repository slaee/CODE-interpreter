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

// token matcher
void parser_expect_token(Parser* parser, enum TokenType type) {
    extern char* tokentype_str_value[];
    if(parser->current_token->type == type) {
        parser->previous_token = parser->current_token;
        parser->current_token = lex_next_token(parser->lexer);
        printf("%s\n", tokentype_str_value[type]);
    } else {
        printf(
            "Syntax Error: Unexpected token %s with type %s at line %d, col %d\n", 
            parser->current_token->value,
            tokentype_str_value[parser->current_token->type],
            parser->lexer->line, 
            parser->lexer->col
        );
        exit(1);
    }
}

void parser_expect_prev_or_current_token(Parser* parser, enum TokenType type1, enum TokenType type2) {
    extern char* tokentype_str_value[];
    if(parser->current_token->type == type1 || parser->current_token->type == type2) {
        parser->previous_token = parser->current_token;
        parser->current_token = lex_next_token(parser->lexer);
        printf("%s\n", tokentype_str_value[type1]);
    } else {
        printf(
            "Syntax Error: Unexpected token %s at line %d, col %d\n", 
            parser->current_token->value,
            parser->lexer->line, 
            parser->lexer->col
        );
        exit(1);
    }
}

// token peeker
int token_peek(Parser* parser) {
    return parser->current_token->type;
}

void* parser_skip_newlines(Parser* parser) {
    while(parser->current_token->type == TOKEN_NEWLINE) {
        parser_expect_token(parser, TOKEN_NEWLINE);
    }
}

// program parser
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
    code_parse_statement(parser); 
    while(token_peek(parser) == TOKEN_NEWLINE) {
        parser_expect_token(parser, TOKEN_NEWLINE);
        code_parse_statement(parser);
    }
}

// statement rule
AST* code_parse_statement(Parser* parser) {
    switch(token_peek(parser)) {
        case TOKEN_TYPE:
            code_parse_variable_declaration(parser);
            break;
        case TOKEN_IDENTIFIER:
            code_parse_assignment(parser);
            break;
    }
    
}

AST* code_parse_variable_declaration(Parser* parser) {
    parser_expect_token(parser, TOKEN_TYPE);
    parser_expect_token(parser, TOKEN_IDENTIFIER);

    if(token_peek(parser) == TOKEN_EQUAL) {
        code_parse_assignment(parser);
    }
    
    while(token_peek(parser) == TOKEN_COMMA) {
        code_parse_variable_declaration_prime(parser);
    }
}

AST* code_parse_variable_declaration_prime(Parser* parser) {
    parser_expect_token(parser, TOKEN_COMMA);
    parser_expect_token(parser, TOKEN_IDENTIFIER);
    if(token_peek(parser) == TOKEN_EQUAL) {
        code_parse_assignment(parser);
    }
}

AST* code_parse_assignment(Parser* parser) {
    if(parser->previous_token->type == TOKEN_IDENTIFIER) {
        parser_expect_token(parser, TOKEN_EQUAL);
        code_parse_expression(parser);
    } else {
        parser_expect_token(parser, TOKEN_IDENTIFIER);
        parser_expect_token(parser, TOKEN_EQUAL);
        code_parse_expression(parser);
    }
}


/*

    arithmetic_expression → term expressionprime                   
          expressionprime → '+' term expressionprime
                          | '-' term expressionprime 
                          | ε
                 term → factor termprime
                termprime → '*' factor termprime
                          | '/' factor termprime
                          | ε
                   factor → '+' factor 
                          | '-' factor 
                          | paren
                          | id
                          | number
                    paren → ( expression )
                   number → [0-9]+


         S -> T S'
         S' -> + T S'
            | - T S'
            | ε
          T -> F T'
         T' -> * F T'
            | / F T'
            | ε
          F -> + F
            | - F
            | ( S )
            | id
            | number

        1
        1 +  
*/

AST* code_parse_expression(Parser* parser) {
    switch(token_peek(parser)) {
        case TOKEN_PLUS:
        case TOKEN_MINUS:
            code_parse_arithmetic_expression(parser);
            break;
        case TOKEN_IDENTIFIER:
        case TOKEN_NUMBER:
        case TOKEN_LPAREN:
            code_parse_arithmetic_expression(parser);
            break;
        default:
            printf("Syntax Error: invalid at line %d, col %d\n", 
                parser->lexer->line, 
                parser->lexer->col
            );
            exit(1);
    }
}

AST* code_parse_arithmetic_expression(Parser* parser) {
    code_parse_term(parser);
    while (token_peek(parser) == TOKEN_PLUS || token_peek(parser) == TOKEN_MINUS) {
        code_parse_arithmetic_expression_prime(parser);
    }
}

AST* code_parse_arithmetic_expression_prime(Parser* parser) {
    switch(token_peek(parser)) {
        case TOKEN_PLUS:
            parser_expect_token(parser, TOKEN_PLUS);
            code_parse_term(parser);
            break;
        case TOKEN_MINUS:
            parser_expect_token(parser, TOKEN_MINUS);
            code_parse_term(parser);
            break;
    }
}

AST* code_parse_term(Parser* parser){
    code_parse_factor(parser);
    while (token_peek(parser) == TOKEN_STAR || token_peek(parser) == TOKEN_SLASH) {
        code_parse_term_prime(parser);
    }
}

AST* code_parse_term_prime(Parser* parser){
    switch(token_peek(parser)) {
        case TOKEN_STAR:
            parser_expect_token(parser, TOKEN_STAR);
            code_parse_factor(parser);
            break;
        case TOKEN_SLASH:
            parser_expect_token(parser, TOKEN_SLASH);
            code_parse_factor(parser);
            break;
    }
}

AST* code_parse_factor(Parser* parser){
    switch(token_peek(parser)) {
        case TOKEN_PLUS:
            parser_expect_token(parser, TOKEN_PLUS);
            if(token_peek(parser) == TOKEN_IDENTIFIER)
                parser_expect_token(parser, TOKEN_IDENTIFIER);
            else if(token_peek(parser) == TOKEN_NUMBER)
                parser_expect_token(parser, TOKEN_NUMBER);
            else {
                printf(
                    "Syntax Error: Unexpected token %s at line %d, col %d\n", 
                    parser->current_token->value,
                    parser->lexer->line, 
                    parser->lexer->col
                );
                exit(1);
            }
            break;
        case TOKEN_MINUS:
            parser_expect_token(parser, TOKEN_MINUS);
            if(token_peek(parser) == TOKEN_IDENTIFIER)
                parser_expect_token(parser, TOKEN_IDENTIFIER);
            else if(token_peek(parser) == TOKEN_NUMBER)
                parser_expect_token(parser, TOKEN_NUMBER);
            else {
                printf(
                    "Syntax Error: Unexpected token %s at line %d, col %d\n", 
                    parser->current_token->value,
                    parser->lexer->line, 
                    parser->lexer->col
                );
                exit(1);
            }
            break;
        case TOKEN_LPAREN:
            code_parse_paren(parser);
            break;
        case TOKEN_IDENTIFIER:
            parser_expect_token(parser, TOKEN_IDENTIFIER);
            break;
        case TOKEN_NUMBER:
            parser_expect_token(parser, TOKEN_NUMBER);
            break;
        default:
            printf(
                "Syntax Error: Unexpected token %s at line %d, col %d\n", 
                parser->previous_token->value,
                parser->lexer->line, 
                parser->lexer->col
            );
            exit(1);
    }
}

AST* code_parse_paren(Parser* parser){
    parser_expect_token(parser, TOKEN_LPAREN);
    code_parse_expression(parser);
    parser_expect_token(parser, TOKEN_RPAREN);
}

AST* code_parse_function_call(Parser* parser){
    
}

AST* code_parse_args(Parser* parser){
    
}


AST* code_parse_args_prime(Parser* parser){
    
}

AST* code_parse_arg(Parser* parser){
    
}

AST* code_parse_string_val(Parser* parser){
    
}

AST* code_parse_string_val_prime(Parser* parser){
    
}

AST* code_parse_string(Parser* parser){
    
}

AST* code_parse_function_declaration(Parser* parser){
    
}

AST* code_parse_function_params(Parser* parser){
    
}

AST* code_parse_function_params_prime(Parser* parser){
    
}

AST* code_parse_function_definition(Parser* parser){
    
}

AST* code_parse_function_return_statement(Parser* parser){
    
}

AST* code_parse_switch_case(Parser* parser){
    
}

AST* code_parse_boolean_expression(Parser* parser){
    
}

AST* code_parse_boolean_expression_prime(Parser* parser){
    
}

AST* code_parse_bool_term(Parser* parser){
    
}

AST* code_parse_case_statements(Parser* parser){
    
}

AST* code_parse_case_statement(Parser* parser){
    
}

AST* code_parse_if_statement(Parser* parser){
    
}

AST* code_parse_else_if_statements(Parser* parser){
    
}

AST* code_parse_else_if_statement(Parser* parser){
    
}

AST* code_parse_else_statement(Parser* parser){
    
}

AST* code_parse_while_loop(Parser* parser){
    
}

AST* code_parse_for_loop(Parser* parser){
    
}

AST* code_parse_do_while_loop(Parser* parser){
    
}

/*
    program: NEWLINE* BEGIN CODE NEWLINE* statements END CODE NEWLINE*
*/
// AST* parse_code(Parser* parser) {
//     AST* ast = NULL;
//     parser_skip_newlines(parser);
//     parser_expect_token(parser, TOKEN_BEGIN);
//     parser_expect_token(parser, TOKEN_CODE);
//     parser_expect_token(parser, TOKEN_NEWLINE);
//     ast = code_parse_statements(parser);
//     parser_expect_token(parser, TOKEN_END);
//     parser_expect_token(parser, TOKEN_CODE);
//     parser_skip_newlines(parser);
//     return ast;
// }

// AST* code_parse_statements(Parser* parser) {
//     AST* compound = init_code_ast(AST_COMPOUND);
//     compound->compound_value = (AST**) malloc(sizeof(AST*));

//     AST* statement = code_parse_statement(parser);
//     compound->compound_value[0] = statement;
//     compound->compound_size += 1;

//     while(parser->current_token->type == TOKEN_NEWLINE) {
//         parser_expect_token(parser, TOKEN_NEWLINE);
//         AST* statement = code_parse_statement(parser);
//         if (statement) {
//             compound->compound_value = (AST**) realloc(
//             compound->compound_value, 
//                 sizeof(AST*) * (compound->compound_size + 1)
//             );
//             compound->compound_value[compound->compound_size] = statement;
//             compound->compound_size += 1;
//         }
//     }

//     return compound;
// }

// AST* code_parse_statement(Parser* parser) {
//     switch(parser->current_token->type) {
//         case TOKEN_TYPE: return code_parse_identifier(parser);
//         case TOKEN_IDENTIFIER: return code_parse_identifier(parser);
//     }

//     return init_code_ast(AST_NOOP);
// }

// AST* code_parse_expression(Parser* parser) {
//     switch(parser->current_token->type) {
//         case TOKEN_BOOLEAN: return code_parse_boolean(parser);
//         case TOKEN_IDENTIFIER: return code_parse_identifier(parser);
//     }

//     return init_code_ast(AST_NOOP);
// }

// AST* code_parse_factor(Parser* parser) {

// }

// AST* code_parse_term(Parser* parser) {

// }

// AST* code_parse_function_call(Parser* parser) {
//     AST* func_call = init_code_ast(AST_FUNCTION_CALL);
//     func_call->func_call_name = parser->previous_token->value;
//     parser_expect_token(parser, TOKEN_COLON);
//     func_call->func_call_args = (AST**) malloc(sizeof(AST*));

//     AST* expr = code_parse_expression(parser);
//     func_call->func_call_args[0] = expr;
//     func_call->func_call_args_size += 1;

//     while(parser->current_token->type == TOKEN_COMMA) {
//         parser_expect_token(parser, TOKEN_COMMA);
//         AST* expr = code_parse_expression(parser);
//         func_call->func_call_args = (AST**) realloc(
//             func_call->func_call_args, 
//             sizeof(AST*) * (func_call->func_call_args_size + 1)
//         );
//         func_call->func_call_args[func_call->func_call_args_size] = expr;
//         func_call->func_call_args_size += 1;
//     }

//     return func_call;
// }

// AST* code_parse_boolean(Parser* parser) {
//     char* token_value = parser->current_token->value;
//     parser_expect_token(parser, TOKEN_BOOLEAN);
   
//     AST* boolean = init_code_ast(AST_BOOLEAN);
//     boolean->boolean_value = token_value;
//     return boolean;
// }

// AST* code_parse_string(Parser* parser) {
//     char* token_value = parser->current_token->value;
//     parser_expect_token(parser, TOKEN_STRING);

//     AST* string = init_code_ast(AST_STRING);
//     string->string_value = token_value;
//     return string;
// }


// AST* code_parse_variable(Parser* parser) {
//     char* token_value = parser->current_token->value;
//     parser_expect_token(parser, TOKEN_IDENTIFIER); // variable name or function call name
//     if(parser->current_token->type == TOKEN_COLON) {
//         return code_parse_function_call(parser);
//     }
        
//     AST* variable = init_code_ast(AST_VARIABLE);
//     variable->variable_name = token_value;

//     return variable;
// }

// AST* code_parse_variable_def(Parser* parser) {
//     parser_expect_token(parser, TOKEN_TYPE); // type: INT, FLOAT, BOOL, CHAR
//     char* type = parser->current_token->value;
//     parser_expect_token(parser, TOKEN_IDENTIFIER); // INT a
//     parser_expect_token(parser, TOKEN_EQUAL);
//     AST* variable_value = code_parse_expression(parser);

//     AST* variable_def = init_code_ast(AST_VARIABLE_DEFINITION);
//     variable_def->variable_def_name = type;
//     variable_def->variable_def_value = variable_value;

//     return variable_def;
// }

// AST* code_parse_identifier(Parser* parser) {
//     if(parser->current_token->type == TOKEN_TYPE) {
//         return code_parse_variable_def(parser);
//     }
    
//     return code_parse_variable(parser);
// }
