#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "types.h"

static TokenStream* tokens = NULL;

Parser* init_code_parser(Lexer* lexer) {
    tokens = lex_tokenize(lexer);
    Parser* parser = (Parser*) malloc(sizeof(Parser));
    parser->lexer = lexer;
    parser->current_token = ts_advance(tokens);
    parser->previous_token = parser->current_token;
    return parser;
}

// token matcher
void parser_expect_token(Parser* parser, enum TokenType type) {
    extern char* tokentype_str_value[];
    if(parser->current_token->type == type) {
        parser->previous_token = parser->current_token;
        parser->current_token = ts_advance(tokens);
        //printf("%s\n", tokentype_str_value[type]);
    } else {
        printf(
            "Syntax Error: Unexpected token type name ‘%s’ at line %d, col %d\n", 
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
    AST* ast = init_code_ast(AST_COMPOUND);
    ast->children = init_children(sizeof(AST*));
    parser_skip_newlines(parser);
    parser_expect_token(parser, TOKEN_BEGIN);
    parser_expect_token(parser, TOKEN_CODE);
    parser_expect_token(parser, TOKEN_NEWLINE);
    ast_add_child(ast, code_parse_declarations_statements(parser));
    ast_add_child(ast, code_parse_executable_statements(parser));
    parser_expect_token(parser, TOKEN_END);
    parser_expect_token(parser, TOKEN_CODE);
    parser_skip_newlines(parser);
    parser_expect_token(parser, TOKEN_EOF);
    return ast;
}

AST* code_parse_declarations_statements(Parser* parser) {
    AST* declarations = init_code_ast(AST_DECLARATIONS);
    declarations->children = init_children(sizeof(AST*));

    while(token_peek(parser) == TOKEN_TYPE) {
        ast_add_child(declarations, code_parse_variable_declaration(parser));
        parser_expect_token(parser, TOKEN_NEWLINE);
    }

    return declarations;
}

AST* code_parse_executable_statements(Parser* parser) {
    AST* executable = init_code_ast(AST_EXECUTABLES);
    executable->children = init_children(sizeof(AST*));
    
    while(token_peek(parser) != TOKEN_END) {
        if(token_peek(parser) == TOKEN_TYPE) {
            printf(
                "Syntax Error: Declaration at line %d, col %d must be before executable.\n", 
                parser->lexer->line, 
                parser->lexer->col
            );
            exit(1);
        }
        
        ast_add_child(executable, code_parse_executable_statement(parser));
        parser_expect_token(parser, TOKEN_NEWLINE);
    }

    return executable;
}

// statement rule
AST* code_parse_executable_statement(Parser* parser) {
    switch(token_peek(parser)) {
        case TOKEN_IDENTIFIER:
            parser_expect_token(parser, TOKEN_IDENTIFIER);
            if (token_peek(parser) == TOKEN_COLON) {
                return code_parse_function_call(parser);
            } else {
                return code_parse_assignment(parser);
            }
        case TOKEN_SWITCH:
            return code_parse_switch_case(parser);
        case TOKEN_IF:
            return code_parse_if_else_statements(parser);
        case TOKEN_WHILE:
            return code_parse_while_loop(parser);
        case TOKEN_BREAK:
            return code_parse_break_statement(parser);
        case TOKEN_CONTINUE:
            return code_parse_continue_statement(parser);
    }

    return init_code_ast(AST_NOOP);
}

AST* code_parse_variable_declaration(Parser* parser) {
    AST* variable_decls = init_code_ast(AST_VARIABLE_DECLS);
    /**/ variable_decls->children = init_children(sizeof(AST*));

    AST* variable_decl = init_code_ast(AST_VARIABLE);
    /**/ variable_decl->data_type = to_data_type(parser->current_token->value);
    parser_expect_token(parser, TOKEN_TYPE);
    /**/ variable_decl->name = parser->current_token->value;
    parser_expect_token(parser, TOKEN_IDENTIFIER);
    
    if(token_peek(parser) == TOKEN_EQUAL) {
        parser_expect_token(parser, TOKEN_EQUAL);
        /**/ variable_decl->value = code_parse_expression(parser);
    } 
    
    ast_add_child(variable_decls, variable_decl);

    if(token_peek(parser) == TOKEN_LPAREN) {
        // todo function declaration
    }

    while(token_peek(parser) == TOKEN_COMMA) {
        ast_add_child(variable_decls, code_parse_variable_declaration_prime(parser, variable_decl->data_type));
    }

    return variable_decls;
}

AST* code_parse_variable_declaration_prime(Parser* parser, int data_type) {
    parser_expect_token(parser, TOKEN_COMMA);
    AST* variable_decl = init_code_ast(AST_VARIABLE);
    /**/ variable_decl->data_type = data_type;
    /**/ variable_decl->name = parser->current_token->value;
    parser_expect_token(parser, TOKEN_IDENTIFIER);

    if(token_peek(parser) == TOKEN_EQUAL) {
        parser_expect_token(parser, TOKEN_EQUAL);
        /**/ variable_decl->value = code_parse_expression(parser);
    } 

    return variable_decl;
}

AST* code_parse_assignment(Parser* parser) {
    AST* assignment = init_code_ast(AST_ASSIGNMENT);

    /**/ assignment->target_name = parser->previous_token->value;
    if(parser->previous_token->type == TOKEN_IDENTIFIER) {
        parser_expect_token(parser, TOKEN_EQUAL);
        assignment->value = code_parse_expression(parser);
    } else {
        /**/ assignment->target_name = parser->current_token->value;
        parser_expect_token(parser, TOKEN_IDENTIFIER);
        parser_expect_token(parser, TOKEN_EQUAL);
        /**/ assignment->value = code_parse_expression(parser);
    }
    
    return assignment;
}

AST* code_parse_expression(Parser* parser) {
    switch(token_peek(parser)) {
        case TOKEN_IDENTIFIER:
            switch(ts_lookahead(tokens, 0)) {
                case TOKEN_EQUAL:
                    return code_parse_assignment(parser);

                case TOKEN_PLUS:
                case TOKEN_MINUS:
                case TOKEN_STAR:
                case TOKEN_SLASH:
                case TOKEN_PERCENT:
                    return code_parse_arithmetic_expression(parser);
                
                case TOKEN_AMPERSAND:
                    return code_parse_string_val_expression(parser);
                
                case TOKEN_LESSTHAN:
                case TOKEN_GREATERTHAN:
                case TOKEN_GREATEREQUAL:
                case TOKEN_LESSEQUAL:
                case TOKEN_EQEQUAL:
                case TOKEN_NOTEQUAL:
                case TOKEN_AND:
                case TOKEN_OR:
                    return code_parse_boolean_expression(parser);

                default:
                    AST* identifier = init_code_ast(AST_VARIABLE);
                    /**/ identifier->name = parser->current_token->value;
                    parser_expect_token(parser, TOKEN_IDENTIFIER);
                    return identifier;
            }
            break;
        case TOKEN_LPAREN:
            // do not call the code_parse_paren since it will consume the closing paren

            int i = 0;
            // so make advance until we find the closing paren
            while(ts_lookahead(tokens, i) != TOKEN_RPAREN) i++;
            
            // then examine the token after the closing paren
            switch(ts_lookahead(tokens, i + 1)) {
                case TOKEN_PLUS:
                case TOKEN_MINUS:
                case TOKEN_STAR:
                case TOKEN_SLASH:
                case TOKEN_PERCENT:
                    return code_parse_arithmetic_expression(parser);
                
                case TOKEN_AMPERSAND:
                    return code_parse_string_val_expression(parser);
                
                case TOKEN_LESSTHAN:
                case TOKEN_GREATERTHAN:
                case TOKEN_GREATEREQUAL:
                case TOKEN_LESSEQUAL:
                case TOKEN_EQEQUAL:
                case TOKEN_NOTEQUAL:
                case TOKEN_AND:
                case TOKEN_OR:
                case TOKEN_NOT:
                    return code_parse_boolean_expression(parser);

                default:
                    return code_parse_paren(parser);
            }
            break;
        case TOKEN_PLUS:
        case TOKEN_MINUS:
        case TOKEN_STAR:
        case TOKEN_SLASH:
        case TOKEN_PERCENT:
        case TOKEN_NUMBER:
            switch(ts_lookahead(tokens, 0)) {
                case TOKEN_LESSTHAN:
                case TOKEN_GREATERTHAN:
                case TOKEN_GREATEREQUAL:
                case TOKEN_LESSEQUAL:
                case TOKEN_EQEQUAL:
                case TOKEN_NOTEQUAL:
                case TOKEN_AND:
                case TOKEN_OR:
                case TOKEN_NOT:
                    return code_parse_boolean_expression(parser);
            }
            return code_parse_arithmetic_expression(parser);

        case TOKEN_STRING:
            switch(ts_lookahead(tokens, 0)) {
                case TOKEN_LESSTHAN:
                case TOKEN_GREATERTHAN:
                case TOKEN_GREATEREQUAL:
                case TOKEN_LESSEQUAL:
                case TOKEN_EQEQUAL:
                case TOKEN_NOTEQUAL:
                case TOKEN_AND:
                case TOKEN_OR:
                case TOKEN_NOT:
                    return code_parse_boolean_expression(parser);
            }

        case TOKEN_DOLLAR:
        case TOKEN_LBRACKET:
            return code_parse_string_val_expression(parser);
            
        case TOKEN_BOOLEAN:
            return code_parse_boolean_expression(parser);

        case TOKEN_CHARACTER:
            AST* char_val = init_code_ast(AST_CHAR);
            char_val->character_value = parser->current_token->value[0];
            parser_expect_token(parser, TOKEN_CHARACTER);
            return char_val;

        default:
            printf("Syntax Error: invalid syntax at line %d, col %d\n", 
                parser->lexer->line, 
                parser->lexer->col
            );
            exit(1);
    }
}

AST* code_parse_arithmetic_expression(Parser* parser) {
    AST* left = code_parse_term(parser);
    return code_parse_arithmetic_expression_prime(parser, left);
}

AST* code_parse_arithmetic_expression_prime(Parser* parser, AST* left) {
    AST* expression = left;

    while (token_peek(parser) == TOKEN_PLUS || token_peek(parser) == TOKEN_MINUS) {
        AST* binop = init_code_ast(AST_ARITHMETIC_EXPRESSION);
        /**/ binop->left = left;
        switch(token_peek(parser)) {
            case TOKEN_PLUS:
                /**/ binop->operator = TOKEN_PLUS;
                parser_expect_token(parser, TOKEN_PLUS);
                /**/ binop->right = code_parse_term(parser);
                break;
            case TOKEN_MINUS:
                /**/ binop->operator = TOKEN_MINUS;
                parser_expect_token(parser, TOKEN_MINUS);
                /**/ binop->right = code_parse_term(parser);
                break;
        }
        expression = binop;
    }

    return expression;
}

AST* code_parse_term(Parser* parser){
    AST* left = code_parse_factor(parser);
    return code_parse_term_prime(parser, left);
}

AST* code_parse_term_prime(Parser* parser, AST* left){
    AST* term = left;
    while (token_peek(parser) == TOKEN_STAR || token_peek(parser) == TOKEN_SLASH || token_peek(parser) == TOKEN_PERCENT) {
        AST* binop = init_code_ast(AST_ARITHMETIC_EXPRESSION);
        /**/ binop->left = left;
        switch(token_peek(parser)) {
            case TOKEN_STAR:
                /**/ binop->operator = TOKEN_STAR;
                parser_expect_token(parser, TOKEN_STAR);
                binop->right = code_parse_factor(parser);
                break;
            case TOKEN_SLASH:
                /**/ binop->operator = TOKEN_SLASH;
                parser_expect_token(parser, TOKEN_SLASH);
                /**/ binop->right = code_parse_factor(parser);
                break;
            case TOKEN_PERCENT:
                /**/ binop->operator = TOKEN_PERCENT;
                parser_expect_token(parser, TOKEN_PERCENT);
                /**/ binop->right = code_parse_factor(parser);
                break;
        }
        term = binop;
    }

    return term;
}

AST* code_parse_unary(Parser* parser) {
    AST* unary = init_code_ast(AST_UNARY_EXPRESSION);
    switch(token_peek(parser)) {
        case TOKEN_PLUS:
            /**/ unary->operator = TOKEN_PLUS;
            parser_expect_token(parser, TOKEN_PLUS);
            /**/ unary->right = code_parse_factor(parser);
           break;
        case TOKEN_MINUS:
            /**/ unary->operator = TOKEN_MINUS;
            parser_expect_token(parser, TOKEN_MINUS);
            /**/ unary->right = code_parse_factor(parser);
            break;
    }

    return unary;
}

AST* code_parse_factor(Parser* parser){
    switch(token_peek(parser)) {
        // unary
        case TOKEN_PLUS:
        case TOKEN_MINUS:
            return code_parse_unary(parser);

        // literals
        case TOKEN_LPAREN:
            return code_parse_paren(parser);
        case TOKEN_IDENTIFIER:
            AST* identifier = init_code_ast(AST_VARIABLE);
            /**/ identifier->name = parser->current_token->value;
            parser_expect_token(parser, TOKEN_IDENTIFIER);
            return identifier;
        case TOKEN_NUMBER:
            AST* number = init_code_ast(AST_NUMBER);
            if(strchr(parser->current_token->value, '.')) {
                /**/ number->type = AST_FLOAT;
                /**/ number->float_value = atof(parser->current_token->value);
            } else {
                /**/ number->type = AST_INT;
                /**/ number->int_value = atoi(parser->current_token->value);
            }
            parser_expect_token(parser, TOKEN_NUMBER);
            return number;
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
    AST* expression = NULL;
    parser_expect_token(parser, TOKEN_LPAREN);
    expression = code_parse_expression(parser);
    expression->type = AST_PAREN_EXPRESSION;
    parser_expect_token(parser, TOKEN_RPAREN);
    return expression;
}

AST* code_parse_function_call(Parser* parser) {
    AST* function_call = init_code_ast(AST_FUNCTION_CALL);
    function_call->children = init_children(sizeof(AST*));
    function_call->name = parser->previous_token->value;

    if(parser->previous_token->type == TOKEN_IDENTIFIER) {
        parser_expect_token(parser, TOKEN_COLON);
        ast_add_child(function_call, code_parse_args(parser));
    } 

    return function_call;
}

AST* code_parse_args(Parser* parser){
    AST* function_call_args = init_code_ast(AST_ARGS);
    function_call_args->children = init_children(sizeof(AST*));
    
    ast_add_child(function_call_args, code_parse_arg(parser));
    while(token_peek(parser) == TOKEN_COMMA) {
        parser_expect_token(parser, TOKEN_COMMA);
        ast_add_child(function_call_args, code_parse_arg(parser));
    }

    return function_call_args;
}

AST* code_parse_arg(Parser* parser){
    return code_parse_expression(parser);
}

AST* code_parse_string_val_expression(Parser* parser){
    AST* expression = code_parse_constants(parser);
    while(token_peek(parser) == TOKEN_AMPERSAND) {
        AST* binop = init_code_ast(AST_CONCAT_EXPRESSION);
        /**/ binop->left = expression;
        /**/ binop->operator = TOKEN_AMPERSAND;
        parser_expect_token(parser, TOKEN_AMPERSAND);
        binop->right = code_parse_constants(parser);

        expression = binop;
    }

    return expression;
}

AST* code_parse_constants(Parser* parser){
    AST* constant = init_code_ast(AST_STRING);
    switch(token_peek(parser)) {
        case TOKEN_LBRACKET:
            parser_expect_token(parser, TOKEN_LBRACKET);
            switch(token_peek(parser)) {
                case TOKEN_LBRACKET:
                    constant->string_value = parser->current_token->value;
                    parser_expect_token(parser, TOKEN_LBRACKET);
                    break;
                case TOKEN_RBRACKET:
                    constant->string_value = parser->current_token->value;
                    parser_expect_token(parser, TOKEN_RBRACKET);
                    break;
                case TOKEN_POUND:
                    constant->string_value = parser->current_token->value;
                    parser_expect_token(parser, TOKEN_POUND);
                    break;
                case TOKEN_AMPERSAND:
                    constant->string_value = parser->current_token->value;
                    parser_expect_token(parser, TOKEN_AMPERSAND);
                    break;
            }
            parser_expect_token(parser, TOKEN_RBRACKET);
            break; 
        case TOKEN_DOLLAR:
            constant->string_value = parser->current_token->value;
            parser_expect_token(parser, TOKEN_DOLLAR);
            break;
        case TOKEN_STRING:
            constant->string_value = parser->current_token->value;
            parser_expect_token(parser, TOKEN_STRING);
            break;
        case TOKEN_NUMBER:
            constant->type = AST_NUMBER;
            if(strchr(parser->current_token->value, '.')) {
                constant->type = AST_FLOAT;
                constant->float_value = atof(parser->current_token->value);
            } else {
                constant->type = AST_INT;
                constant->int_value = atoi(parser->current_token->value);
            }
            parser_expect_token(parser, TOKEN_NUMBER);
            break;
        case TOKEN_BOOLEAN:
            constant->type = AST_BOOLEAN;
            constant->boolean_value = parser->current_token->value;
            parser_expect_token(parser, TOKEN_BOOLEAN);
            break;
        case TOKEN_IDENTIFIER:
            constant->type = AST_VARIABLE;
            constant->name = parser->current_token->value;
            parser_expect_token(parser, TOKEN_IDENTIFIER);
            break;
        case TOKEN_LPAREN:
            return code_parse_paren(parser);
        default:
            printf(
                "Syntax Error: Unexpected token %s at line %d, col %d\n", 
                parser->previous_token->value,
                parser->lexer->line, 
                parser->lexer->col
            );
            exit(1);
    }

    return constant;
}

AST* code_parse_function_declaration(Parser* parser){
    // TODO: Implement function declaration
}

AST* code_parse_function_params(Parser* parser){
    // TODO: Implement function params
}

AST* code_parse_function_params_prime(Parser* parser){
    // TODO: Implement function params prime
}

AST* code_parse_function_definition(Parser* parser){
    // TODO: Implement function definition
}

AST* code_parse_function_return_statement(Parser* parser){
    // TODO: Implement funciton return statement
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
    AST* left = code_parse_boolean_factor(parser);
    return code_parse_boolean_expression_prime(parser, left);
}

AST* code_parse_boolean_expression_prime(Parser* parser, AST* left){
    AST* expression = left;
    while(token_peek(parser) == TOKEN_LESSTHAN || 
        token_peek(parser) == TOKEN_GREATERTHAN ||
        token_peek(parser) == TOKEN_GREATEREQUAL ||
        token_peek(parser) == TOKEN_LESSEQUAL ||
        token_peek(parser) == TOKEN_EQEQUAL ||
        token_peek(parser) == TOKEN_NOTEQUAL ||
        token_peek(parser) == TOKEN_AND ||
        token_peek(parser) == TOKEN_OR ||
        token_peek(parser) == TOKEN_NOT) {
        AST* binop = init_code_ast(AST_BOOLEAN_EXPRESSION);
        switch(token_peek(parser)) {
            case TOKEN_LESSTHAN:
                binop->left = expression;
                binop->operator = TOKEN_LESSTHAN;
                parser_expect_token(parser, TOKEN_LESSTHAN);
                binop->right = code_parse_boolean_factor(parser);
                break;
            case TOKEN_GREATERTHAN:
                binop->left = expression;
                binop->operator = TOKEN_GREATERTHAN;
                parser_expect_token(parser, TOKEN_GREATERTHAN);
                binop->right = code_parse_boolean_factor(parser);
                break;
            case TOKEN_GREATEREQUAL:
                binop->left = expression;
                binop->operator = TOKEN_GREATEREQUAL;
                parser_expect_token(parser, TOKEN_GREATEREQUAL);
                binop->right = code_parse_boolean_factor(parser);
                break;
            case TOKEN_LESSEQUAL:
                binop->left = expression;
                binop->operator = TOKEN_LESSEQUAL;
                parser_expect_token(parser, TOKEN_LESSEQUAL);
                binop->right = code_parse_boolean_factor(parser);
                break;
            case TOKEN_EQEQUAL:
                binop->left = expression;
                binop->operator = TOKEN_EQEQUAL;
                parser_expect_token(parser, TOKEN_EQEQUAL);
                binop->right = code_parse_boolean_factor(parser);
                break;
            case TOKEN_NOTEQUAL:
                binop->left = expression;
                binop->operator = TOKEN_NOTEQUAL;
                parser_expect_token(parser, TOKEN_NOTEQUAL);
                binop->right = code_parse_boolean_factor(parser);
                break;
            case TOKEN_AND:
                binop->left = expression;
                binop->operator = TOKEN_AND;
                parser_expect_token(parser, TOKEN_AND);
                binop->right = code_parse_boolean_factor(parser);
                break;
            case TOKEN_OR:
                binop->left = expression;
                binop->operator = TOKEN_OR;
                parser_expect_token(parser, TOKEN_OR);
                binop->right = code_parse_boolean_factor(parser);
                break;
            case TOKEN_NOT:
                binop->left = expression;
                binop->operator = TOKEN_OR;
                parser_expect_token(parser, TOKEN_NOT);
                binop->right = code_parse_boolean_factor(parser);
                break;
        }
    }

    return expression;
}

AST* code_parse_boolean_factor(Parser* parser){
    AST* constant = NULL;
    switch(token_peek(parser)){
        case TOKEN_BOOLEAN:
            constant = init_code_ast(AST_BOOLEAN);
            constant->boolean_value =  parser->current_token->value;
            parser_expect_token(parser, TOKEN_BOOLEAN);
            break;
        case TOKEN_IDENTIFIER:
            constant = init_code_ast(AST_VARIABLE);
            constant->name =  parser->current_token->value;
            parser_expect_token(parser, TOKEN_IDENTIFIER);
            break;
        case TOKEN_STRING:
            constant = init_code_ast(AST_STRING);
            constant->string_value =  parser->current_token->value;
            parser_expect_token(parser, TOKEN_STRING);
            break;
        case TOKEN_NUMBER:
            constant = init_code_ast(AST_NUMBER);
            if(strchr(parser->current_token->value, '.')) {
                constant->type = AST_FLOAT;
                constant->float_value = atof(parser->current_token->value);
            } else {
                constant->type = AST_INT;
                constant->int_value = atoi(parser->current_token->value);
            }
            parser_expect_token(parser, TOKEN_NUMBER);
            break;
        case TOKEN_LPAREN:
            return code_parse_paren(parser);
        default:
            printf(
                "Syntax Error: Unexpected token %s at line %d, col %d\n", 
                parser->previous_token->value,
                parser->lexer->line, 
                parser->lexer->col
            );
            exit(1);
    }

    return constant;
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
    code_parse_executable_statements(parser);
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
    code_parse_executable_statements(parser);
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
    parser_expect_token(parser, TOKEN_IF);
    parser_expect_token(parser, TOKEN_LPAREN);
    code_parse_expression(parser);
    parser_expect_token(parser, TOKEN_RPAREN);
    parser_expect_token(parser, TOKEN_NEWLINE);
    parser_expect_token(parser, TOKEN_BEGIN);
    parser_expect_token(parser, TOKEN_IF);
    parser_expect_token(parser, TOKEN_NEWLINE);
    code_parse_executable_statements(parser);
    parser_expect_token(parser, TOKEN_END);
    parser_expect_token(parser, TOKEN_IF);
}

AST* code_parse_if_else_statements(Parser* parser){
    code_parse_if_statement(parser);
    while(ts_peek(tokens)->type == TOKEN_ELSE) {
        parser_expect_token(parser, TOKEN_NEWLINE);
        parser_expect_token(parser, TOKEN_ELSE);
        if(token_peek(parser) == TOKEN_IF) {
            code_parse_if_statement(parser);
        } else {
            code_parse_else_statement(parser);
            break;
        }
    }
}

AST* code_parse_else_statement(Parser* parser){
    if(parser->previous_token->type == TOKEN_ELSE) {
        parser_expect_token(parser, TOKEN_NEWLINE);
        parser_expect_token(parser, TOKEN_BEGIN);
        parser_expect_token(parser, TOKEN_IF);
        parser_expect_token(parser, TOKEN_NEWLINE);
        code_parse_executable_statements(parser);
        parser_expect_token(parser, TOKEN_END);
        parser_expect_token(parser, TOKEN_IF);
    }
}

AST* code_parse_while_loop(Parser* parser){
    parser_expect_token(parser, TOKEN_WHILE);
    parser_expect_token(parser, TOKEN_LPAREN);
    code_parse_expression(parser);
    parser_expect_token(parser, TOKEN_RPAREN);
    parser_expect_token(parser, TOKEN_NEWLINE);
    parser_expect_token(parser, TOKEN_BEGIN);
    parser_expect_token(parser, TOKEN_WHILE);
    parser_expect_token(parser, TOKEN_NEWLINE);
    code_parse_executable_statements(parser);
    parser_expect_token(parser, TOKEN_END);
    parser_expect_token(parser, TOKEN_WHILE);
}

AST* code_parse_break_statement(Parser* parser){
    parser_expect_token(parser, TOKEN_BREAK);
}

AST* code_parse_continue_statement(Parser* parser){
    parser_expect_token(parser, TOKEN_CONTINUE);
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
//     compound->compound_statements = (AST**) malloc(sizeof(AST*));

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
//     func_call->func_call_name = parser->previous_token->value; DISPLAY
//     parser_expect_token(parser, TOKEN_COLON); :
//     func_call->func_call_args = (AST**) malloc(sizeof(AST*));

//     AST* expr = code_parse_expression(parser); "sy"
//     func_call->func_call_args[0] = expr; "sy"
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
