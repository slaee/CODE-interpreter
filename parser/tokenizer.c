#include "tokenizer.h"

void error(char* message) {
    printf("Error: %s\n", message);
    exit(1);
}

int is_identifier_char(char c) {
    return isalnum(c) || c == '_';
}

void advance(Interpreter* interp) {
    interp->pos++;
    if (interp->pos >= interp->input_size) {
        interp->current_token.type = TOKEN_EOF;
        interp->current_token.lexeme = NULL;
    }
}

void skip_whitespace(Interpreter* interp) {
    while (interp->pos < interp->input_size) {
        char c = interp->input[interp->pos];
        if (isspace(c)) {
            if (c == '\n') {
                interp->current_token.type = TOKEN_NEWLINE;
                interp->current_token.lexeme = NULL;
                interp->line++;
            }
            advance(interp);
        } else if (c == '#') {
            while (interp->pos < interp->input_size && interp->input[interp->pos] != '\n') {
                advance(interp);
            }
        } else {
            break;
        }
    }
}

void read_identifier(Interpreter* interp) {
    int start = interp->pos;
    while (interp->pos < interp->input_size && is_identifier_char(interp->input[interp->pos])) {
        advance(interp);
    }

    int len = interp->pos - start;
    char* identifier = malloc(len + 1);

    strncpy(identifier, interp->input + start, len);
    identifier[len] = '\0';

    // Check if the identifier is a keyword
    if (strcmp(identifier, "BEGIN") == 0) {
        interp->current_token.type = TOKEN_BEGIN;
    } else if (strcmp(identifier, "END") == 0) {
        interp->current_token.type = TOKEN_END;
    } else if (strcmp(identifier, "INT") == 0) {
        interp->current_token.type = TOKEN_INT;
    } else if (strcmp(identifier, "CHAR") == 0) {
        interp->current_token.type = TOKEN_CHAR;
    } else if (strcmp(identifier, "BOOL") == 0) {
        interp->current_token.type = TOKEN_BOOL;
    } else if (strcmp(identifier, "FLOAT") == 0) {
        interp->current_token.type = TOKEN_FLOAT;
    } else if (strcmp(identifier, "TRUE") == 0) {
        interp->current_token.type = TOKEN_TRUE;
    } else if (strcmp(identifier, "FALSE") == 0) {
        interp->current_token.type = TOKEN_FALSE;
    } else if (strcmp(identifier, "DISPLAY") == 0) {
        interp->current_token.type = TOKEN_DISPLAY;
    } else {
        interp->current_token.type = TOKEN_IDENTIFIER;
    }

    interp->current_token.lexeme = identifier;
}


