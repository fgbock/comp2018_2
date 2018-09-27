#include <stdio.h>
#include <stdlib.h>

#define MAX_CHILD_NODES 1024


#define NODE_INT_LITERAL    0
#define NODE_FLOAT_LITERAL  1
#define NODE_STRING_LITERAL 2
#define NODE_CHAR_LITERAL   3
#define NODE_BOOL_LITERAL   4

#define NODE_IF             6
#define NODE_ELSE           7

#define NODE_ADD            8

#define NODE_COMMAND_BLOCK  9


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
      case NODE_ADD: // TODO: Make generic for binary operations
        printf("(");
        descompila_internal(node->child[0]);
        printf("+");
        descompila_internal(node->child[1]);
        printf(")");
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
      case NODE_COMMAND_BLOCK:
        printf("\n{");
        descompila_internal(node->child[0]);
        printf("}");
      break;
   }

   printf("descompila\n");
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
