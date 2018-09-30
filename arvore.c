#include "arvore.h"

ast_node* make_node(int type) {
   ast_node* node = malloc(sizeof(ast_node));
   for (int i = 0; i < MAX_CHILD_NODES; i++) {
      // Just in case
      node->child[i] = NULL;
   }
   node->type = type;
   return node;
}

void descompila_internal_unary_expression(ast_node* node)
{
   if (node == NULL) {
      return;
   }
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
   if (node == NULL) {
      return;
   }
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
      case NODE_GREATER:
        printf(">");
        break;
      case NODE_LESS:
        printf("<");
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
        printf("%s", "\%>\%");
        break;
      case NODE_BASH_PIPE:
        printf("%s", "\%|\%");
        break;
   }
}


void descompila_internal(ast_node* node) {
   int i = 0;
   if (node == NULL) {
      return;
   }
   //printf("type %d\n", node->type);
   switch(node->type) {

      case NODE_PROGRAM:
        descompila_internal(node->child[0]);
        descompila_internal(node->child[1]);
        break;

      case NODE_INT_TYPE:
        printf("int");
        break;
      case NODE_CHAR_TYPE:
        printf("char");
        break;
      case NODE_STRING_TYPE:
        printf("string");
        break;
      case NODE_BOOL_TYPE:
        printf("bool");
        break;
      case NODE_FLOAT_TYPE:
        printf("float");
        break;

      case NODE_STATIC:
        printf("static");
        break;

      case NODE_SIZE:
        printf("[%d]", node->int_literal);
        break;

      case NODE_VAR_GLOBAL:
        for (int i = 0; i < MAX_CHILD_NODES && node->child[i] != NULL; i++) {
           descompila_internal(node->child[i]);
           if (i + 1 < MAX_CHILD_NODES && node->child[i + 1] != NULL) {
              printf(" ");
           }
        }
        printf(";\n");
        break;

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
        printf("\n");
        break;

      case NODE_ELSE:
        printf("\nelse");
        descompila_internal(node->child[0]); // command block
        break;

      case NODE_TERNARY:
        descompila_internal(node->child[0]);
        printf(" ? ");
        descompila_internal(node->child[1]);
        printf(" : ");
        descompila_internal(node->child[2]);
        break;

      case NODE_COMMAND_BLOCK:
        printf(" {\n");
        descompila_internal(node->child[0]);
        descompila_internal(node->child[1]);
        printf("}");
        break;

      case NODE_IDENTIFIER:
        printf("%s", node->string_literal);
        break;

      case NODE_FUNCTION_CALL:
        descompila_internal(node->child[0]); // identifier
        descompila_internal(node->child[1]); // arguments
        break;

      case NODE_ARGUMENT:
        descompila_internal(node->child[0]); // static or empty
        if (node->child[0] != NULL && node->child[0]->type == NODE_STATIC) {
           printf(" ");
        }
        descompila_internal(node->child[1]); // type
        printf(" ");
        descompila_internal(node->child[2]); // identifier
        break;

      case NODE_ARGUMENT_LIST:
        descompila_internal(node->child[0]); // first argument (head)
        if (node->child[1] != NULL && node->child[1]->type == NODE_ARGUMENT_LIST) {
           printf(", ");
        }
        descompila_internal(node->child[1]); // next arguments (tail)
        break;

      case NODE_FUNCTION_DEFINITION:
        printf("\n");
        descompila_internal(node->child[0]); // static or empty
        if (node->child[0] != NULL && node->child[0]->type == NODE_STATIC) { 
           printf(" ");
        }
        descompila_internal(node->child[1]); // return type
        printf(" ");
        descompila_internal(node->child[2]); // identifier
        printf("(");
        descompila_internal(node->child[3]); // argument list
        printf(")");
        descompila_internal(node->child[4]); // body
        printf("\n");
        break;
   }
}

void libera_internal(ast_node* node) {
   if (node == NULL) {
      return;
   }
   for (int i = 0; i < MAX_CHILD_NODES; i++) {
      if (node->child[i] != NULL) {
         libera_internal(node->child[i]);
      }
   }

   if (node->type == NODE_STRING_LITERAL) {
       free(node->string_literal);
   }
   free(node);
}

void printree(ast_node* node, int lvl){
   int i;
   if ( node == NULL) {
	return;
   }
   for(int j = 0; j < lvl; j++){printf(" ");}
   printf("Type: %d\n", node->type);
   for (i = 0; i < MAX_CHILD_NODES; i++) {
      if (node->child[i] != NULL) {
	printree(node->child[i], lvl+1);
      }
   }	
}

void descompila(void *arvore) {
   printree((ast_node*)arvore, 0);
   descompila_internal((ast_node*)arvore);
}


void libera(void *arvore) {
   libera_internal((ast_node*)arvore);
}
