#include <stdio.h>
#include <stdlib.h>

#define MAX_CHILD_NODES 1024


#define NODE_INT_LITERAL    0
#define NODE_FLOAT_LITERAL  1
#define NODE_STRING_LITERAL 2
#define NODE_CHAR_LITERAL   3
#define NODE_BOOL_LITERAL   4


#define NODE_LE             8   // '<='
#define NODE_GE             9   // '>='
#define NODE_EQ             10  // '=='
#define NODE_NE             11  // '!='
#define NODE_AND            12  // '&&'
#define NODE_OR             13  // '||'
#define NODE_SR             14  // '>>'
#define NODE_SL             15  // '<<'
#define NODE_FORWARD_PIPE   16  // '%>%'
#define NODE_BASH_PIPE      17  // '%|%'


#define NODE_ADD            18  // '+;
#define NODE_SUB            19  // '-'
#define NODE_MUL            20  // '*'
#define NODE_DIV            21  // '/'


#define NODE_POSITIVE       22  // '+'
#define NODE_MINUS          23  // '-'
#define NODE_NOT            24  // '!'
#define NODE_DEREF_POINTER  25  // '&'
#define NODE_DEREF_VALUE    26  // '*'
#define NODE_ACCESS         27  // '#'
#define NODE_BOOL_EVAL      28  // '?'

#define NODE_MOD            29  // '%'
#define NODE_BITWISE_OR     30  // '|'
#define NODE_BITWISE_AND    31  // '&'
#define NODE_EXP            32  // '^'


#define NODE_IF             40
#define NODE_ELSE           41
#define NODE_TERNARY        42


#define NODE_COMMAND_BLOCK  43


typedef struct ast_node {

   // Type, one of the #defines
   int type;
   union {
      int   int_literal;    // Valid when type == NODE_INT_LITERAL
      float float_literal;  // Valid when type == NODE_FLOAT_LITERAL
      char* string_literal; // Valid when type == NODE_STRING_LITERAL
      char  char_literal;   // Valid when type == NODE_CHAR_LITERAL
      int   bool_literal;   // Valid when type == NODE_BOOL_LITERAL
   };

   // Children
   struct ast_node* child[MAX_CHILD_NODES];
} ast_node;


ast_node* make_node(int type);

void descompila_internal_unary_expression(ast_node* node);

void descompila_internal_binary_expression(ast_node* node);

void descompila_internal(ast_node* node);

void libera_internal(ast_node* node);

void descompila(void *arvore);

void libera(void *arvore);
