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

void visit_statements(AST* ast, Visitor* visitor) {
    unsigned int i;
    for(i = 0; i < ast->children_size; ++i) {
        visit(ast->children[i], visitor);
    }
}
    
void visit(AST* ast, Visitor* visitor) {
    switch(ast->type) {
        // visiting compound statements
        case AST_COMPOUND: 
            visit_compound(ast, visitor);
            break;
        
        // visiting declaration group of nodes
        case AST_DECLARATIONS:
            visit_declarations(ast, visitor);
            break;

        // visiting executable group of nodes
        case AST_EXECUTABLES:
            visit_executables(ast, visitor);
            break;

        // visiting group of variable declarations
        case AST_VARIABLE_DECLS:
            visit_variable_declarations(ast, visitor);
            break;
        
        // visiting group of function declarations
        case AST_FUNCTION_DECLS:
            visit_function_declarations(ast, visitor);
            break;


        case AST_VARIABLE:
            visit_variable(ast, visitor);
            break;

        case AST_ASSIGNMENT:
            visit_assignment(ast, visitor);
            break;


        case AST_INT:
            visit_int(ast, visitor);
            break;

        case AST_FLOAT:
            visit_float(ast, visitor);
            break;
        
        case AST_BOOLEAN:
            visit_boolean(ast, visitor);
            break;

        case AST_CHAR:
            visit_char(ast, visitor);
            break;

        case AST_STRING:
            visit_string(ast, visitor);
            break;
    }
}

void visit_declarations(AST* ast, Visitor* visitor) {
    visit_statements(ast, visitor);
}

void visit_executables(AST* ast, Visitor* visitor) {
    visit_statements(ast, visitor);
}

void visit_compound(AST* ast, Visitor* visitor) {
    visit_statements(ast, visitor);
}

void visit_variable_declarations(AST* ast, Visitor* visitor) {
    visit_statements(ast, visitor);
}

void visit_function_declarations(AST* ast, Visitor* visitor) {
    visit_statements(ast, visitor);
}


void visit_int(AST* obj, Visitor* visitor){
    
}

void visit_float(AST* obj, Visitor* visitor) {

}

void visit_boolean(AST* obj, Visitor* visitor) {

}

void visit_char(AST* obj, Visitor* visitor) {

}

void visit_string(AST* obj, Visitor* visitor) {

}



void visit_variable(AST* obj, Visitor* visitor) {
    int igarbage;
    float fgarbage;
    char cgarbage;
    char* str = "FALSE";
    
    switch(obj->data_type) {
        case DATA_TYPE_BOOL:
            if(obj->value == NULL)
                insert_symbol(symtab, obj->name, obj->data_type, &str, LOCAL); 
            else
                insert_symbol(symtab, obj->name, obj->data_type, &obj->value->boolean_value, LOCAL);
            break;
        
        case DATA_TYPE_INT:
            if(obj->value == NULL)
                insert_symbol(symtab, obj->name, obj->data_type, &igarbage, LOCAL);
            else
                insert_symbol(symtab, obj->name, obj->data_type, &obj->value->int_value, LOCAL);
            break;  

        case DATA_TYPE_CHAR:
            if(obj->value == NULL) 
                insert_symbol(symtab, obj->name, obj->data_type, &cgarbage, LOCAL);
            else 
                insert_symbol(symtab, obj->name, obj->data_type, &obj->value->character_value, LOCAL);
            break;
        
        case DATA_TYPE_FLOAT:
            if(obj->value == NULL)
                insert_symbol(symtab, obj->name, obj->data_type, &fgarbage, LOCAL);
            else 
                insert_symbol(symtab, obj->name, obj->data_type, &obj->value->float_value, LOCAL);
            break;

        case DATA_TYPE_STRING:
            insert_symbol(symtab, obj->name, obj->data_type, &obj->value->string_value, LOCAL);
            break;
    }
}

void visit_assignment(AST* obj, Visitor* visitor) {
     if (obj->type == AST_ASSIGNMENT) {
        char* var_name = obj->target_name;
        
        // Look up the variable in the symbol table
        SYMBOL* entry = lookup_symbol(symtab, var_name);
        
        if (entry == NULL) {
            // Variable is not defined in symbol table, report an error
            printf("Error: An identifier '%s' has not been declared\n", var_name);
            exit(1);
        } else if (entry->type == FORMAL) {
            // Trying to assign a value to a formal parameter, report an error
            printf("Error: cannot assign value to formal parameter '%s'\n", var_name);
            exit(1);
        }
         else {
            // Variable is defined in symbol table, update its value
            // entry->name = evaluate_expression(obj->right, symtab); // assuming evaluate_expression evaluates the expression on the right-hand side
            if(obj->value->type == AST_ASSIGNMENT) {
                visit_assignment(obj->value, visitor);
            }
            
            switch(entry->data_type) {
                case DATA_TYPE_INT:
                    printf("I am an integer");
                    break;
            }
        }
    } else {
        // Left-hand side is not a variable, report an error
        printf("Error: invalid assignment target\n");
        exit(1);
    }
}

float evaluate_non_string_expression(AST* obj, SYMBOL_TABLE* symtab) {
    switch(obj->type) {
        case AST_INT:
            return obj->int_value;
        case AST_FLOAT:
            return obj->float_value;
    }
}

float eval_arithmetic_expr(AST* obj, SYMBOL_TABLE* symtab) {
    
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

void visit_if_else_statement(AST* ast, Visitor* visitor) {
    // Evaluate the condition
    AST* condition = ast->children[0];
    visit(condition, visitor);
    
    // Assuming the condition is of type AST_BOOLEAN and its value is stored in the `boolean_value` field
    if (strcmp(condition->boolean_value, "true") == 0) {
        // If the condition is true, visit the if branch
        AST* if_branch = ast->children[1];
        visit(if_branch, visitor);
    } else if (ast->children_size == 3) {
        // If the condition is false and there's an else branch, visit the else branch
        AST* else_branch = ast->children[2];
        visit(else_branch, visitor);
    }
}

