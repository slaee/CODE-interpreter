#ifndef _VISITOR_H_
#define _VISITOR_H_

#include "../parser/ast.h"

typedef struct Visitor {
    AST* object;
} Visitor;

int type_check(int type);
Visitor* init_visitor();
void visit(AST* ast, Visitor* visitor);

void visit_compound(AST* ast, Visitor* visitor);
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

#endif