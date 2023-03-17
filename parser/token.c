#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/internal/codecore_token.h"

int CodeOneChar(int c) {
    switch (c) {
        case '+': return PLUS;
        case '-': return MINUS;
        case '*': return ASTERISK;
        case '/': return SLASH;
        case '%': return PERCENT;
        case '(': return LEFT_PAREN;
        case ')': return RIGHT_PAREN;
        case '[': return LEFT_BRACKET;
        case ']': return RIGHT_BRACKET;
        case '<': return LESS;
        case '>': return GREATER;
        case '=': return EQUAL;
        case '$': return DOLLAR;
        case '&': return AMPERSAND;
        case ',': return COMMA;
        case ':': return COLON;
        default: return INVALID;
    }
}

int CodeTwoChars(int c1, int c2) {
    switch (c1) {
        case '>':
            if (c2 == '=') return GREATER_EQUAL;
            break;
        case '<':
            if (c2 == '=') return LESS_EQUAL;
            if (c2 == '>') return NOT_EQUAL;
            break; 
        case '=':
            if (c2 == '=') return EQUAL_EQUAL;
            break;
    }
}