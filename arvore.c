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
        printf("%s", " \%>\% ");
        break;
      case NODE_BASH_PIPE:
        printf("%s", " \%|\% ");
        break;
   }
}

void shift_or_assignment(ast_node* node, char* op) {
   if (node == NULL) return;
   descompila_internal(node->child[0]); // identifier
   descompila_internal(node->child[1]); // optional property access
   descompila_internal(node->child[2]); // optional vector access
   printf("%s", op);
   descompila_internal(node->child[3]); // rhs
}


void descompila_internal(ast_node* node) {
   int i = 0;
   if (node == NULL) {
      return;
   }
   switch(node->type) {

      case NODE_PROGRAM:
        descompila_internal(node->child[0]);
        descompila_internal(node->child[1]);
        break;

      case NODE_COMMAND_LIST_COMA_SEPARATED:
        descompila_internal(node->child[0]);
        if (node->child[1] != NULL && node->child[1]->type == NODE_COMMAND_LIST_COMA_SEPARATED)
           printf(",");
        descompila_internal(node->child[1]);
        break;

      case NODE_COMMAND_LIST:
        descompila_internal(node->child[0]);
        printf(";\n");
        descompila_internal(node->child[1]);
        break;

      case NODE_VAR_ACCESS:
        descompila_internal(node->child[0]);
        descompila_internal(node->child[1]);
        descompila_internal(node->child[2]);
        break;

      case NODE_ASSIGNMENT_2:
        descompila_internal(node->child[0]); // lhs
        printf(" = ");
        descompila_internal(node->child[1]); // rhs
        break;

      case NODE_BRACKET_EXPR:
        printf("(");
        descompila_internal(node->child[0]); // lhs
        printf(")");
        break;


      case NODE_SHIFT_LEFT:
        shift_or_assignment(node, " << ");
        break;

      case NODE_SHIFT_RIGHT:
        shift_or_assignment(node, " >> ");
        break;

      case NODE_SHIFT_LEFT_SPECIAL:
        shift_or_assignment(node, " << ");
        break;

      case NODE_SHIFT_RIGHT_SPECIAL:
        shift_or_assignment(node, " >> ");
        break;

      case NODE_ASSIGNMENT:
        shift_or_assignment(node, " = ");
        break;

      case NODE_CONST:
        printf("const ");
        break;

      case NODE_LOCAL_VAR:
        descompila_internal(node->child[3]); // Static or empty
        printf(" ");
        descompila_internal(node->child[2]); // Const or empty
        printf(" ");
        descompila_internal(node->child[1]); // Type
        printf(" ");
        descompila_internal(node->child[0]); // Identifier
        
        if (node->child[4] != NULL && node->child[4]->type != NODE_EMPTY)
           printf(" <= ");
        descompila_internal(node->child[4]); // Init value
        break;

      case NODE_EXPRESSION_LIST:
        descompila_internal(node->child[0]);
        if (node->child[1] != NULL && node->child[1]->type == NODE_EXPRESSION_LIST)
           printf(", ");
        descompila_internal(node->child[1]);
        break;

      case NODE_INPUT:
        printf("input ");
        descompila_internal(node->child[0]);
        break;

      case NODE_OUTPUT:
        printf("output ");
        descompila_internal(node->child[0]);
        if (node->child[1] != NULL && node->child[1]->type == NODE_EXPRESSION_LIST)
           printf(", ");
        descompila_internal(node->child[1]);
        break;

      case NODE_VECTOR_ACCESS:
        printf("[");
        descompila_internal(node->child[0]);
        printf("]");
        break;

      case NODE_PROPERTY_ACCESS:
        printf("$%s", node->string_literal);
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

      case NODE_NEW_TYPE:
	descompila_internal(node->child[0]);
        printf(" ");
	descompila_internal(node->child[1]);
	printf(" ");
	printf("[");
	descompila_internal(node->child[2]);
	descompila_internal(node->child[3]);
	printf("]");
	printf(";");
	printf("\n");
        break;

     case NODE_NEW_TYPE_PROPERTY_LIST:
	printf(":");
	descompila_internal(node->child[0]);
        printf(" ");
	descompila_internal(node->child[1]);
	break;

     case NODE_NEW_TYPE_PROPERTY:
	printf(" ");
	descompila_internal(node->child[0]);
        printf(" ");
	descompila_internal(node->child[1]);
	printf(" ");
	descompila_internal(node->child[2]);
	printf(" ");
	break;

     case NODE_CLASS:
        printf("class");
        break;

     case NODE_PUBLIC:
        printf("public");
        break;
     case NODE_PRIVATE:
        printf("private");
        break;
     case NODE_PROTECTED:
        printf("protected");
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
        printf("\'%c\'", node->char_literal);
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
      case NODE_LESS:
      case NODE_GREATER:
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

      case NODE_FOR:
        printf("for (");
        descompila_internal(node->child[0]); // first init command
        if (node->child[1] != NULL && node->child[1]->type == NODE_COMMAND_LIST_COMA_SEPARATED)
          printf(",");
        descompila_internal(node->child[1]); // init command list
        printf(" : ");
        descompila_internal(node->child[2]); // conditional
        printf(" : ");
        descompila_internal(node->child[3]); // first exec command
        if (node->child[4] != NULL && node->child[4]->type == NODE_COMMAND_LIST_COMA_SEPARATED)
          printf(",");
        descompila_internal(node->child[4]); // exec command list
        printf(")");
        descompila_internal(node->child[5]); // body
        break;

      case NODE_FOREACH:
        printf("foreach (");
        descompila_internal(node->child[0]); // identifier
        printf(" : ");
        descompila_internal(node->child[1]); // first expression
        if (node->child[2] != NULL && node->child[2]->type == NODE_EXPRESSION_LIST)
           printf(", ");
        descompila_internal(node->child[2]); // expression list
        printf(")\n");
        descompila_internal(node->child[3]); // command block
        break;

      case NODE_IF:
        printf("\nif (");
        descompila_internal(node->child[0]); // expression
        printf(") then");
        descompila_internal(node->child[1]); // then block
        descompila_internal(node->child[2]); // optional else 
        printf("\n");
        break;

      case NODE_SWITCH:
        printf("switch (");
        descompila_internal(node->child[0]); // value
        printf(")");
        descompila_internal(node->child[1]); // command block
        printf("\n");
        break;

      case NODE_CASE:
        printf("case %d:", node->int_literal);
        descompila_internal(node->child[0]); // value
        break;

      case NODE_ELSE:
        printf(" else ");
        descompila_internal(node->child[0]); // command block
        break;

      case NODE_WHILE:
        printf("while (");
        descompila_internal(node->child[0]); // conditional
        printf(") do ");
        descompila_internal(node->child[1]); // command block
        printf("\n");
        break;

      case NODE_DO_WHILE:
        printf("do");
        descompila_internal(node->child[0]); // command block
        printf(" while(");
        descompila_internal(node->child[1]); // conditional
        printf(")");
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

      case NODE_FUNCTION_BODY:
        printf(" {\n");
        descompila_internal(node->child[0]);
        descompila_internal(node->child[1]);
        printf("}");
        break;

      case NODE_ARGUMENT_PLACEHOLDER:
        printf(".");
        break;

      case NODE_IDENTIFIER:
        printf("%s", node->string_literal);
        break;

      case NODE_FUNCTION_CALL:
        descompila_internal(node->child[0]); // identifier
        printf("(");
        descompila_internal(node->child[1]); // arguments
        printf(")");
        descompila_internal(node->child[2]); // optional pipe
        break;

      case NODE_PIPE_COMMAND:
        descompila_internal(node->child[0]); // pipe
        descompila_internal(node->child[1]); // function
	break;

      case NODE_ARGUMENT:
        descompila_internal(node->child[0]); // const or empty
        if (node->child[0] != NULL && node->child[0]->type == NODE_STATIC) {
           printf(" ");
        }
        descompila_internal(node->child[1]); // static or empty
        if (node->child[1] != NULL && node->child[1]->type == NODE_STATIC) {
           printf(" ");
        }
        descompila_internal(node->child[2]); // type
        printf(" ");
        descompila_internal(node->child[3]); // identifier
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

      case NODE_BREAK:
        printf("break");
        break;

      case NODE_CONTINUE:
        printf("continue");
        break;

      case NODE_RETURN:
        printf("return ");
        descompila_internal(node->child[0]); // expression
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

void printree(ast_node* node, int lvl, int child){
	int i;
   if ( node == NULL) {
		return;
   }
   for(int j = 0; j < lvl; j++){
		printf(" ");
	}
   printf("Child: %d, Type: %d", child, node->type);
   if (node->type == NODE_IDENTIFIER) 
		printf(", %s", node->string_literal);
   
	printf("\n");
   for (i = 0; i < MAX_CHILD_NODES; i++) {
      if (node->child[i] != NULL) {
			printree(node->child[i], lvl+1, i);
      }
   }	
}

void descompila(void *arvore) {
   descompila_internal((ast_node*)arvore);
}


void libera(void *arvore) {
   libera_internal((ast_node*)arvore);
}
