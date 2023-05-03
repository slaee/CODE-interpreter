#ifndef _VISITOR_H_
#define _VISITOR_H_

#include "../parser/ast.h"
#include "../parser/symtab.h"

typedef struct Visitor {
    AST* object;
} Visitor;

int type_check(int type);
Visitor* init_visitor();
void visit(AST* ast, Visitor* visitor);

// visitor for compound statements
void visit_compound(AST* ast, Visitor* visitor);

// visitor for declaration group of nodes
void visit_declarations(AST* ast, Visitor* visitor);
// visitor for executable group of nodes
void visit_executables(AST* ast, Visitor* visitor);

// visitor for group of variable declarations
void visit_variable_declarations(AST* ast, Visitor* visitor);
// visitor for group of function declarations
void visit_function_declarations(AST* ast, Visitor* visitor);

void visit_int(AST* obj, Visitor* visitor);
void visit_string(AST* obj, Visitor* visitor);
void visit_char(AST* obj, Visitor* visitor);
void visit_boolean(AST* obj, Visitor* visitor);
void visit_float(AST* obj, Visitor* visitor);
void visit_variable(AST* obj, Visitor* visitor);
void visit_assignment(AST* obj, Visitor* visitor);
void visit_concat_expression(AST* obj, Visitor* visitor);
void visit_arithmetic_expression(AST* obj, Visitor* visitor);
void visit_boolean_expression(AST* obj, Visitor* visitor);
void visit_unary_expression(AST* obj, Visitor* visitor);
void visit_paren_expression(AST* obj, Visitor* visitor);
void visit_function_call(AST* obj, Visitor* visitor);
void visit_if_else_statement(AST* obj, Visitor* visitor);
void visit_while_loop(AST* obj, Visitor* visitor);

float evaluate_non_string_expression(AST* obj, SYMBOL_TABLE* symtab);

#endif