#ifndef SEMANTIC
#define SEMANTIC

#include <assert.h>
#include "arvore.h"
#include "semantic_error_codes.h"

#define ASSERT(X) if (!(X)) { printf("Assert Failed"); exit(-1); }

// Generic function to check and set semantic value of arithmetic nodes
void set_arithmetic_semantic(ast_node* node);

// Generic function to check and set semantic value of boolean nodes
void set_boolean_semantic(ast_node* node);

void set_function_call_semantic(ast_node* node);

void set_unary_number_semantic(ast_node* node);

// '!', '?'
void set_unary_bool_semantic(ast_node* node);

// '? :'
void set_ternary_expression_semantic(ast_node* node);


// if (x) then y else z
void set_if_semantic(ast_node* node);

// while (x) then
void set_while_semantic(ast_node* node);

// do x while y
void set_do_while_semantic(ast_node* node);

// for (x)
void set_for_semantic(ast_node* node);

// foreach (x)
void set_foreach_semantic(ast_node* node);

// switch (x) { ... }
void set_switch_semantic(ast_node* node);

// return x;
void set_return_nature(ast_node* node);

// break;
void set_break_nature(ast_node* node);

// continue;
void set_continue_nature(ast_node* node);

// case x:
void set_case_nature(ast_node* node);

// intput x, y
void set_input_semantic(ast_node* node);

// Aux

int can_cast_to_bool(int semantic_nature);

int can_cast_to_int(int semantic_nature);

void exit_with_cannot_cast_to_int_error(int semantic_nature);

void exit_with_cannot_cast_to_bool(int semantic_nature);


#endif
