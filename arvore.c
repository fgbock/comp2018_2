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


#define NODE_IF             30
#define NODE_ELSE           31
#define NODE_TERNARY        32


#define NODE_COMMAND_BLOCK  29


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


ast_node* make_node(int type) {
   ast_node* node = malloc(sizeof(node));
   for (int i = 0; i < MAX_CHILD_NODES; i++) {
      // Just in case
      node->child[i] = NULL;
   }
   node->type = type;
   return node;
}

void descompila_internal_unary_expression(ast_node* node)
{
   switch(node->type)
   {
      case NODE_POSITIVE:
        printf("+");
        break;
      case NODE_MINUS:
        printf("-");
        break;
      case NODE_NOT:
        printf("!");
        break;
      case NODE_DEREF_POINTER:
        printf("&");
        break;
      case NODE_DEREF_VALUE:
        printf("*");
        break;
      case NODE_ACCESS:
        printf("#");
        break;
      case NODE_BOOL_EVAL:
        printf("?");
        break;
   }
}

void descompila_internal_binary_expression(ast_node* node)
{
   switch(node->type)
   {
      case NODE_ADD:
        printf("+");
        break;
      case NODE_SUB:
        printf("-");
        break;
      case NODE_MUL:
        printf("*");
        break;
      case NODE_DIV:
        printf("/");
        break;
      case NODE_LE:
        printf("<=");
        break;
      case NODE_GE:
        printf(">=");
        break;
      case NODE_EQ:
        printf("==");
        break;
      case NODE_NE:
        printf("!=");
        break;
      case NODE_AND:
        printf("&&");
        break;
      case NODE_OR:
        printf("||");
        break;
      case NODE_SR:
        printf(">>");
        break;
      case NODE_SL:
        printf("<<");
        break;
      case NODE_FORWARD_PIPE:
        printf("\%>\%");
        break;
      case NODE_BASH_PIPE:
        printf("\%|\%");
        break;
   }
}


void descompila_internal(ast_node* node) {
   if (node == NULL) {
      return;
   }
   switch(node->type) {
      case NODE_INT_LITERAL:
        printf("%d", node->int_literal);
        break;

      case NODE_FLOAT_LITERAL:
        printf("%f", node->float_literal);
        break;

      case NODE_STRING_LITERAL:
        printf("\"%s\"", node->string_literal);
        break;

      case NODE_CHAR_LITERAL:
        printf("'%c'", node->char_literal);
        break;

      case NODE_BOOL_LITERAL:
        if (node->bool_literal)
           printf("true");
        else 
           printf("false");
        break;

      // Unary expressions
      case NODE_POSITIVE:
      case NODE_MINUS:
      case NODE_NOT:
      case NODE_DEREF_POINTER:
      case NODE_DEREF_VALUE:
      case NODE_ACCESS:
      case NODE_BOOL_EVAL:
        descompila_internal_unary_expression(node);
        descompila_internal(node->child[0]);
        break;
      
      // Binary expressions
      case NODE_ADD:
      case NODE_SUB:
      case NODE_MUL:
      case NODE_DIV:
      case NODE_LE:
      case NODE_GE:
      case NODE_EQ:
      case NODE_NE:
      case NODE_AND:
      case NODE_OR:
      case NODE_SR:
      case NODE_SL:
      case NODE_FORWARD_PIPE:
      case NODE_BASH_PIPE:
        descompila_internal(node->child[0]); 
        descompila_internal_binary_expression(node);
        descompila_internal(node->child[1]);
        break;

      case NODE_IF:
        printf("\nif (");
        descompila_internal(node->child[0]); // expression
        printf(") then");
        descompila_internal(node->child[1]); // then block
        descompila_internal(node->child[2]); // optional else
        break;

      case NODE_ELSE:
        printf("\nelse");
        descompila_internal(node->child[0]);
        break;

      case NODE_TERNARY:
        descompila_internal(node->child[0]);
        printf(" ? ");
        descompila_internal(node->child[1]);
        printf(" : ");
        descompila_internal(node->child[2]);
        break;

      case NODE_COMMAND_BLOCK:
        printf("\n{");
        descompila_internal(node->child[0]);
        printf("};");
        break;

   }

   printf("\n");
}

void libera_internal(ast_node* node) {
   for (int i = 0; i < MAX_CHILD_NODES; i++) {
      if (node->child[i] != NULL) {
         libera_internal(node->child[i]);
      } else {
         break;
      }
   }

   if (node->type == NODE_STRING_LITERAL) {
       free(node->string_literal);
   }
   free(node);
}

void descompila(void *arvore) {
   descompila_internal((ast_node*)arvore);
}


void libera(void *arvore) {
   libera_internal((ast_node*)arvore);
}
