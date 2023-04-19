#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symtab.h"

#define SYMBOL_TABLE_SIZE 11

int hash_fn(char *name) {
    int hash = 0;
    while(*name) hash = (hash * 0.75) + *name++;
    return hash % SYMBOL_TABLE_SIZE;
}

SYMBOL_TABLE* create_symbol_table() {
    SYMBOL_TABLE *table = (SYMBOL_TABLE *) malloc(sizeof(SYMBOL_TABLE));
    table->symbols = (SYMBOL **) malloc(sizeof(SYMBOL *) * SYMBOL_TABLE_SIZE);
    table->size = 0;
    table->capacity = SYMBOL_TABLE_SIZE;
    table->parent = NULL;
    return table;
}

SYMBOL_TABLE* scope_symbol_table(SYMBOL_TABLE *table) {
    SYMBOL_TABLE *new_table = create_symbol_table();
    new_table->parent = table;
    return new_table;
}

SYMBOL* lookup_symbol(SYMBOL_TABLE *table, char *name) {
    int i = hash_fn(name);

    SYMBOL *symbol = table->symbols[i];

    int j;
    for(j = 0; j < table->size; ++j) {
        if(symbol == NULL) 
            continue;
        if(strcmp(symbol->name, name) == 0) 
            return symbol;
    }

    return NULL;
}

SYMBOL* insert_symbol(SYMBOL_TABLE *table, char *name, enum SymbolType type) {
    int i = hash_fn(name);
    // check redifinition
    if(lookup_symbol(table, name)) {
        printf("Error: redefinition of symbol %s \n", name);
        exit(1);
    }

    SYMBOL *symbol = (SYMBOL *) malloc(sizeof(SYMBOL));
    symbol->name = name;
    symbol->type = type;

    if(table->size == table->capacity) {
        table->symbols = (SYMBOL **) realloc(table->symbols, sizeof(SYMBOL *) * table->capacity * 2);
        table->capacity *= 2;
    }

    table->symbols[i] = symbol;
    table->size++;
    return symbol;
}

void print_symbol_table(SYMBOL_TABLE *table) {
    int i;
    for(i = 0; i < SYMBOL_TABLE_SIZE; ++i) {
        if(table->symbols[i] == NULL) continue;
        SYMBOL *symbol = table->symbols[i];
        printf("Symbol: %s,\t type: %d,\n", symbol->name, symbol->type);
    }
}

void free_symbol_table(SYMBOL_TABLE *table) {
    int i;
    for(i = 0; i < table->size; i++) {
        free(table->symbols[i]);
    }
    free(table->symbols);
    free(table);
}