#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "io.h"
#include "parser/lexer.h"
#include "parser/parser.h"
#include "code/visitor.h"


int main() {
    extern char* buffer;
    READ_FILE("test/main.code");

    // create lexer
    Lexer* lex = init_code_lexer(buffer, strlen(buffer));
    Parser* parser = init_code_parser(lex);
    AST* root = parse_code(parser);
    // Visitor* visitor = init_code_visitor();
    // visitor_visit(visitor, root);

    // Token* token;
    // while((token = lex_next_token(lex)) && (token->type != TOKEN_EOF)) {
    //    print_token(token);
    // }
    

    return 0;
}