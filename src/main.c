#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rfile.h"
#include "parser/lexer.h"

int main() {
    extern char* buffer;
    READ_FILE("test/test.code", BUFFER_SIZE);

    // create lexer
    lexer* lex = init_code_lexer(buffer, strlen(buffer));

    Token* token;
    while((token = lex_next_token(lex)) && (token->type != TOKEN_EOF)) {
       print_token(token);
    }
 
    return 0;
}