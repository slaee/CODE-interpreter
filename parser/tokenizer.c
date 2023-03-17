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
        interp->current_token.type = EOF;
        interp->current_token.lexeme = NULL;
    }
}

void skip_whitespace(Interpreter* interp) {
    while (interp->pos < interp->input_size) {
        char c = interp->input[interp->pos];
        if (isspace(c)) {
            if (c == '\n') {
                interp->current_token.type = NEWLINE;
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

    if(CodeOneChar(identifier) != INVALID){
        interp->current_token.type = CodeOneChar(identifier);
        return;
    }

    // Check if the identifier is a keyword
    if (strcmp(identifier, "BEGIN") == 0) {
        interp->current_token.type = BEGIN;
    } else if (strcmp(identifier, "END") == 0) {
        interp->current_token.type = END;
    } else if (strcmp(identifier, "INT") == 0) {
        interp->current_token.type = INT;
    } else if (strcmp(identifier, "CHAR") == 0) {
        interp->current_token.type = CHAR;
    } else if (strcmp(identifier, "BOOL") == 0) {
        interp->current_token.type = BOOL;
    } else if (strcmp(identifier, "FLOAT") == 0) {
        interp->current_token.type = FLOAT;
    } else if (strcmp(identifier, "TRUE") == 0) {
        interp->current_token.type = TRUE;
    } else if (strcmp(identifier, "FALSE") == 0) {
        interp->current_token.type = FALSE;
    } else if (strcmp(identifier, "DISPLAY") == 0) {
        interp->current_token.type = DISPLAY;
    } else {
        interp->current_token.type = IDENTIFIER;
    }

    interp->current_token.lexeme = identifier;
}

void read_number(Interpreter* interp) {
    int start = interp->pos;
    while (interp->pos < interp->input_size && isdigit(interp->input[interp->pos])) {
        advance(interp);
    }

    int len = interp->pos - start;
    char* number = malloc(len + 1);

    strncpy(number, interp->input + start, len);
    number[len] = '\0';

    interp->current_token.type = INTEGER;
    interp->current_token.lexeme = number;
}

void next_token(Interpreter* interp) {
    skip_whitespace(interp);
    if (interp->pos >= interp->input_size) {
        interp->current_token.type = EOF;
        interp->current_token.lexeme = NULL;
        return;
    }

    char c = interp->input[interp->pos];
    switch (c) {
        case '+':
            interp->current_token.type = PLUS;
            interp->current_token.lexeme = NULL;
            advance(interp);
            break;
        case '-':
            interp->current_token.type = MINUS;
            interp->current_token.lexeme = NULL;
            advance(interp);
            break;
        case '*':
            interp->current_token.type = ASTERISK;
            interp->current_token.lexeme = NULL;
            advance(interp);
        break;
        case '/':
            interp->current_token.type = SLASH;
            interp->current_token.lexeme = NULL;
            advance(interp);
        break;
        case '%':
            interp->current_token.type = PERCENT;
            interp->current_token.lexeme = NULL;
            advance(interp);
            break;
        case '=':
            if (interp->pos < interp->input_size && interp->input[interp->pos] == '=') {
                interp->current_token.type = EQUAL;
                interp->current_token.lexeme = "Assign";
                interp->pos += 2;
            } else {
                error("Invalid token");
            }
            break;
    }
}