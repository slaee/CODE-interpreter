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
            parser_expect_token(parser, TOKEN_IDENTIFIER);
            if (token_peek(parser) == TOKEN_COLON) {
                code_parse_function_call(parser);
            } else {
                code_parse_assignment(parser);
            }
            break;
        case TOKEN_SWITCH:
            code_parse_switch_case(parser);
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
        if(token_peek(parser) == TOKEN_CHARACTER) 
            parser_expect_token(parser, TOKEN_CHARACTER);
        else 
            code_parse_expression(parser);
    } else {
        parser_expect_token(parser, TOKEN_IDENTIFIER);
        parser_expect_token(parser, TOKEN_EQUAL);
        if(token_peek(parser) == TOKEN_CHARACTER) 
            parser_expect_token(parser, TOKEN_CHARACTER);
        else 
            code_parse_expression(parser);
    }
}

AST* code_parse_expression(Parser* parser) {
    switch(token_peek(parser)) {
        case TOKEN_IDENTIFIER:
            parser_expect_token(parser, TOKEN_IDENTIFIER);
            switch(token_peek(parser)) {
                case TOKEN_PLUS:
                case TOKEN_MINUS:
                case TOKEN_STAR:
                case TOKEN_SLASH:
                    code_parse_arithmetic_expression(parser);
                    break;
                
                case TOKEN_AMPERSAND:
                    while(token_peek(parser) == TOKEN_AMPERSAND) {
                        code_parse_string_val_expression_prime(parser);
                    }
                    break;
                
                case TOKEN_LESSTHAN:
                case TOKEN_GREATERTHAN:
                case TOKEN_GREATEREQUAL:
                case TOKEN_LESSEQUAL:
                case TOKEN_EQEQUAL:
                case TOKEN_NOTEQUAL:
                case TOKEN_AND:
                case TOKEN_OR:
                     while(token_peek(parser) == TOKEN_LESSTHAN || 
                        token_peek(parser) == TOKEN_GREATERTHAN ||
                        token_peek(parser) == TOKEN_GREATEREQUAL ||
                        token_peek(parser) == TOKEN_LESSEQUAL ||
                        token_peek(parser) == TOKEN_EQEQUAL ||
                        token_peek(parser) == TOKEN_NOTEQUAL ||
                        token_peek(parser) == TOKEN_AND ||
                        token_peek(parser) == TOKEN_OR ||
                        token_peek(parser) == TOKEN_NOT) {
                            code_parse_boolean_expression_prime(parser);
                        }
                    break;
            }
            break;
        case TOKEN_LPAREN:
            code_parse_paren(parser);
            switch(token_peek(parser)) {
                case TOKEN_PLUS:
                case TOKEN_MINUS:
                case TOKEN_STAR:
                case TOKEN_SLASH:
                    code_parse_arithmetic_expression(parser);
                    break;
                
                case TOKEN_AMPERSAND:
                    code_parse_string_val_expression(parser);
                    break;
                
                case TOKEN_LESSTHAN:
                case TOKEN_GREATERTHAN:
                case TOKEN_GREATEREQUAL:
                case TOKEN_LESSEQUAL:
                case TOKEN_EQEQUAL:
                case TOKEN_NOTEQUAL:
                case TOKEN_AND:
                case TOKEN_OR:
                case TOKEN_NOT:
                    while(token_peek(parser) == TOKEN_LESSTHAN || 
                        token_peek(parser) == TOKEN_GREATERTHAN ||
                        token_peek(parser) == TOKEN_GREATEREQUAL ||
                        token_peek(parser) == TOKEN_LESSEQUAL ||
                        token_peek(parser) == TOKEN_EQEQUAL ||
                        token_peek(parser) == TOKEN_NOTEQUAL ||
                        token_peek(parser) == TOKEN_AND ||
                        token_peek(parser) == TOKEN_OR ||
                        token_peek(parser) == TOKEN_NOT) {
                            code_parse_boolean_expression_prime(parser);
                        }
                    break;
            }
            break;
        case TOKEN_PLUS:
        case TOKEN_MINUS:
        case TOKEN_NUMBER:
            code_parse_arithmetic_expression(parser);
            break;
        case TOKEN_STRING:
            code_parse_string_val_expression(parser);
            break;
        case TOKEN_BOOLEAN:
            code_parse_boolean_expression(parser);
            break;
        default:
            printf("Syntax Error: invalid syntax at line %d, col %d\n", 
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
                code_parse_paren(parser);
            }
            break;
        case TOKEN_MINUS:
            parser_expect_token(parser, TOKEN_MINUS);
            if(token_peek(parser) == TOKEN_IDENTIFIER)
                parser_expect_token(parser, TOKEN_IDENTIFIER);
            else if(token_peek(parser) == TOKEN_NUMBER)
                parser_expect_token(parser, TOKEN_NUMBER);
            else {
                code_parse_paren(parser);
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
    if(parser->previous_token->type == TOKEN_IDENTIFIER) {
        parser_expect_token(parser, TOKEN_COLON);
        code_parse_args(parser);
    } 
}

AST* code_parse_args(Parser* parser){
    code_parse_arg(parser);

    while(token_peek(parser) == TOKEN_COMMA) {
        code_parse_args_prime(parser);
    }
}


AST* code_parse_args_prime(Parser* parser){
    parser_expect_token(parser, TOKEN_COMMA);
    code_parse_arg(parser);
}

AST* code_parse_arg(Parser* parser){
    code_parse_expression(parser);
}

AST* code_parse_string_val_expression(Parser* parser){
    parser_expect_token(parser, TOKEN_STRING);
    while(token_peek(parser) == TOKEN_AMPERSAND) {
        code_parse_string_val_expression_prime(parser);
    }
}

AST* code_parse_string_val_expression_prime(Parser* parser){
    if(token_peek(parser) == TOKEN_AMPERSAND) {
        parser_expect_token(parser, TOKEN_AMPERSAND);
        code_parse_constants(parser);
    }
}

AST* code_parse_constants(Parser* parser){
    switch(token_peek(parser)) {
        case TOKEN_STRING:
            parser_expect_token(parser, TOKEN_STRING);
            break;
        case TOKEN_NUMBER:
            parser_expect_token(parser, TOKEN_NUMBER);
            break;
        case TOKEN_BOOLEAN:
            parser_expect_token(parser, TOKEN_BOOLEAN);
            break;
        case TOKEN_IDENTIFIER:
            parser_expect_token(parser, TOKEN_IDENTIFIER);
            break;
        case TOKEN_LPAREN:
            code_parse_paren(parser);
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
    parser_expect_token(parser, TOKEN_SWITCH);
    parser_expect_token(parser, TOKEN_LPAREN);
    code_parse_expression(parser);
    parser_expect_token(parser, TOKEN_RPAREN);
    parser_expect_token(parser, TOKEN_NEWLINE);
    parser_expect_token(parser, TOKEN_BEGIN);
    parser_expect_token(parser, TOKEN_SWITCH);
    parser_expect_token(parser, TOKEN_NEWLINE);
    code_parse_case_statements(parser);
    parser_expect_token(parser, TOKEN_END);
    parser_expect_token(parser, TOKEN_SWITCH);
}

AST* code_parse_boolean_expression(Parser* parser){
    parser_expect_token(parser, TOKEN_BOOLEAN);

    while(token_peek(parser) == TOKEN_LESSTHAN || 
        token_peek(parser) == TOKEN_GREATERTHAN ||
        token_peek(parser) == TOKEN_GREATEREQUAL ||
        token_peek(parser) == TOKEN_LESSEQUAL ||
        token_peek(parser) == TOKEN_EQEQUAL ||
        token_peek(parser) == TOKEN_NOTEQUAL ||
        token_peek(parser) == TOKEN_AND ||
        token_peek(parser) == TOKEN_OR ||
        token_peek(parser) == TOKEN_NOT) {
            code_parse_boolean_expression_prime(parser);
        }
}

AST* code_parse_boolean_expression_prime(Parser* parser){
    switch(token_peek(parser)) {
        case TOKEN_LESSTHAN:
            parser_expect_token(parser, TOKEN_LESSTHAN);
            code_parse_boolean_factor(parser);
            break;
        case TOKEN_GREATERTHAN:
            parser_expect_token(parser, TOKEN_GREATERTHAN);
            code_parse_boolean_factor(parser);
            break;
        case TOKEN_GREATEREQUAL:
            parser_expect_token(parser, TOKEN_GREATEREQUAL);
            code_parse_boolean_factor(parser);
            break;
        case TOKEN_LESSEQUAL:
            parser_expect_token(parser, TOKEN_LESSEQUAL);
            code_parse_boolean_factor(parser);
            break;
        case TOKEN_EQEQUAL:
            parser_expect_token(parser, TOKEN_EQEQUAL);
            code_parse_boolean_factor(parser);
            break;
        case TOKEN_NOTEQUAL:
            parser_expect_token(parser, TOKEN_NOTEQUAL);
            code_parse_boolean_factor(parser);
            break;
        case TOKEN_AND:
            parser_expect_token(parser, TOKEN_AND);
            code_parse_boolean_factor(parser);
            break;
        case TOKEN_OR:
            parser_expect_token(parser, TOKEN_OR);
            code_parse_boolean_factor(parser);
            break;
        case TOKEN_NOT:
            parser_expect_token(parser, TOKEN_NOT);
            code_parse_boolean_factor(parser);
            break;
    }
}

AST* code_parse_boolean_factor(Parser* parser){
    switch(token_peek(parser)){
        case TOKEN_BOOLEAN:
            parser_expect_token(parser, TOKEN_BOOLEAN);
            break;
        case TOKEN_IDENTIFIER:
            parser_expect_token(parser, TOKEN_IDENTIFIER);
            break;
        case TOKEN_LPAREN:
            code_parse_paren(parser);
            break;
    }
}

AST* code_parse_case_statements(Parser* parser){
    code_parse_case_statement(parser);
    while(token_peek(parser) == TOKEN_CASE) {
        code_parse_case_statement(parser);
    }
}

AST* code_parse_case_statement(Parser* parser){
    switch(token_peek(parser)) {
        case TOKEN_CASE:
            code_parse_case(parser);
            break;
        case TOKEN_DEFAULT:
            code_parse_default(parser);
            break;
    }
}

AST* code_parse_case(Parser* parser){
    parser_expect_token(parser, TOKEN_CASE);
    code_parse_case_factor(parser);
    parser_expect_token(parser, TOKEN_COLON);
    parser_expect_token(parser, TOKEN_NEWLINE);
    code_parse_statements(parser);
    if(token_peek(parser) == TOKEN_BREAK) {
        parser_expect_token(parser, TOKEN_BREAK);
        parser_expect_token(parser, TOKEN_NEWLINE);
    }
}

AST* code_parse_default(Parser* parser){
    parser_expect_token(parser, TOKEN_DEFAULT);
    code_parse_case_factor(parser);
    parser_expect_token(parser, TOKEN_COLON);
    parser_expect_token(parser, TOKEN_NEWLINE);
    code_parse_statements(parser);
    if(token_peek(parser) == TOKEN_BREAK) {
        parser_expect_token(parser, TOKEN_BREAK);
        parser_expect_token(parser, TOKEN_NEWLINE);
    }
}

AST* code_parse_case_factor(Parser* parser) {
    switch(token_peek(parser)) {
        case TOKEN_IDENTIFIER:
            parser_expect_token(parser, TOKEN_IDENTIFIER);
            break;
        case TOKEN_NUMBER:
            parser_expect_token(parser, TOKEN_NUMBER);
            break;
        case TOKEN_CHARACTER:
            parser_expect_token(parser, TOKEN_CHARACTER);
            break;
    }
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
