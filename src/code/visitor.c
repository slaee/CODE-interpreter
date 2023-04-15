#include <stdio.h>
#include <string.h>
#include "visitor.h"

static AST* builtin_function_display(Visitor* visitor, AST** args, size_t arg_size) {
    int i;
    for(i = 0; i < arg_size; i++) {
        AST* visit = visitor_visit(visitor, args[i]);

        switch(visit->type) {
            case AST_BOOLEAN_EXPRESSION: printf("%p: %s\n", visit, visit->boolean_value); break;
            default: printf("%p\n", visit); break;
        }
    }

    return init_code_ast(AST_NOOP);
}

Visitor* init_code_visitor() {
    Visitor* visitor = (Visitor*) malloc(sizeof(Visitor));
    visitor->variable_defs = (void*) 0;
    visitor->variable_defs_size = 0;

    return visitor;
}

AST* visitor_visit(Visitor* visitor, AST* node) {
    switch(node->type) {
        case AST_VARIABLE_DECLARATIONS: return visitor_visit_variable_declaration(visitor, node);
        case AST_VARIABLE: return visitor_visit_variable(visitor, node);
        case AST_FUNCTION_CALL: return visitor_visit_func_call(visitor, node);
        case AST_STRING_VAL_EXPRESSION: return visitor_visit_string(visitor, node);
        case AST_BOOLEAN_EXPRESSION: return visitor_visit_boolean(visitor, node);
        case AST_COMPOUND: return visitor_visit_compound(visitor, node);
        case AST_NOOP: return node;
    }
    
    printf("Uncaught statement of type '%d\n", node->type);
    exit(1);
}

AST* visitor_visit_variable_declaration(Visitor* visitor, AST* node) {
    if(visitor->variable_defs == (void*) 0) {
        visitor->variable_defs = (AST**) malloc(sizeof(AST*));
        visitor->variable_defs[0] = node;
        visitor->variable_defs_size += 1;
    } else {
        visitor->variable_defs = (AST**) realloc(
            visitor->variable_defs, 
            sizeof(AST*) * (visitor->variable_defs_size + 1)
        );
        visitor->variable_defs[visitor->variable_defs_size] = node;
        visitor->variable_defs_size += 1;
    }

    return node;
}

AST* visitor_visit_variable(Visitor* visitor, AST* node) {
    int i;
    for(i = 0; i < visitor->variable_defs_size; ++i) {
        AST* variable_def = visitor->variable_defs[i];
        if(strcmp(variable_def->variable_declaration_type, node->variable_name) == 0) {
            return visitor_visit(visitor, variable_def->variable_declaration_names[0]);
        }
    }

    printf("Undefined variable '%s'\n", node->variable_name);
    return node;
}

AST* visitor_visit_func_call(Visitor* visitor, AST* node) {
    if(strcmp(node->func_call_name, "DISPLAY") == 0) {
        return builtin_function_display(visitor, node->func_call_args, node->func_call_args_size);
    }

    printf("Undefined function '%s'\n", node->func_call_name);
    exit(1);
}

AST* visitor_visit_string(Visitor* visitor, AST* node) {

}

AST* visitor_visit_boolean(Visitor* visitor, AST* node) {
    return node;
}

AST* visitor_visit_compound(Visitor* visitor, AST* node) {
    int i;
    for(i = 0; i < node->compound_size; i++) {
        visitor_visit(visitor, node->compound_statements[i]);
    }

    return init_code_ast(AST_NOOP);
}