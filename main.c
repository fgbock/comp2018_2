/*
Função principal
*/
#include <stdio.h>
#include "arvore.h"
#include "scope_stack.h"
#include "parser.tab.h" //arquivo gerado com bison -d parser.y
#include "codegen.h"

void *arvore = NULL;
void descompila (void *arvore);
void libera (void *arvore);

t_scope_stack scope_stack;

int main (int argc, char **argv)
{
  scope_stack_push_scope(&scope_stack);
  int ret = yyparse();
  //descompila(arvore);
  printree(arvore, 0, 0);
  printf("Generating code:\n");
  generate_code((ast_node*)arvore);
  libera(arvore);
  yylex_destroy();
  return ret;
}
