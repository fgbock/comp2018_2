#include <stdio.h>
#include <stdlib.h>

#define MAX_CHILD_NODES 1024


#define NODE_INT_LITERAL    0
#define NODE_FLOAT_LITERAL  1
#define NODE_STRING_LITERAL 2
#define NODE_CHAR_LITERAL   3
#define NODE_BOOL_LITERAL   4

#define NODE_ADD            5


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

void descompila_internal(ast_node* arvore) {
   if (arvore == NULL) {
      return;
   }
   if (arvore->type == NODE_ADD) {
      printf("(");
      descompila_internal(arvore->child[0]);
      printf("+");
      descompila_internal(arvore->child[1]);
      printf(")");
   }
   printf("descompila\n");
}

void descompila(void *arvore) {
   descompila_internal((ast_node*)arvore);
}


void libera(void *arvore) {
   printf("libera\n");
}
