#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

#define ERROR -1

#define BLANK 32
#define TAB 9
#define NEWLINE 10
#define VTAB 11
#define FORMFEED 12
#define CARRIAGE_RETURN 13


#define START_STATE 0

static int comment_T[3][3] = {
    {1, ERROR, ERROR},
    {1,     2,     1},
    {2,     2,     2},
};

static int identifier_T[4][3] = {
    {1, ERROR, ERROR},
    {2,     2, ERROR},
    {2,     2,     2},
    {3,     3,     3},
};

int number_T[5][2] = {
    {1,     ERROR},
    {1,         2},
    {3,     ERROR},
    {3,     ERROR},
    {ERROR, ERROR},
};


const char* tokentype_str_value[] = {
    [TOKEN_BEGIN]       = "BEGIN",
    [TOKEN_CODE]        = "CODE",
    [TOKEN_END]         = "END",
    [TOKEN_TYPE]        = "TYPE",
    [TOKEN_IF]          = "IF",
    [TOKEN_ELSE]        = "ELSE",
    [TOKEN_WHILE]       = "WHILE",
    [TOKEN_DO]          = "DO",
    [TOKEN_FOR]         = "FOR",
    [TOKEN_SWITCH]      = "SWITCH",
    [TOKEN_CASE]        = "CASE",
    [TOKEN_DEFAULT]     = "DEFAULT",
    [TOKEN_BREAK]       = "BREAK",
    [TOKEN_CONTINUE]    = "CONTINUE",
    [TOKEN_OR]          = "OR",
    [TOKEN_AND]         = "AND",
    [TOKEN_NOT]         = "NOT",
    [TOKEN_BOOLEAN]     = "BOOLEAN",
    [TOKEN_NUMBER]      = "NUMBER",
    [TOKEN_FNUMBER]     = "FNUMBER",
    [TOKEN_IDENTIFIER]  = "IDENTIFIER",
    [TOKEN_CHARACTER]   = "CHARACTER",
    [TOKEN_STRING]      = "STRING",
    [TOKEN_FUNC]        = "FUNC",
    [TOKEN_AND]         = "AND",
    [TOKEN_OR]          = "OR",
    [TOKEN_NOT]         = "NOT",
    [TOKEN_EOF]         = "EOF",
    [TOKEN_NEWLINE]     = "NEWLINE",
    [TOKEN_PLUS]        = "+",
    [TOKEN_MINUS]       = "-",
    [TOKEN_STAR]        = "*",
    [TOKEN_SLASH]       = "/",
    [TOKEN_PERCENT]     = "%",
    [TOKEN_DOLLAR]      = "$",
    [TOKEN_POUND]       = "#",
    [TOKEN_AMPERSAND]   = "&",
    [TOKEN_COLON]       = ":",
    [TOKEN_COMMA]       = ",",
    [TOKEN_LPAREN]      = "(",
    [TOKEN_RPAREN]      = ")",
    [TOKEN_LBRACKET]    = "[",
    [TOKEN_RBRACKET]    = "]",
    [TOKEN_EQUAL]       = "=",
    [TOKEN_PLUSPLUS]    = "++",
    [TOKEN_MINUSMINUS]  = "--",
    [TOKEN_EQEQUAL]     = "==",
    [TOKEN_NOTEQUAL]    = "<>",
    [TOKEN_GREATEREQUAL]= ">=",
    [TOKEN_LESSEQUAL]   = "<=",
    [TOKEN_GREATERTHAN] = ">",
    [TOKEN_LESSTHAN]    = "<",
};

// lex initializer
Lexer* init_code_lexer(char* source, int len) {
    Lexer* lex = (Lexer*) malloc(sizeof(Lexer));
    lex->source = source;
    lex->len = len;
    lex->pos = 0;
    lex->line = 1;
    lex->col = 1;
    lex->current_char = lex->source[lex->pos];
    return lex;
}

// create_token helper function
Token* create_token(int type, char* lexeme) {
    Token* token = (Token*) malloc(sizeof(Token));
    token->type = type;
    token->value = lexeme;

    return token;
}

int lex_lookback(Lexer* lexer) {
    return lexer->source[lexer->pos - 1];
}

int lex_peek(Lexer* lexer) {
    return lexer->current_char;
}

int lex_advance(Lexer* lexer) {
    if (lexer->current_char != EOF && lexer->pos < lexer->len) {
        lexer->pos++;
        lexer->col++;
        lexer->current_char = lexer->source[lexer->pos];
    }
    return lexer->current_char;
}

int lex_unget(Lexer* lexer) {
    lexer->pos--;
    lexer->col--;
    lexer->current_char = lexer->source[lexer->pos];
    return lexer->current_char;
}

int lex_lookahead(Lexer* lexer) {
    if (lexer->pos + 1 < lexer->len) {
        return lexer->source[lexer->pos + 1];
    }
    return EOF;
}

char* lex_get_char_as_string(Lexer* lexer) {
    char* str = (char*) malloc(sizeof(char) * 2);
    str[0] = lex_peek(lexer);
    str[1] = '\0';
    return str;
}

void lex_skip_whitespace(Lexer* lexer) {
    while(lex_peek(lexer) == BLANK 
          || lex_peek(lexer) == TAB
          || lex_peek(lexer) == VTAB
          || lex_peek(lexer) == FORMFEED
          || lex_peek(lexer) == CARRIAGE_RETURN) {
        lex_advance(lexer);
    }
}

// eliminate comments using DFA transition table form
void lex_skip_comment(Lexer* lexer) {
    int state, input;
    state = input = 0;

    int flag_skip = 0;
    if(lex_lookback(lexer) == NEWLINE)
        flag_skip = 1;

    while(1) {
        switch(lex_peek(lexer)) {
            case '#': 
                input = 0;
                break;
            case EOF:
            case NEWLINE:
            case '\0':
                input = 1;
                break;
            default:
                input = 2;
                break;
        }
        state = comment_T[state][input];
        if(state == ERROR) {
            lex_error("Unexpected character", lexer->line, lexer->col);
            exit(1);
        } 
        
        if (state == 2) {
            break;
        }
        lex_advance(lexer);
    } 
}

Token* lex_number(Lexer* lexer) {
    char* val = (char*) malloc(sizeof(char));
    val[0] = '\0';
    char* s = NULL;
    int state = START_STATE;
    int input = 0;
    while (1) {
        if (isdigit(lex_peek(lexer))) {
            input = 0;
        } else if (lex_peek(lexer) == '.') {
            input = 1;
        } else if (lex_peek(lexer) == BLANK 
                || lex_peek(lexer) == TAB 
                || lex_peek(lexer) == NEWLINE 
                || lex_peek(lexer) == EOF
                || lex_peek(lexer) == '\0') {
            input = 2;
            break;
        } else {
            break;
        }
        state = number_T[state][input];
        if (state == ERROR) {
            lex_error("Unexpected character", lexer->line, lexer->col);
            exit(1);
        }
        if (state >= 0) {
            s = lex_get_char_as_string(lexer);
            val = (char*) realloc(val, sizeof(char) * (strlen(val) + strlen(s) + 1));
            strcat(val, s);
            lex_advance(lexer);
        }
    }
    
    if (state == 1 || state == 3) {
        return create_token(TOKEN_NUMBER, val);
    } else {
        lex_error("Unexpected character", lexer->line, lexer->col);
        exit(1);
    }
}

Token* lex_identifier(Lexer* lexer) {
    char* val = (char*) malloc(sizeof(char));
    val[0] = '\0';
    char* s = NULL;

    int state = START_STATE;
    while(lex_peek(lexer) != BLANK && lex_peek(lexer) != EOF) {
        char c = lex_peek(lexer);
        int input = 0;
        if (isalpha(c) || c == '_') {
            input = 0;
        } else if (isdigit(c)) {
            input = 1;
        } else {
            break;
        }
        int next_state = identifier_T[state][input];
        if (next_state == ERROR) {
            lex_error("Unexpected character", lexer->line, lexer->col);
            exit(1);
        } else {
            s = lex_get_char_as_string(lexer);
            val = (char*) realloc(val, sizeof(char) * (strlen(val) + strlen(s) + 1));
            strcat(val, s);
            lex_advance(lexer);
            state = next_state;
        }
    }

    if(strcmp(val, "BEGIN") == 0) {
        return create_token(TOKEN_BEGIN, val);
    } 
    else if (strcmp(val, "END")  == 0) {
        return create_token(TOKEN_END, val);
    }
    else if (strcmp(val, "CODE")  == 0) {
        return create_token(TOKEN_CODE, val);
    }
    else if (strcmp(val, "INT") == 0) {
        return create_token(TOKEN_TYPE, val);
    }
    else if (strcmp(val, "CHAR") == 0) {
        return create_token(TOKEN_TYPE, val);
    }
    else if (strcmp(val, "FLOAT") == 0) {
        return create_token(TOKEN_TYPE, val);
    }
    else if (strcmp(val, "BOOL") == 0) {
        return create_token(TOKEN_TYPE, val);
    }
    else if (strcmp(val, "WHILE") == 0) {
        return create_token(TOKEN_WHILE, val);
    }
    else if (strcmp(val, "DO") == 0) {
        return create_token(TOKEN_DO, val);
    }
    else if (strcmp(val, "FOR") == 0) {
        return create_token(TOKEN_FOR, val);
    }
    else if (strcmp(val, "FUNC") == 0) {
        return create_token(TOKEN_FUNC, val);
    }
    else if (strcmp(val, "RETURN") == 0) {
        return create_token(TOKEN_RETURN, val);
    }
    else if (strcmp(val, "SWITCH") == 0) {
        return create_token(TOKEN_SWITCH, val);
    }
    else if (strcmp(val, "CASE") == 0) {
        return create_token(TOKEN_CASE, val);
    }
    else if (strcmp(val, "DEFAULT") == 0) {
        return create_token(TOKEN_DEFAULT, val);
    }
    else if (strcmp(val, "BREAK") == 0) {
        return create_token(TOKEN_BREAK, val);
    }
    else if (strcmp(val, "CONTINUE") == 0) {
        return create_token(TOKEN_CONTINUE, val);
    }
    else if (strcmp(val, "AND") == 0) {
        return create_token(TOKEN_AND, val);
    }
    else if (strcmp(val, "OR") == 0) {
        return create_token(TOKEN_OR, val);
    }
    else if (strcmp(val, "NOT") == 0) {
        return create_token(TOKEN_NOT, val);
    }
    else if (strcmp(val, "IF") == 0) {
        return create_token(TOKEN_IF, val);
    }
    else if (strcmp(val, "ELSE") == 0) {
        return create_token(TOKEN_ELSE, val);
    }

    return create_token(TOKEN_IDENTIFIER, val);
}

Token* lex_string(Lexer* lexer) {
    char* val = (char*) malloc(sizeof(char));
    val[0] = '\0';

    char* s = NULL;
    int valid_string = 0;
    if(lex_peek(lexer) == '"'){
        lex_advance(lexer);
        while(lex_peek(lexer) != '"' && lex_peek(lexer) != NEWLINE && lex_peek(lexer) != EOF) {
            s = lex_get_char_as_string(lexer);
            val = (char*) realloc(val, sizeof(char) * (strlen(val) + strlen(s) + 1));
            strcat(val, s);
           
            lex_advance(lexer);
        }
    }
    
    if(lex_peek(lexer) == '"'){
        valid_string = 1;
        lex_advance(lexer);
    }
    
    if(valid_string){
        if(strcmp(val, "TRUE") == 0 || strcmp(val, "FALSE") == 0)
            return create_token(TOKEN_BOOLEAN, val);
        return create_token(TOKEN_STRING, val);
    } else {
        lex_error("Unexpected character", lexer->line, lexer->col);
        exit(1);
    }
}

Token* lex_character(Lexer* lexer) {
    char* val = (char*) malloc(sizeof(char));
    val[0] = '\0';

    char* s = NULL;
    if(lex_peek(lexer) == '\''){
        s = lex_get_char_as_string(lexer);
        val = (char*) realloc(val, sizeof(char) * (strlen(val) + strlen(s) + 1));
        strcat(val, s);
        lex_advance(lexer);

        while(lex_peek(lexer) != '\'' && lex_peek(lexer) != NEWLINE && lex_peek(lexer) != EOF) {
            s = lex_get_char_as_string(lexer);
            val = (char*) realloc(val, sizeof(char) * (strlen(val) + strlen(s) + 1));
            strcat(val, s);
            lex_advance(lexer);
        }
    }

    if(lex_peek(lexer) == '\''){
        s = lex_get_char_as_string(lexer);
        val = (char*) realloc(val, sizeof(char) * (strlen(val) + strlen(s) + 1));
        strcat(val, s);
        lex_advance(lexer);
    }
    
    if(val[0] == '\'' && val[strlen(val) - 1] == '\'' && strlen(val) == 3)
        return create_token(TOKEN_CHARACTER, val);
    else {
        lex_error("Unexpected character", lexer->line, lexer->col);
        exit(1);
    }
}

Token* lex_newline(Lexer* lexer) {
    lex_advance(lexer);
    lex_skip_whitespace(lexer);
    while(1) {
        if(lex_peek(lexer) == NEWLINE) {
            lexer->col = 1;
            lexer->line++;
            lex_advance(lexer);
            lex_skip_whitespace(lexer);
        }
        else
            break;
        
    }
    if (lex_peek(lexer) == '#') {
        lex_skip_comment(lexer); 
        lexer->line++;
        lex_newline(lexer);
    }
    return create_token(TOKEN_NEWLINE, NULL);
}

Token* lex_next_token(Lexer* lexer) {
    while(lexer->current_char != EOF && lexer->pos < lexer->len) {
        lex_skip_whitespace(lexer);
        if(lex_peek(lexer) == NEWLINE) {
            lexer->col = 1;
            lexer->line++;
            return lex_newline(lexer);
        } 
        else if(lex_peek(lexer) == '#') {
            if(lex_lookback(lexer) == '[') {
                lex_advance(lexer);
                return create_token(TOKEN_POUND, NULL);
            }
            else 
                lex_skip_comment(lexer);
        }
        else if(lex_peek(lexer) == EOF)
            return create_token(TOKEN_EOF, NULL);
        else if (lex_peek(lexer) == '"')
            return lex_string(lexer);
        else if (lex_peek (lexer) == '\'')
            return lex_character(lexer);
        else if(isalpha(lex_peek(lexer)) || lex_peek(lexer) == '_')
            return lex_identifier(lexer);
        else if(isdigit(lex_peek(lexer)) || lex_peek(lexer) == '.')
            return lex_number(lexer);
        else {
            switch(lex_peek(lexer)) {
                case '+':
                    if(lex_advance(lexer) == '+') {
                        lex_advance(lexer);
                        return create_token(TOKEN_PLUSPLUS, NULL);
                    } else {
                        return create_token(TOKEN_PLUS, NULL);
                    }
                case '-':
                    if(lex_advance(lexer) == '-') {
                        lex_advance(lexer);
                        return create_token(TOKEN_MINUSMINUS, NULL);
                    } else {
                        return create_token(TOKEN_MINUS, NULL);
                    }
                case '*':
                    if(lex_advance(lexer) == '=') {
                        lex_advance(lexer);
                        return create_token(TOKEN_STAREQUAL, NULL);
                    } else {
                        return create_token(TOKEN_STAR, NULL);
                    }
                case '/':
                    if(lex_advance(lexer) == '=') {
                        lex_advance(lexer);
                        return create_token(TOKEN_SLASHEQUAL, NULL);
                    } else {
                        return create_token(TOKEN_SLASH, NULL);
                    }
                case '=':
                    if(lex_advance(lexer) == '=') {
                        lex_advance(lexer);
                        return create_token(TOKEN_EQEQUAL, NULL);
                    } else {
                        return create_token(TOKEN_EQUAL, NULL);
                    }
                case '>':
                    if(lex_advance(lexer) == '=') {
                        lex_advance(lexer);
                        return create_token(TOKEN_GREATEREQUAL, NULL);
                    } else {
                        return create_token(TOKEN_GREATERTHAN, NULL);
                    }
                case '<':
                    char holder = lex_advance(lexer);
                    if(holder == '=') {
                        lex_advance(lexer);
                        return create_token(TOKEN_LESSEQUAL, NULL);
                    } else if (holder == '>') {
                        lex_advance(lexer);
                        return create_token(TOKEN_NOTEQUAL, NULL);
                    } else {
                        return create_token(TOKEN_LESSTHAN, NULL);
                    }
                case '%': lex_advance(lexer); return create_token(TOKEN_PERCENT, NULL);
                case ',': lex_advance(lexer); return create_token(TOKEN_COMMA, NULL);
                case ':': lex_advance(lexer); return create_token(TOKEN_COLON, NULL);
                case '(': lex_advance(lexer); return create_token(TOKEN_LPAREN, NULL);
                case ')': lex_advance(lexer); return create_token(TOKEN_RPAREN, NULL);
                case '[': lex_advance(lexer); return create_token(TOKEN_LBRACKET, NULL);
                case ']': lex_advance(lexer); return create_token(TOKEN_RBRACKET, NULL);
                case '&': lex_advance(lexer); return create_token(TOKEN_AMPERSAND, NULL);
                case '$': lex_advance(lexer); return create_token(TOKEN_DOLLAR, NULL);
                default:
                    lex_error("Unexpected character", lexer->line, lexer->col);
                    exit(1);
            }
        }
    }
    
    return create_token(TOKEN_EOF, NULL);
}

void ts_append(TokenStream* ts, Token* token) {
    ts->tokens[ts->size++] = token;
}

TokenStream* lex_tokenize(Lexer* lexer) {
    TokenStream* ts = (TokenStream*) malloc(sizeof(TokenStream));
    ts->tokens = (Token**) malloc(sizeof(Token*) * 100);
    ts->size = 0;
    ts->pos = 0;

    Token* token = lex_next_token(lexer);
    while(token->type != TOKEN_EOF) {
        ts_append(ts, token);
        token = lex_next_token(lexer);
    }
    ts_append(ts, token);
    return ts;
}

Token* ts_peek(TokenStream* ts) {
    return ts->tokens[ts->pos];
}

Token* ts_advance(TokenStream* ts) {
    return ts->tokens[ts->pos++];
}


void lexer_free(Lexer* lexer) {
    free(lexer);
}

void lex_error(const char* msg, int line, int col) {
    printf("Lexical error: %s at line %d, col %d \n", msg, line, col);
    exit(1);
}

void print_token(Token* token) {
    printf("TOKEN('%s', %s)\n", tokentype_str_value[token->type], token->value);
}
