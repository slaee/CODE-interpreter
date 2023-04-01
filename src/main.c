#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser/lexer.h"

// this will be used to read the file and store it in a buffer
void read_file(char* path, char* buffer) {
    // read file
    FILE *fp = fopen("test/test1.code", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // // Get the size of the file
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    // Allocate a buffer for the file contents
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    // Read the file contents into the buffer
    fread(buffer, file_size, 1, fp);
    buffer[file_size] = EOF; 
    fclose(fp);
}


int main() {
    char* buffer = malloc(1024);
    read_file("test/test1.code", buffer);

    // START YOUR DEBUGGIN HERE

    // create lexer
    lexer* lex = Lexer(buffer, strlen(buffer));
    // tokenize
    TokenStream* stream = tokenize(lex);
    Token* token;
    
    /// MULTIPLE RETREIVAL
    peek_ts(stream);
    token = advance_ts(stream);
    print_token(token);

    // printf("%d", peek_ts(stream));
    // token = advance_ts(stream);
    // print_token(token);

    /// MULTIPLE RETREIVAL USING LOOP
    // while (peek_ts(stream) != TOKEN_EOF) {
    //     Token* token = advance_ts(stream);
    //     print_token(token);
    // }
    free(lex);
    return 0;
}