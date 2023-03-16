#include <stdio.h>
#include <string.h>
#include "../parser/tokenizer.h"

int main() {

    /**
     * Basic testing phase
     */
    Interpreter interp;

    interp.input = "INT a = 5;";
    interp.input_size = strlen(interp.input);
    interp.pos = 3;
    interp.line = 1;

    // removed white spaces so the interpreter input will be converted as 
    // INTa=5;
    // but this is not the case, we need to split into words as well to become a token
    skip_whitespace(&interp);
    read_identifier(&interp);

    // This should print 35 a 5 1 10
    // 35 is TOKEN_IDENTIFIER
    // so 'a' is an identifier
    printf("%d %s %d %d %d" , interp.current_token.type, interp.current_token.lexeme, interp.pos, interp.line, interp.input_size);

    return 0;
}
