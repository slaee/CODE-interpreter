#include <stdio.h>
#include <string.h>
#include "../parser/tokenizer.h"

int main() {

    /**
     * Basic testing phase
     */
    Interpreter interp;

    interp.input = "INT a = 5";
    interp.input_size = strlen(interp.input);
    interp.pos = 0;
    interp.line = 1;

    // removed white spaces so the interpreter input will be converted as 
    // INTa=5;
    // but this is not the case, we need to split into words as well to become a token
    //skip_whitespace(&interp);
    read_identifier(&interp);
    // 35 = IDENTIFIER
    printf("TOKENIZED: %d \'%s\' %d %d %d\n" , interp.current_token.type, interp.current_token.lexeme, interp.pos, interp.line, interp.input_size);

    interp.pos = 4;
    interp.line = 1;
    read_identifier(&interp);
    // 35 = IDENTIFIER
    printf("TOKENIZED: %d \'%s\' %d %d %d\n" , interp.current_token.type, interp.current_token.lexeme, interp.pos, interp.line, interp.input_size);

    interp.pos = 6;
    interp.line = 1;
    next_token(&interp);
    // 13 = EQUAL (Assign operation)
    printf("TOKENIZED: %d \'%s\' %d %d %d\n" , interp.current_token.type, interp.current_token.lexeme, interp.pos, interp.line, interp.input_size);

    interp.pos = 8;
    interp.line = 1;
    read_number(&interp);
    // 35 = IDENTIFIER
    printf("TOKENIZED: %d \'%s\' %d %d %d\n" , interp.current_token.type, interp.current_token.lexeme, interp.pos, interp.line, interp.input_size);

    return 0;
}
