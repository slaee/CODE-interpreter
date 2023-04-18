#include "ast.h"

AST* init_code_ast(enum AST_Type type) {
    AST* ast = (AST*) malloc(sizeof(AST)); 
    ast->type = type;
    return ast;
}

AST** init_children(size_t size) {
    AST** children = (AST**) malloc(size);
    return children;
}

void ast_add_child(AST* parent, AST* child) {
    if (parent->children == NULL) {
        parent->children = (AST**) malloc(sizeof(AST*));
        parent->children_size = 0;
    }
    // reallocate 
    parent->children = (AST**) realloc(parent->children, sizeof(AST*) * (parent->children_size + 1));
    parent->children[parent->children_size] = child;
    parent->children_size++;
}