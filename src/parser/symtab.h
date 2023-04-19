#ifndef _SYMTAB_H_
#define _SYMTAB_H_

#include "ast.h"

enum SymbolType {
    LOCAL,
    GLOBAL,
    PARAM,
    FUNCTION,
    FORMAL
};

typedef struct SYMBOL {
    char *name;
    enum SymbolType type;
    struct SYMBOL *next;
} SYMBOL;

// use a hash table to store symbols
#define HASH_TABLE_SIZE 1024
typedef struct SYMBOL_TABLE {
    struct SYMBOL** symbols;
    int size;
    int capacity;
    struct SYMBOL_TABLE *parent;
} SYMBOL_TABLE;

SYMBOL_TABLE* create_symbol_table();

SYMBOL_TABLE* scope_symbol_table(SYMBOL_TABLE *table);

SYMBOL *lookup_symbol(SYMBOL_TABLE *table, char *name);

SYMBOL* insert_symbol(SYMBOL_TABLE *table, char *name, enum SymbolType type);

void print_symbol_table(SYMBOL_TABLE *table);

void free_symbol_table(SYMBOL_TABLE *table);

#endif