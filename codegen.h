#ifndef CODEGEN
#define CODEGEN

#include "./arvore.h"
#include "./scope_stack.h"

extern t_scope_stack scope_stack; 

void generate_code(ast_node* node);

// Private

void generate_binary_op(ast_node* node, char* instruction_code);

void generate_relational_op(ast_node* node, char* instruction_code);

void generate_var_access(ast_node* node);

void generate_if_code(ast_node* node);

void generate_while_code(ast_node* node);

void generate_do_while_code(ast_node* node);

void generate_and_code(ast_node* node);

void generate_or_code(ast_node* node);

void generate_boolean_literal_code(ast_node* node);

void generate_assignment_code(ast_node* node);

void generate_comment(char* comment);

char* next_register();

char* next_label();

#endif
