#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "visitor.h"
#include "../parser/types.h"
#include "../parser/ast.h"
#include "../parser/symtab.h"

SYMBOL_TABLE* symtab;

Visitor* init_visitor() {
    symtab = create_symbol_table();
    Visitor* visitor = (Visitor*) malloc(sizeof(Visitor));
    return visitor;
}
    
void visit(AST* ast, Visitor* visitor) {
    switch(ast->type) {
        case AST_COMPOUND: 
            visit_compound(ast, visitor);
            break;
        case AST_DEFINITIONS:
            int i;
            for(i = 0; i < ast->children_size; ++i) {
                switch(ast->children[i]->type) {
                    case AST_VARIABLE_DECLS:
                        visit_variable(ast->children[i], visitor);
                        break;
                    case AST_FUNCTION_DECLS:
                        break;
                }
            }
            break;
        case AST_ASSIGNMENT:
            visit_assignment(ast, visitor);
            break;
    }
}

void visit_compound(AST* ast, Visitor* visitor) {
    unsigned int i;
    for(i = 0; i < ast->children_size; ++i) {
        visit(ast->children[i], visitor);
    }
}

void visit_int(AST* obj, Visitor* visitor){
    
}

void visit_string(AST* obj, Visitor* visitor) {

}

void visit_char(AST* obj, Visitor* visitor) {

}

void visit_boolean(AST* obj, Visitor* visitor) {

}

void visit_float(AST* obj, Visitor* visitor) {

}

void visit_variable(AST* obj, Visitor* visitor) {
    unsigned int i;
    for(i = 0; i < obj->children_size; ++i) {
        if(obj->children[i]->type = AST_VARIABLE) {
            insert_symbol(symtab, obj->children[i]->name, LOCAL);
        }
    }
}

// int type_check(AST* obj) {
    
//     switch(type) {
//         case DATA_TYPE_INT:
//             visit_int(obj->children[i], visitor);
//             break;
//         case DATA_TYPE_STRING:
//             visit_string(obj->children[i], visitor);
//             break;
//         case DATA_TYPE_CHAR:
//             visit_char(obj->children[i], visitor);
//             break;
//         case DATA_TYPE_BOOL:
//             visit_boolean(obj->children[i], visitor);
//             break;
//         case DATA_TYPE_FLOAT:
//             visit_float(obj->children[i], visitor);
//             break;
//     }
// }

void visit_assignment(AST* obj, Visitor* visitor) {
     if (obj->type == AST_ASSIGNMENT) {
        char* var_name = obj->name;
        
        // Look up the variable in the symbol table
        SYMBOL* entry = lookup_symbol(symtab, var_name);
        
        if (entry == NULL) {
            // Variable is not defined in symbol table, report an error
            printf("Error: variable '%s' is not defined\n", var_name);
            exit(1);
        } else if (entry->type == FORMAL) {
            // Trying to assign a value to a formal parameter, report an error
            printf("Error: cannot assign value to formal parameter '%s'\n", var_name);
            exit(1);
        }
         else {
            // Variable is defined in symbol table, update its value
            // entry->name = evaluate_expression(obj->right, symtab); // assuming evaluate_expression evaluates the expression on the right-hand side
        }
    } else {
        // Left-hand side is not a variable, report an error
        printf("Error: invalid assignment target\n");
        exit(1);
    }
}

void visit_concat_expression(AST* obj, Visitor* visitor) {

}

void visit_arithmetic_expression(AST* obj, Visitor* visitor) {

}

void visit_boolean_expression(AST* obj, Visitor* visitor) {

}

void visit_unary_expression(AST* obj, Visitor* visitor) {

}

void visit_paren_expression(AST* obj, Visitor* visitor) {

}

void visit_function_call(AST* obj, Visitor* visitor) {

}