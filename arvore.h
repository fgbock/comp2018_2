#ifndef ARVORE
#define ARVORE

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHILD_NODES 1024

#define NODE_INT_LITERAL    0
#define NODE_FLOAT_LITERAL  1
#define NODE_STRING_LITERAL 2
#define NODE_CHAR_LITERAL   3
#define NODE_BOOL_LITERAL   4


#define NODE_PROGRAM        5


#define NODE_GREATER        6   // '>'
#define NODE_LESS           7   // '<'
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


#define NODE_IF             40  // if (x) then { }
#define NODE_ELSE           41  // else { }
#define NODE_TERNARY        42  // .. ? .. : ..
#define NODE_WHILE          43  // while (x) do { }
#define NODE_DO_WHILE       44  // do { } while (x)
#define NODE_SWITCH         45  // switch (x) { }
#define NODE_CASE           46  // case (x): {}
#define NODE_FOR            47  // for(x) {}
#define NODE_FOREACH        48  // foreach


#define NODE_IDENTIFIER     50      // abc, aaa01
#define NODE_FUNCTION_CALL  51      // abc(x1, x2, x3, ...)
#define NODE_FUNCTION_DEFINITION 52 // abc(int x1, char x2, ...)
#define NODE_FUNCTION_HEADER 452

#define NODE_ARGUMENT             53 // (int x1)
#define NODE_ARGUMENT_LIST        54 // (int x1, char x2, ...)
#define NODE_ARGUMENT_PLACEHOLDER 55 // .
#define NODE_PIPE_COMMAND         56 // %>% ou %|%
#define NODE_EXPRESSION_LIST      57

#define NODE_COMMAND_LIST_COMA_SEPARATED 58
#define NODE_FUNCTION_BODY  59
#define NODE_COMMAND_LIST   60
#define NODE_COMMAND_BLOCK  61
#define NODE_VAR_GLOBAL     62


#define NODE_NEW_TYPE 63
#define NODE_CLASS 64

#define NODE_SIZE 65 // [10], [20]

#define NODE_ROOT 100
#define NODE_INT_TYPE 101
#define NODE_CHAR_TYPE 102
#define NODE_STRING_TYPE 103
#define NODE_BOOL_TYPE 104
#define NODE_FLOAT_TYPE 105

#define NODE_STATIC 106
#define NODE_CONST 107
#define NODE_PUBLIC 108
#define NODE_PRIVATE 109
#define NODE_PROTECTED 110

#define NODE_NEW_TYPE_PROPERTY 111
#define NODE_NEW_TYPE_PROPERTY_LIST 112


#define NODE_LOCAL_VAR        200
#define NODE_VAR_ACCESS       201
#define NODE_PROPERTY_ACCESS  203  // variavel$property
#define NODE_VECTOR_ACCESS    204  // variavel[x]


#define NODE_RETURN      301  // return x
#define NODE_BREAK       302  // break
#define NODE_CONTINUE    303  // continue
#define NODE_INPUT       304  // input x;
#define NODE_OUTPUT      305  // output x, y, z;
#define NODE_ASSIGNMENT  306  // x = y;
#define NODE_SHIFT_LEFT  307  // x << y;
#define NODE_SHIFT_RIGHT 308  // x >> y;
#define NODE_ASSIGNMENT_2 309 // Fix with variable access
#define NODE_SHIFT_LEFT_SPECIAL  310  // x << y;
#define NODE_SHIFT_RIGHT_SPECIAL 311 //
#define NODE_BRACKET_EXPR 312


#define NODE_EMPTY 666     // no value


#define NATUREZA_NULL               0
#define NATUREZA_LITERAL_INT        1
#define NATUREZA_LITERAL_FLOAT      2
#define NATUREZA_LITERAL_CHAR       3
#define NATUREZA_LITERAL_STRING     4
#define NATUREZA_LITERAL_BOOL       5
#define NATUREZA_IDENTIFICADOR      6

typedef struct ast_node {

   // Type, one of the #defines
   int type;

   int semantic_nature;
   union {
      int   int_literal;    // Valid when type == (NODE_INT_LITERAL | NODE_SIZE)
      float float_literal;  // Valid when type == NODE_FLOAT_LITERAL
      char* string_literal; // Valid when type == (NODE_STRING_LITERAL | NODE_IDENTIFIER | NODE_PROPERTY_ACCESS)
      char  char_literal;   // Valid when type == NODE_CHAR_LITERAL
      int   bool_literal;   // Valid when type == NODE_BOOL_LITERAL
   };

   // Children
   struct ast_node* child[MAX_CHILD_NODES];

   char* register_name;

   char* true_label;
   char* false_label;
} ast_node;


ast_node* make_node(int type);

void descompila_internal_unary_expression(ast_node* node);

void descompila_internal_binary_expression(ast_node* node);

void descompila_internal(ast_node* node);

void libera_internal(ast_node* node);

void printree(ast_node* node, int lvl, int child);

void descompila(void* arvore);

void libera(void* arvore);

#endif /* ARVORE */
