/*
Função principal
*/
#include <stdio.h>
#include "arvore.h"
#include "parser.tab.h" //arquivo gerado com bison -d parser.y

void *arvore = NULL;
void descompila (void *arvore);
void libera (void *arvore);

int main (int argc, char **argv)
{
  int ret = yyparse();
  //descompila(arvore);
  printree(arvore, 0, 0);
  libera(arvore);
  yylex_destroy();
  return ret;
}
