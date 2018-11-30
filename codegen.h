#ifndef CODEGEN
#define CODEGEN

#include <stdarg.h>
#include "./arvore.h"
#include "./scope_stack.h"



extern t_scope_stack scope_stack;

void generate(ast_node* root);

// Private

void instruction(const char *format, ...);

void generate_return_op(ast_node* node);

void generate_code(ast_node* node);

void generate_bootstrap_code();

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

void generate_local_var_code(ast_node* node);

void generate_comment(char* comment);

void generate_function_call(ast_node* node);

void generate_function_definition(ast_node* node);

// Returns register with value
char* generate_variable_load_code(char* variable_identifier);

char* next_register();

char* next_label();

#endif
